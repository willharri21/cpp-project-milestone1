#ifndef TASK_H
#define TASK_H

#include <string>

// Represents a single task in our task manager
struct Task {
    int id;
    std::string description;
    bool isComplete;
};

#endif
