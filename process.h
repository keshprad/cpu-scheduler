#ifndef PROCESS_H
#define PROCESS_H

#include "process_slice.h"
#include <vector>

class Process {
private:
  int m_Id;
  int m_Priority;
  std::vector<ProcessSlice> m_Slices;

public:
  Process(int id, int priority, std::vector<ProcessSlice> &&slices);
  Process(int id, int priority, std::vector<ProcessSlice> &slices);

  int getId() const { return m_Id; }
  int getPriority() const { return m_Priority; }
  const std::vector<ProcessSlice> &getSlices() const { return m_Slices; }
};

#endif