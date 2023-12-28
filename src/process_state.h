#ifndef PROCESS_STATE_H
#define PROCESS_STATE_H

// Provides info about state of a process added to a CPU scheduling algorithm
class ProcessState {
public:
  int m_Pid;
  int m_WaitingTime = 0;
  int m_TurnaroundTime = 0;
  int m_CPUTime = 0;

  ProcessState(int pid);
};

#endif
