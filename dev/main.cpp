#include <iostream>
#include <string>
#include "TaskManager.h"

int main() {
    TaskManager manager;
    int choice = 0;

    std::cout << "=== C++ Task Manager ===\n";

    while (choice != 3) {
        std::cout << "\n1. Add a task\n";
        std::cout << "2. List tasks\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // clear the newline left in the input buffer

        if (choice == 1) {
            std::string description;
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            manager.addTask(description);
        } else if (choice == 2) {
            manager.listTasks();
        } else if (choice != 3) {
            std::cout << "Invalid option, try again.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
