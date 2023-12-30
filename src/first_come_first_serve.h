#ifndef FIRST_COME_FIRST_SERVE_H
#define FIRST_COME_FIRST_SERVE_H

#include "cpu_scheduler.h"
#include "process.h"
#include <vector>

class FirstComeFirstServe : public CPUScheduler {
private:
  static const std::string m_Name;
  std::vector<Process> m_ReadyQueue;

public:
  const std::string &getName() const override { return m_Name; }
  void scheduleProcess(Process proc) override;
  void exec() override;
};

#endif