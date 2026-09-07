#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>
#include "Task.h"

// Handles storing, adding, and listing tasks
class TaskManager {
public:
    void addTask(const std::string& description);
    void listTasks() const;

private:
    std::vector<Task> tasks;
};

#endif
