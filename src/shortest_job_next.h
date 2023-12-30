#ifndef SHORTEST_JOB_NEXT_H
#define SHORTEST_JOB_NEXT_H

#include "cpu_scheduler.h"
#include "process.h"
#include <vector>

class ShortestJobNext : public CPUScheduler {
private:
  static const std::string m_Name;
  std::vector<Process> m_ReadyQueue;

public:
  const std::string &getName() const override { return m_Name; }
  void scheduleProcess(Process proc) override;
  void exec() override;
};

#endif