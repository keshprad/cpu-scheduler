#include "process_state.h"
#include <ostream>

ProcessState::ProcessState() {}
ProcessState::ProcessState(int pid, int arrival_time)
    : m_Pid(pid),
      // initialize last timestamp executed on CPU to the arrival time
      m_LastCpuTime(arrival_time) {}

std::ostream &operator<<(std::ostream &os, const ProcessState &obj) {
  os << "ProcessState: {\n"
     << "\tpid: " << obj.m_Pid << ",\n"
     << "\tlast_cpu_time: " << obj.m_LastCpuTime << ",\n"
     << "\ttotal_cpu_time: " << obj.m_TotalCpuTime << ",\n"
     << "\tturnaround_time: " << obj.m_TurnaroundTime << ",\n"
     << "\twaiting_time: " << obj.m_WaitingTime << ",\n"
     << '}';
  return os;
}