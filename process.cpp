#include "process.h"
#include <iostream>
#include <string>

Process::Process(std::string name, int arrival_time, int burst_time,
                 int priority)
    : m_Name(name), m_ArrivalTime(arrival_time), m_BurstTime(burst_time),
      m_Priority(priority) {}

// Define an overload for the << operator
std::ostream &operator<<(std::ostream &os, const Process &obj) {
  os << "{\n"
     << "\tname: \"" << obj.m_Name << "\",\n"
     << "\tarrival_time: " << obj.m_ArrivalTime << ",\n"
     << "\tburst_time: " << obj.m_BurstTime << ",\n"
     << "\tpriority: " << obj.m_Priority << ",\n"
     << '}';
  return os;
}