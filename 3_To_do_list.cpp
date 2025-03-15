#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
    string description;
    bool completed;
    int priority;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    cout << "Enter priority (1-High, 2-Medium, 3-Low): ";
    cin >> newTask.priority;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) { return a.priority < b.priority; });
    
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[Done] " : "[Pending] ")
             << tasks[i].description << " (Priority: " << tasks[i].priority << ")" << endl;
    }
}

void markComplete() {
    int index;
    viewTasks();
    cout << "Enter task number to mark as complete: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as complete!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void removeTask() {
    int index;
    viewTasks();
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nTo-Do List Menu:";
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Complete\n4. Remove Task\n5. Exit\nChoose an option: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markComplete(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting the To-Do List application.\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}