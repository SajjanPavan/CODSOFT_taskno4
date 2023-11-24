#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task>& taskList, const string& description);
void viewTasks(const vector<Task>& taskList);
void markAsCompleted(vector<Task>& taskList, int index);
void removeTask(vector<Task>& taskList, int index);

int main() {
    vector<Task> taskList;

    cout << "Simple To-Do List Manager" << endl;

    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addTask(taskList, description);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markAsCompleted(taskList, index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(taskList, index);
                break;
            }
            case 5:
                cout << "Exiting the to-do list manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}

// Function to add a task to the list
void addTask(vector<Task>& taskList, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    taskList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks found." << endl;
    } else {
        cout << "\nTask List:" << endl;
        cout << setw(5) << "Index" << setw(30) << "Description" << setw(15) << "Status" << endl;
        for (size_t i = 0; i < taskList.size(); ++i) {
            cout << setw(5) << i + 1 << setw(30) << taskList[i].description;
            if (taskList[i].completed) {
                cout << setw(15) << "Completed";
            } else {
                cout << setw(15) << "Pending";
            }
            cout << endl;
        }
    }
}

// Function to mark a task as completed
void markAsCompleted(vector<Task>& taskList, int index) {
    if (index >= 1 && static_cast<size_t>(index) <= taskList.size()) {
        taskList[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid index. Please enter a valid index." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& taskList, int index) {
    if (index >= 1 && static_cast<size_t>(index) <= taskList.size()) {
        taskList.erase(taskList.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid index. Please enter a valid index." << endl;
    }
}
