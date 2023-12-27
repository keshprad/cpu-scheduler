#ifndef CPU_SCHEDULER_H
#define CPU_SCHEDULER_H

#include "event.h"
#include "process.h"
#include <vector>

// Abstract class for CPU schedulers
class CPUScheduler {
private:
  std::string m_Name;

protected:
  std::vector<Process> m_Procs;
  std::vector<Event> m_Events;

public:
  const std::string &getName() const { return m_Name; }
  const std::vector<Process> &getProcs() const { return m_Procs; }
  const std::vector<Event> &getEvents() { return m_Events; }

  // add process to the CPUScheduler
  virtual void addProcess(Process proc) = 0;
  // execute all processes added to the CPUScheduler
  virtual void exec() = 0;
};

#endif