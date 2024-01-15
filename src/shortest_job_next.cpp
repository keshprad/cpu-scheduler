#include "shortest_job_next.h"
#include "process.h"
#include <algorithm>

const std::string ShortestJobNext::m_Name = "ShortestJobNext";

// tell if scheduler has awaiting processes
bool ShortestJobNext::hasAwaitingProcesses() const {
  return !m_ReadyQueue.empty();
};

// adds process to necessary datastructures to schedule process
void ShortestJobNext::scheduleProcess(Process proc) {
  // add to ready queue
  // Use lower_bound with a lamdba to find insertion index
  auto insertionIndex =
      std::lower_bound(m_ReadyQueue.begin(), m_ReadyQueue.end(), proc,
                       Process::burstTimeComparator);
  // Insert the new element at the found position
  m_ReadyQueue.insert(insertionIndex, proc);
}

// execute all processes added to the scheduler
void ShortestJobNext::exec() {
  while (hasAwaitingProcesses()) {
    // atomic section: use lock to execute each process
    std::lock_guard<std::mutex> lockGuard(scheduler_lock);

    // pop element from front
    auto proc = m_ReadyQueue[0];
    m_ReadyQueue.erase(m_ReadyQueue.begin());

    // calculate start time for current proc: either the prev event end time or
    // curr proc arrival time
    double start_time = std::max(
        m_Events.empty() ? 0 : m_Events[m_Events.size() - 1].getEndTime(),
        proc.getArrivalTime());
    // calculate end time
    double end_time = start_time + proc.getBurstTime();

    // create and push event
    Event e(proc.getPid(), start_time, end_time);
    m_Events.push_back(e);

    // update process state
    ProcessState &ps = m_ProcessStates[proc.getPid()];
    ps.m_TotalCpuTime += end_time - start_time;
    ps.m_WaitingTime += start_time - ps.m_LastCpuTime;
    ps.m_TurnaroundTime = end_time - proc.getArrivalTime();
    ps.m_LastCpuTime = end_time;
  }
}