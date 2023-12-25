#include "process_slice.h"
#include <iostream>
#include <utility>
#include <vector>

ProcessSlice::ProcessSlice(int burst_time,
                           std::vector<int> &&acquired_resources,
                           std::vector<int> &&released_resources)
    : m_BurstTime(burst_time),
      m_AcquiredResources(std::move(acquired_resources)),
      m_ReleasedResources(std::move(released_resources)) {
  // TODO: REMOVE
  std::cout << "process slice made with rval ref acq/rel" << std::endl;
}

ProcessSlice::ProcessSlice(int burst_time, std::vector<int> &acquired_resources,
                           std::vector<int> &released_resources)
    : m_BurstTime(burst_time), m_AcquiredResources(acquired_resources),
      m_ReleasedResources(released_resources) {
  // TODO: REMOVE
  std::cout << "process slice made lval ref acq/rel" << std::endl;
}