#include "first_come_first_serve.h"
#include "process.h"
#include "round_robin.h"
#include "shortest_job_next.h"
#include <thread>

#include <iostream>
#include <vector>

void AddProcesses(CPUScheduler *sched) {}

int main() {
  Process p(1, 1, 10, 1);
  Process p2(2, 6, 2, 3);
  Process p3(3, 6, 3, 2);
  Process p4(4, 4, 9, 1);
  Process p5(5, 5, 1.2, 5);
  Process p6(6, 0, 12, 4);

  FirstComeFirstServe fcfs = FirstComeFirstServe();
  ShortestJobNext sjn = ShortestJobNext();
  RoundRobin rr = RoundRobin();
  std::vector<CPUScheduler *> cpuSchedulers = {&fcfs, &sjn, &rr};
  for (auto sched : cpuSchedulers) {
    std::cout << sched->getName() << std::endl;
    sched->addProcess(p);
    // sched->addProcess(p);
    sched->addProcess(p2);
    sched->addProcess(p3);
    sched->addProcess(p4);
    sched->addProcess(p5);
    sched->addProcess(p6);

    sched->exec();

    std::cout << "average turnaround time: "
              << sched->getAverageTurnaroundTime() << std::endl;
    std::cout << "average waiting time: " << sched->getAverageWaitingTime()
              << std::endl;
    std::cout << std::endl;
  }

  return 0;
}