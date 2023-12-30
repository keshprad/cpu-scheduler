#include "process.h"
#include <ostream>
#include <string>

Process::Process(int pid, double arrival_time, double burst_time, int priority)
    : m_Pid(pid), m_ArrivalTime(arrival_time), m_BurstTime(burst_time),
      m_Priority(priority) {}

// lower_than comparator for arrival time
bool Process::arrivalTimeComparator(const Process &a, const Process &b) {
  return a.getArrivalTime() < b.getArrivalTime();
}

// lower_than comparator for burst time
bool Process::burstTimeComparator(const Process &a, const Process &b) {
  return a.getBurstTime() < b.getBurstTime();
}

// lower_than comparator for priority time
bool Process::priorityComparator(const Process &a, const Process &b) {
  return a.getPriority() < b.getPriority();
}

// Define an overload for the << operator
std::ostream &operator<<(std::ostream &os, const Process &obj) {
  // push member variables to output stream
  os << "Process: {\n"
     << "\tpid: " << obj.m_Pid << ",\n"
     << "\tarrival_time: " << obj.m_ArrivalTime << ",\n"
     << "\tburst_time: " << obj.m_BurstTime << ",\n"
     << "\tpriority: " << obj.m_Priority << ",\n"
     << '}';
  return os;
}