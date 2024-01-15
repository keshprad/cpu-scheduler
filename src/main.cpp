#include "first_come_first_serve.h"
#include "process.h"
#include "round_robin.h"
#include "shortest_job_next.h"
#include <thread>

#include <iostream>
#include <mutex>
#include <vector>

// std::condition_variable gConditionVariable;
bool processesAdded = false;

void AddProcesses(CPUScheduler *sched) {
  std::vector<Process> procs = {
      Process(6, 0, 12, 4),  Process(1, 1, 10, 1), Process(4, 4, 9, 1),
      Process(5, 5, 1.2, 5), Process(2, 6, 2, 3),  Process(3, 6, 3, 2),
  };

  // adding processes
  for (auto &proc : procs) {
    sched->addProcess(proc);
  }

  // Set to false. Trigger stop calling sched->exec
  processesAdded = true;
  // gConditionVariable.notify_one();
}

void ExecProcesses(CPUScheduler *sched) {
  int i = 0;

  while (!processesAdded || sched->hasAwaitingProcesses()) {
    // execute processes
    i += 1;
    sched->exec();
  }
  std::cout << "done " << std::endl;
  std::cout << i << std::endl;
}

void PrintSchedulerSummary(CPUScheduler *sched) {
  // Print out workload summary
  std::cout << sched->getName() << " summary" << std::endl;
  std::cout << "average turnaround time: " << sched->getAverageTurnaroundTime()
            << std::endl;
  std::cout << "average waiting time: " << sched->getAverageWaitingTime()
            << std::endl;
  std::cout << std::endl;
}

int main() {
  FirstComeFirstServe fcfs = FirstComeFirstServe();
  ShortestJobNext sjn = ShortestJobNext();
  RoundRobin rr = RoundRobin();
  std::vector<CPUScheduler *> cpuSchedulers = {&fcfs, &sjn, &rr};

  for (auto sched : cpuSchedulers) {
    // set indicator to false;
    processesAdded = false;
    std::thread add_procs_worker(AddProcesses, sched);
    std::thread exec_procs_worker(ExecProcesses, sched);

    add_procs_worker.join();
    exec_procs_worker.join();

    // Print out workload summary
    PrintSchedulerSummary(sched);
  }

  return 0;
}