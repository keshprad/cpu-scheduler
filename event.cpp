#include "event.h"
#include <iostream>
#include <string>

Event::Event(std::string process_name, int start_time, int end_time)
    : m_ProcessName(process_name), m_StartTime(start_time),
      m_EndTime(end_time) {}

// Define an overload for the << operator
std::ostream &operator<<(std::ostream &os, const Event &obj) {
  // push member variables to output stream
  os << "{\n"
     << "\tprocess_name: \"" << obj.m_ProcessName << "\",\n"
     << "\tstart_time: " << obj.m_StartTime << ",\n"
     << "\tend_time: " << obj.m_EndTime << ",\n"
     << '}';
  return os;
}