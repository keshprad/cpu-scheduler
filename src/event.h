#ifndef EVENT_H
#define EVENT_H

#include <ostream>
#include <string>

class Event {
private:
  int m_ProcessPid;
  int m_StartTime;
  int m_EndTime;

public:
  Event(int process_pid, int start_time, int end_time);
  int getProcessPid() const { return m_ProcessPid; }
  int getStartTime() const { return m_StartTime; }
  int getEndTime() const { return m_EndTime; }

  friend std::ostream &operator<<(std::ostream &os, const Event &obj);
};

#endif
