#ifndef PROCESS_SLICE_H
#define PROCESS_SLICE_H

#include <vector>

class ProcessSlice {
private:
  int m_BurstTime;
  std::vector<int> m_AcquiredResources;
  std::vector<int> m_ReleasedResources;

public:
  ProcessSlice(int burst_time, std::vector<int> &&acquired_resources,
               std::vector<int> &&released_resources);
  ProcessSlice(int burst_time, std::vector<int> &acquired_resources,
               std::vector<int> &released_resources);

  int getBurstTime() { return m_BurstTime; }
  const std::vector<int> &getAcquiredResources() { return m_AcquiredResources; }
  const std::vector<int> &getReleasedResources() { return m_ReleasedResources; }
};

#endif