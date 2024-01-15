#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include "cpu_scheduler.h"
#include "process.h"
#include <functional>
#include <queue>
#include <vector>

class MinHeapProcessComparator {
public:
  bool operator()(Process &a, Process &b) {
    return !Process::priorityComparator(a, b);
  }
};

class RoundRobin : public CPUScheduler {
private:
  static const std::string m_Name;
  const double m_Quantum;

  std::priority_queue<Process, std::vector<Process>, MinHeapProcessComparator>
      m_ReadyMinHeap;

public:
  RoundRobin();
  RoundRobin(double quantum);

  const std::string &getName() const override { return m_Name; }
  bool hasAwaitingProcesses() const override;
  void scheduleProcess(Process proc) override;
  void exec() override;
};
#endif
