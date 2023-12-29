#ifndef SHORTEST_JOB_NEXT_H
#define SHORTEST_JOB_NEXT_H

#include "cpu_scheduler.h"
#include "process.h"
#include <vector>

class ShortestJobNext : public CPUScheduler {
private:
  std::vector<Process> m_ReadyQueue;

public:
  void scheduleProcess(Process proc) override;
  void exec() override;
};

#endif