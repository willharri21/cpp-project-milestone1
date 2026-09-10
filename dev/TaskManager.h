#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>
#include "Task.h"

// Handles storing, adding, listing, completing, and deleting tasks
class TaskManager {
public:
    void addTask(const std::string& description);
    void listTasks() const;
    bool markComplete(int id);
    bool deleteTask(int id);

private:
    std::vector<Task> tasks;
};

#endif
