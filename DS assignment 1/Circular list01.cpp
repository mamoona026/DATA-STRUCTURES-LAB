#include <iostream>                 // For input/output
#include <string>                   // For string type
using namespace std;                // Use standard namespace

// Node for circular linked list
struct Task {
    string name;                    // Task name
    int priority;                   // Task priority
    string status;                  // pending, in-progress, completed
    Task* next;                     // Pointer to next task

    Task(string n, int p, string s) { // Constructor
        name = n;
        priority = p;
        status = s;
        next = nullptr;
    }
};

class TaskList {
private:
    Task* head;                     // Head of circular list
    Task* current;                  // Points to last accessed task for round-robin

public:
    TaskList() {                    // Constructor
        head = nullptr;
        current = nullptr;
    }

    // Add a new task at the end
    void addTask(string name, int priority, string status) {
        Task* newNode = new Task(name, priority, status);
        if (head == nullptr) {      // If list is empty
            head = newNode;
            newNode->next = head;   // Point to itself
            current = head;
        } else {
            Task* temp = head;
            while (temp->next != head) { // Find last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Task '" << name << "' added.\n";
    }

    // Remove a task by name
    void removeTask(string name) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        // If head is to be removed
        if (head->name == name) {
            if (head->next == head) { // Only one node
                delete head;
                head = nullptr;
                current = nullptr;
            } else {
                Task* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                last->next = head->next;
                Task* temp = head;
                head = head->next;
                if (current == temp) current = head;
                delete temp;
            }
            cout << "Task '" << name << "' removed.\n";
            return;
        }
        // Search in rest of the list
        Task* prev = head;
        Task* curr = head->next;
        while (curr != head) {
            if (curr->name == name) {
                prev->next = curr->next;
                if (current == curr) current = curr->next;
                delete curr;
                cout << "Task '" << name << "' removed.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Task '" << name << "' not found.\n";
    }

    // Get next pending task in round-robin order
    void getNextTask() {
        if (head == nullptr) {
            cout << "No tasks in the list.\n";
            return;
        }
        if (current == nullptr) current = head;
        Task* start = current;
        do {
            if (current->status == "pending") {
                cout << "Next task: " << current->name 
                     << " (Priority: " << current->priority << ")\n";
                current = current->next; // Move for next call
                return;
            }
            current = current->next;
        } while (current != start);
        cout << "No pending task found.\n";
    }

    // Display all tasks in a simple format
    void displayAll() {
        if (head == nullptr) {
            cout << "No tasks to display.\n";
            return;
        }
        cout << "\n--- Task List ---\n";
        Task* temp = head;
        do {
            cout << temp->name << " (Priority: " << temp->priority 
                 << ") - " << temp->status << "\n";
            temp = temp->next;
        } while (temp != head);
        cout << "-----------------\n";
    }

    // Update status of a task by name
    void updateStatus(string name, string newStatus) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Task* temp = head;
        do {
            if (temp->name == name) {
                temp->status = newStatus;
                cout << "Status of '" << name << "' updated to " 
                     << newStatus << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Task '" << name << "' not found.\n";
    }
};

int main() {
    TaskList list;
    int choice;
    do {
        cout << "\n=== Task Scheduler ===\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Get Next Task\n";
        cout << "4. Display All Tasks\n";
        cout << "5. Update Task Status\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline

        switch (choice) {
            case 1: {
                string name, status;
                int priority;
                cout << "Enter task name: ";
                getline(cin, name);
                cout << "Enter priority: ";
                cin >> priority;
                cin.ignore();
                cout << "Enter status (pending/in-progress/completed): ";
                getline(cin, status);
                list.addTask(name, priority, status);
                break;
            }
            case 2: {
                string name;
                cout << "Enter task name to remove: ";
                getline(cin, name);
                list.removeTask(name);
                break;
            }
            case 3: {
                list.getNextTask();
                break;
            }
            case 4: {
                list.displayAll();
                break;
            }
            case 5: {
                string name, newStatus;
                cout << "Enter task name to update: ";
                getline(cin, name);
                cout << "Enter new status: ";
                getline(cin, newStatus);
                list.updateStatus(name, newStatus);
                break;
            }
            case 6: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice.\n";
            }
        }
    } while (choice != 6);

    return 0;
}
