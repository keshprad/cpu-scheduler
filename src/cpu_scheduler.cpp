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
  m_ProcessStates[pid] = ProcessState(pid);
  // 3. schedule process
  scheduleProcess(proc);
}
