#include "process.h"
#include <iostream>
#include <string>

Process::Process(int pid, int arrival_time, int burst_time, int priority)
    : m_Pid(pid), m_ArrivalTime(arrival_time), m_BurstTime(burst_time),
      m_Priority(priority) {}

// Define an overload for the << operator
std::ostream &operator<<(std::ostream &os, const Process &obj) {
  // push member variables to output stream
  os << "{\n"
     << "\tpid: \"" << obj.m_Pid << "\",\n"
     << "\tarrival_time: " << obj.m_ArrivalTime << ",\n"
     << "\tburst_time: " << obj.m_BurstTime << ",\n"
     << "\tpriority: " << obj.m_Priority << ",\n"
     << '}';
  return os;
}