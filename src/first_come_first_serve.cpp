#include "first_come_first_serve.h"
#include <algorithm>

// FirstComeFirstServe::FirstComeFirstServe() {}

// adds process to necessary datastructures to schedule process
void FirstComeFirstServe::scheduleProcess(Process proc) {
  // add to ready queue
  // Use lower_bound with a lamdba to find insertion index
  auto insertionIndex =
      std::lower_bound(m_ReadyQueue.begin(), m_ReadyQueue.end(), proc,
                       [](const Process &a, const Process &b) {
                         return a.getArrivalTime() < b.getArrivalTime();
                       });
  // Insert the new element at the found position
  m_ReadyQueue.insert(insertionIndex, proc);
}

// execute all processes added to the scheduler
void FirstComeFirstServe::exec() {
  for (auto proc : m_ReadyQueue) {
    // start time for current proc: either the prev event end time or curr proc
    // arrival time
    int start_time = std::max(
        m_Events.empty() ? 0 : m_Events[m_Events.size() - 1].getEndTime(),
        proc.getArrivalTime());
    // calculate end time
    int end_time = start_time + proc.getBurstTime();

    // create and push event
    Event e(proc.getPid(), start_time, end_time);
    m_Events.push_back(e);
  }

  // clear ready queue
  m_ReadyQueue.clear();
}