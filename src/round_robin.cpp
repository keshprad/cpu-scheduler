#include "round_robin.h"
#include <algorithm>

const std::string RoundRobin::m_Name = "RoundRobin";

RoundRobin::RoundRobin() : m_Quantum(1) {}
RoundRobin::RoundRobin(double quantum) : m_Quantum(quantum) {}

// tell if scheduler has awaiting processes
bool RoundRobin::hasAwaitingProcesses() const {
  return !m_ReadyMinHeap.empty();
};

// adds process to necessary datastructures to schedule process
void RoundRobin::scheduleProcess(Process proc) {
  // add to ready priority queue
  m_ReadyMinHeap.push(proc);
}

void RoundRobin::exec() {
  while (hasAwaitingProcesses()) {
    // atomic section: use lock to execute each process
    std::lock_guard<std::mutex> lockGuard(scheduler_lock);

    // get top element
    auto proc = m_ReadyMinHeap.top();
    // remove top element
    m_ReadyMinHeap.pop();

    // calculate start time for current proc: either the prev event end time or
    // curr proc arrival time
    double start_time = std::max(
        m_Events.empty() ? 0 : m_Events[m_Events.size() - 1].getEndTime(),
        proc.getArrivalTime());
    // find time executed thus far
    double cpuTime = m_ProcessStates[proc.getPid()].m_TotalCpuTime;
    // calculate end time
    // exec time is either quantum, or rest of time remaining to complete
    // process
    double end_time =
        start_time + std::min(m_Quantum, proc.getBurstTime() - cpuTime);

    // create and push event
    Event e(proc.getPid(), start_time, end_time);
    m_Events.push_back(e);

    // update process state
    ProcessState &ps = m_ProcessStates[proc.getPid()];
    ps.m_TotalCpuTime += end_time - start_time;
    ps.m_WaitingTime += start_time - ps.m_LastCpuTime;
    ps.m_TurnaroundTime = end_time - proc.getArrivalTime();
    ps.m_LastCpuTime = end_time;

    // check if proc needs to go back into heap
    // Define a small epsilon value for floating point comparison
    double epsilon = 1e-10;
    if (ps.m_TotalCpuTime < proc.getBurstTime() - epsilon) {
      scheduleProcess(proc);
    }
  }
}