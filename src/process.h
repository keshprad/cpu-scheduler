#ifndef PROCESS_H
#define PROCESS_H

#include <ostream>
#include <string>

// class for Process
class Process {
private:
  int m_Pid;
  int m_ArrivalTime;
  int m_BurstTime;
  int m_Priority;

public:
  Process(int pid, int arrival_time, int burst_time, int priority);

  int getPid() const { return m_Pid; }
  int getArrivalTime() const { return m_ArrivalTime; }
  int getBurstTime() const { return m_BurstTime; }
  int getPriority() const { return m_Priority; }

  friend std::ostream &operator<<(std::ostream &os, const Process &obj);
};

#endif