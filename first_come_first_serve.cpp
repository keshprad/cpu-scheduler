#include "first_come_first_serve.h"
#include "iostream"

// FirstComeFirstServe::FirstComeFirstServe() {}

// add process to process queues
void FirstComeFirstServe::addProcess(Process proc) {
  // 1. add to list of processes
  m_Procs.push_back(proc);

  // 2. add to ready queue
  // Use lower_bound with a lamdba to find insertion index
  auto insertionIndex =
      std::lower_bound(m_ReadyQueue.begin(), m_ReadyQueue.end(), proc,
                       [](const Process &a, const Process &b) {
                         return a.getArrivalTime() < b.getArrivalTime();
                       });
  // Insert the new element at the found position
  m_ReadyQueue.insert(insertionIndex, proc);
}