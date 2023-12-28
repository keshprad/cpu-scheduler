#ifndef FIRST_COME_FIRST_SERVE_H
#define FIRST_COME_FIRST_SERVE_H

#include "cpu_scheduler.h"
#include "process.h"
#include <vector>

class FirstComeFirstServe : public CPUScheduler {
private:
  std::vector<Process> m_ReadyQueue;

public:
  void scheduleProcess(Process proc) override;
  void exec() override;
};

#endif