#ifndef CPU_SCHEDULER_H
#define CPU_SCHEDULER_H

#include "event.h"
#include "process.h"
#include "process_state.h"
#include <unordered_map>
#include <vector>

// Abstract class for CPU schedulers
class CPUScheduler {
protected:
  std::vector<Process> m_Procs;
  std::vector<Event> m_Events;
  std::unordered_map<int, ProcessState> m_ProcessStates;

public:
  virtual const std::string &getName() const = 0;
  const std::vector<Process> &getProcs() const { return m_Procs; }
  const std::vector<Event> &getEvents() const { return m_Events; }

  double getAverageTurnaroundTime() const;
  double getAverageWaitingTime() const;
  const ProcessState &getProcessState(int pid) const;

  // add process to the CPUScheduler
  void addProcess(Process proc);
  // adds process to necessary datastructures to schedule process
  virtual void scheduleProcess(Process proc) = 0;
  // execute all processes added to the CPUScheduler
  virtual void exec() = 0;
};

#endif