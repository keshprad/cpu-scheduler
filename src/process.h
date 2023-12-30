#ifndef PROCESS_H
#define PROCESS_H

#include <ostream>
#include <string>

// class for Process
class Process {
private:
  int m_Pid;
  double m_ArrivalTime;
  double m_BurstTime;
  int m_Priority;

public:
  Process(int pid, double arrival_time, double burst_time, int priority);

  int getPid() const { return m_Pid; }
  double getArrivalTime() const { return m_ArrivalTime; }
  double getBurstTime() const { return m_BurstTime; }
  int getPriority() const { return m_Priority; }

  static bool arrivalTimeComparator(const Process &a, const Process &b);
  static bool burstTimeComparator(const Process &a, const Process &b);
  static bool priorityComparator(const Process &a, const Process &b);

  friend std::ostream &operator<<(std::ostream &os, const Process &obj);
};

#endif