#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> tasks;

void show_tasks() {
    if (!tasks.empty()) {
        std::cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << '\n';
        }
    } else {
        std::cout << "Your to-do list is empty.\n";
    }
}

void add_task(const std::string& task) {
    tasks.push_back(task);
    std::cout << "Task added successfully.\n";
}

void remove_task(int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        std::string removed_task = tasks[index - 1];
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task '" << removed_task << "' removed.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

int main() {
    while (true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Show tasks\n";
        std::cout << "2. Add task\n";
        std::cout << "3. Remove task\n";
        std::cout << "4. Exit\n";

        int choice;
        std::string input;
        std::getline(std::cin, input);
        std::stringstream stream(input);
        stream >> choice;

        switch (choice) {
            case 1:
                show_tasks();
                break;
            case 2: {
                std::string task;
                std::cout << "Enter the task: ";
                std::getline(std::cin, task);
                add_task(task);
                break;
            }
            case 3: {
                int index;
                std::cout << "Enter the task index to remove: ";
                std::getline(std::cin, input);
                std::stringstream stream(input);
                stream >> index;
                remove_task(index);
                break;
            }
            case 4:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0;
}
