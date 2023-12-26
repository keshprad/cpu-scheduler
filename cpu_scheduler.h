#ifndef CPU_SCHEDULER_H
#define CPU_SCHEDULER_H

#include "process.h"
#include <vector>

// Abstract class for CPU schedulers
class CPUScheduler {
private:
  std::string m_Name;
  // std::vector<Event> m_Events;

protected:
  std::vector<Process> m_Procs;

public:
  const std::string &getName() const { return m_Name; }
  const std::vector<Process> &getProcs() const { return m_Procs; }
  // const std::vector<Event> &getEvents() { return m_Events; }
  virtual void addProcess(Process proc) = 0;

  // virtual void exec() = 0;
};

#endif