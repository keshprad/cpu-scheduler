#include "cpu_scheduler.h"
#include "process_state.h"

void CPUScheduler::addProcess(Process proc) {
  int pid = proc.getPid();
  if (m_ProcessStates.contains(pid)) {
    throw std::runtime_error("Duplicate process PID");
  }

  // 1. add to list of processes
  m_Procs.push_back(proc);
  // 2. create process state
  m_ProcessStates[pid] = ProcessState(pid, proc.getArrivalTime());
  // 3. schedule process
  scheduleProcess(proc);
}

double CPUScheduler::getAverageTurnaroundTime() const {
  double total = 0;
  for (auto proc : m_Procs) {
    // use .at(key) to preserve const
    total += m_ProcessStates.at(proc.getPid()).m_TurnaroundTime;
  }
  return total / m_Procs.size();
}

double CPUScheduler::getAverageWaitingTime() const {
  double total = 0;
  for (auto proc : m_Procs) {
    // use .at(key) to preserve const
    total += m_ProcessStates.at(proc.getPid()).m_WaitingTime;
  }
  return total / m_Procs.size();
};

const ProcessState &CPUScheduler::getProcessState(int pid) const {
  return m_ProcessStates.at(pid);
}