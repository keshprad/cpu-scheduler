#include "event.h"
#include <iostream>
#include <string>

Event::Event(int process_pid, int start_time, int end_time)
    : m_ProcessPid(process_pid), m_StartTime(start_time), m_EndTime(end_time) {}

// Define an overload for the << operator
std::ostream &operator<<(std::ostream &os, const Event &obj) {
  // push member variables to output stream
  os << "{\n"
     << "\tprocess_pid: \"" << obj.m_ProcessPid << "\",\n"
     << "\tstart_time: " << obj.m_StartTime << ",\n"
     << "\tend_time: " << obj.m_EndTime << ",\n"
     << '}';
  return os;
}