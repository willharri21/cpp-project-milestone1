#include <iostream>
#include <string>
#include "TaskManager.h"

// Prompts for a menu choice and validates it's actually a number.
// Keeps asking until valid input is given, instead of crashing on bad input.
int getMenuChoice() {
    int choice;
    while (true) {
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // reset the error flag
            std::cin.ignore(10000, '\n'); // discard the bad input
            std::cout << "That's not a valid number. Please try again.\n";
            continue;
        }

        std::cin.ignore(); // clear leftover newline
        return choice;
    }
}

int main() {
    TaskManager manager;
    int choice = 0;

    std::cout << "=== C++ Task Manager ===\n";

    while (choice != 5) {
        std::cout << "\n1. Add a task\n";
        std::cout << "2. List tasks\n";
        std::cout << "3. Mark a task complete\n";
        std::cout << "4. Delete a task\n";
        std::cout << "5. Exit\n";

        choice = getMenuChoice();

        if (choice == 1) {
            std::string description;
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            manager.addTask(description);
        } else if (choice == 2) {
            manager.listTasks();
        } else if (choice == 3) {
            manager.listTasks();
            std::cout << "Enter the task ID to mark complete: ";
            int id = getMenuChoice();
            manager.markComplete(id);
        } else if (choice == 4) {
            manager.listTasks();
            std::cout << "Enter the task ID to delete: ";
            int id = getMenuChoice();
            manager.deleteTask(id);
        } else if (choice != 5) {
            std::cout << "Invalid option, try again.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
