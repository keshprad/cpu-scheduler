# cpu-scheduling

C++ implementation and benchmarking of cpu scheduling algorithms using an abstraction of processes.

## Abstraction details

Processes are represented as objects specified with their pid, arrival time, burst time, priority.

Process state (waiting time, turnaround time, total cpu time, last timestamp executed at) is tracked through the scheduling process and can be surfaced after `CPUScheduler::exec()`.

## Algorithms supported

- First Come First Serve
- Shortest Job Next
- Round Robin
  - Has a default quantum = 1
