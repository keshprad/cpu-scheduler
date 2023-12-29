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

double CPUScheduler::getAverageTurnaroundTime() {
  double total = 0;
  for (auto proc : m_Procs) {
    total += m_ProcessStates[proc.getPid()].m_TurnaroundTime;
  }
  return total / m_Procs.size();
}

double CPUScheduler::getAverageWaitingTime() {
  double total = 0;
  for (auto proc : m_Procs) {
    total += m_ProcessStates[proc.getPid()].m_WaitingTime;
  }
  return total / m_Procs.size();
};
