#ifndef EVENT_H
#define EVENT_H

#include <ostream>
#include <string>

class Event {
private:
  int m_ProcessPid;
  double m_StartTime;
  double m_EndTime;

public:
  Event(int process_pid, int start_time, int end_time);
  int getProcessPid() const { return m_ProcessPid; }
  double getStartTime() const { return m_StartTime; }
  double getEndTime() const { return m_EndTime; }

  friend std::ostream &operator<<(std::ostream &os, const Event &obj);
};

#endif
