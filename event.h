#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

class Event {
private:
  std::string m_ProcessName;
  int m_StartTime;
  int m_EndTime;

public:
  Event(std::string process_name, int start_time, int end_time);
  const std::string &getProcessName() const { return m_ProcessName; }
  int getStartTime() const { return m_StartTime; }
  int getEndTime() const { return m_EndTime; }

  friend std::ostream &operator<<(std::ostream &os, const Event &obj);
};

#endif
