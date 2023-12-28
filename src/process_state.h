#ifndef PROCESS_STATE_H
#define PROCESS_STATE_H

// Provides info about state of a process added to a CPU scheduling algorithm
class ProcessState {
private:
  int m_Pid;

public:
  int m_WaitingTime = 0;
  int m_TurnaroundTime = 0;
  int m_CPUTime = 0;

  ProcessState();
  ProcessState(int pid);
  int getPid() const { return m_Pid; }
};

#endif
