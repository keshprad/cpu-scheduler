#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
private:
  std::string m_Name;
  int m_ArrivalTime;
  int m_BurstTime;
  int m_Priority;

public:
  Process(std::string name, int arrival_time, int burst_time, int priority);

  const std::string &getName() const { return m_Name; }
  int getArrivalTime() const { return m_ArrivalTime; }
  int getBurstTime() const { return m_BurstTime; }
  int getPriority() const { return m_Priority; }

  friend std::ostream &operator<<(std::ostream &os, const Process &obj);
};

#endif