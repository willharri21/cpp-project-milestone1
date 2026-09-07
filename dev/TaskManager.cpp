#include <iostream>
#include "TaskManager.h"

// Adds a new task to the list
void TaskManager::addTask(const std::string& description) {
    Task newTask;
    newTask.id = static_cast<int>(tasks.size()) + 1;
    newTask.description = description;
    newTask.isComplete = false;

    tasks.push_back(newTask);
    std::cout << "Added: \"" << description << "\"\n";
}

// Prints all current tasks to the console
void TaskManager::listTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks yet. Add one!\n";
        return;
    }

    std::cout << "\n--- Your Tasks ---\n";
    for (const Task& t : tasks) {
        std::cout << "[" << (t.isComplete ? "x" : " ") << "] "
                   << t.id << ". " << t.description << "\n";
    }
    std::cout << "------------------\n";
}
