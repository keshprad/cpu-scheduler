#ifndef PROCESS_STATE_H
#define PROCESS_STATE_H

#include <ostream>

// Provides info about state of a process added to a CPU scheduling algorithm
class ProcessState {
private:
  int m_Pid;

public:
  // last timestamp process was executed on cpu.
  // initialized to process arrival time
  double m_LastCpuTime;
  // total time process has spent executing
  double m_TotalCpuTime = 0;
  // time between process arrival and completion
  double m_TurnaroundTime = 0;
  // total time process has spent waiting
  double m_WaitingTime = 0;

  ProcessState();
  ProcessState(int pid, double arrival_time);
  int getPid() const { return m_Pid; }

  friend std::ostream &operator<<(std::ostream &os, const ProcessState &obj);
};

#endif
