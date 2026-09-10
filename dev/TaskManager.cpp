#include <iostream>
#include <algorithm>
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

// Marks a task as complete by its id. Returns false if not found.
bool TaskManager::markComplete(int id) {
    for (Task& t : tasks) {
        if (t.id == id) {
            t.isComplete = true;
            std::cout << "Marked task " << id << " as complete.\n";
            return true;
        }
    }
    std::cout << "No task found with id " << id << ".\n";
    return false;
}

// Removes a task by its id. Returns false if not found.
bool TaskManager::deleteTask(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [id](const Task& t) { return t.id == id; });

    if (it == tasks.end()) {
        std::cout << "No task found with id " << id << ".\n";
        return false;
    }

    tasks.erase(it);
    std::cout << "Deleted task " << id << ".\n";
    return true;
}
