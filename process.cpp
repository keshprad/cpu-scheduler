#include "process.h"
#include "process_slice.h"
#include <iostream>
#include <utility>
#include <vector>

Process::Process(int id, int priority, std::vector<ProcessSlice> &&slices)
    : m_Id(id), m_Priority(priority), m_Slices(std::move(slices)) {}

Process::Process(int id, int priority, std::vector<ProcessSlice> &slices)
    : m_Id(id), m_Priority(priority), m_Slices(slices) {}