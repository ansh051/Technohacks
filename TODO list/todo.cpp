#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

// Function to add a new task to the to-do list
void addTask(std::vector<Task>& todoList) {
    std::string taskDescription;
    std::cout << "Enter the task description: ";
    std::cin.ignore(); // Ignore any remaining newline character
    std::getline(std::cin, taskDescription);

    Task newTask;
    newTask.description = taskDescription;
    newTask.completed = false;

    todoList.push_back(newTask);

    std::cout << "Task added successfully!\n";
}

// Function to view the to-do list
void viewTodoList(const std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "Your to-do list is empty.\n";
        return;
    }

    std::cout << "To-Do List:\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        const Task& task = todoList[i];
        std::cout << "[" << (task.completed ? "X" : " ") << "] " << task.description << std::endl;
    }
}

// Function to mark a task as completed
void markCompleted(std::vector<Task>& todoList) {
    int index;
    std::cout << "Enter the index of the task you want to mark as completed (starting from 0): ";
    std::cin >> index;

    if (index < 0 || index >= static_cast<int>(todoList.size())) {
        std::cout << "Invalid index. No task marked as completed.\n";
        return;
    }

    todoList[index].completed = true;
    std::cout << "Task marked as completed!\n";
}

// Function to delete a task from the to-do list
void deleteTask(std::vector<Task>& todoList) {
    int index;
    std::cout << "Enter the index of the task you want to delete (starting from 0): ";
    std::cin >> index;

    if (index < 0 || index >= static_cast<int>(todoList.size())) {
        std::cout << "Invalid index. No task deleted.\n";
        return;
    }

    todoList.erase(todoList.begin() + index);
    std::cout << "Task deleted successfully!\n";
}

int main() {
    std::vector<Task> todoList;

    while (true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View To-Do List\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(todoList);
                break;
            case 2:
                viewTodoList(todoList);
                break;
            case 3:
                markCompleted(todoList);
                break;
            case 4:
                deleteTask(todoList);
                break;
            case 5:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
