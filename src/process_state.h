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
  int m_LastCpuTime;
  // total time process has spent executing
  int m_TotalCpuTime = 0;
  // time between process arrival and completion
  int m_TurnaroundTime = 0;
  // total time process has spent waiting
  int m_WaitingTime = 0;

  ProcessState();
  ProcessState(int pid, int arrival_time);
  int getPid() const { return m_Pid; }

  friend std::ostream &operator<<(std::ostream &os, const ProcessState &obj);
};

#endif
