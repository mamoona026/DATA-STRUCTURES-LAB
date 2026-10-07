#include <iostream>                 // Include input-output stream library.
#include <string>                   // Include string library.
using namespace std;                // Use standard namespace.

struct TaskNode {                   // Define a node for circular linked list.
    string name;                    // Store task name.
    int priority;                   // Store task priority.
    string status;                  // Store task status: pending, in-progress, completed.
    TaskNode* next;                 // Pointer to next task node.

    TaskNode(string n, int p, string s) { // Constructor for TaskNode.
        name = n;                   // Set task name.
        priority = p;               // Set task priority.
        status = s;                 // Set task status.
        next = nullptr;             // Initialize next pointer.
    }                               // End constructor.
};                                  // End TaskNode structure.

class TaskCircularList {            // Class for circular task list.
private:                            // Private members.
    TaskNode* head;                 // Head pointer of circular list.
    TaskNode* current;              // Current pointer for round-robin scheduling.

public:                             // Public methods.
    TaskCircularList() {            // Constructor.
        head = nullptr;             // Initially list is empty.
        current = nullptr;          // Initially current is null.
    }                               // End constructor.

    void addTask(string name, int priority, string status) { // Add task at end.
        TaskNode* newNode = new TaskNode(name, priority, status); // Create new node.
        if (head == nullptr) {      // If list is empty,
            head = newNode;         // New node becomes head.
            newNode->next = head;   // Point to itself to make circular.
            current = head;         // Set current to head.
            cout << "Task added successfully.\n"; // Print success message.
            return;                 // Exit method.
        }                           // End if.
        TaskNode* last = head;      // Start from head to find last node.
        while (last->next != head) { // Traverse until last node.
            last = last->next;      // Move to next node.
        }                           // End while.
        last->next = newNode;       // Link last node to new node.
        newNode->next = head;       // New node points back to head.
        cout << "Task added successfully.\n"; // Print success message.
    }                               // End addTask.

    void removeTask(string name) {  // Remove task by name.
        if (head == nullptr) {      // If list is empty,
            cout << "List is empty.\n"; // Print message.
            return;                 // Exit method.
        }                           // End if.
        if (head->name == name) {   // If head matches the task name,
            if (head->next == head) { // If only one node exists,
                delete head;        // Delete head node.
                head = nullptr;     // Set head to null.
                current = nullptr;  // Set current to null.
                cout << "Task removed successfully.\n"; // Print success message.
                return;             // Exit method.
            }                       // End if.
            TaskNode* last = head;  // Find last node.
            while (last->next != head) { // Traverse to last node.
                last = last->next;  // Move forward.
            }                       // End while.
            last->next = head->next; // Bypass old head.
            TaskNode* temp = head;  // Store old head.
            head = head->next;      // Move head to next node.
            if (current == temp) {  // If current was old head,
                current = head;     // Update current to new head.
            }                       // End if.
            delete temp;            // Delete old head.
            cout << "Task removed successfully.\n"; // Print success message.
            return;                 // Exit method.
        }                           // End if.
        TaskNode* prev = head;      // Previous node starts at head.
        TaskNode* curr = head->next;// Current node starts at next node.
        while (curr != head) {      // Traverse circular list except head.
            if (curr->name == name) { // If current task matches,
                prev->next = curr->next; // Bypass current node.
                if (current == curr) { // If current was removed node,
                    current = curr->next; // Update current pointer.
                }                   // End if.
                delete curr;        // Delete matched node.
                cout << "Task removed successfully.\n"; // Print success message.
                return;             // Exit method.
            }                       // End if.
            prev = curr;            // Move prev forward.
            curr = curr->next;      // Move curr forward.
        }                           // End while.
        cout << "Task not found.\n"; // Print not found message.
    }                               // End removeTask.

    void getNextTask() {            // Get next pending task in round-robin order.
        if (head == nullptr) {      // If list is empty,
            cout << "No tasks in the list.\n"; // Print message.
            return;                 // Exit method.
        }                           // End if.
        if (current == nullptr) {   // If current is null,
            current = head;         // Start from head.
        }                           // End if.
        TaskNode* start = current;  // Store starting point.
        do {                        // Check at least one full circle.
            if (current->status == "pending") { // If current task is pending,
                cout << "Next Task -> Name: " << current->name // Print task name.
                     << ", Priority: " << current->priority // Print priority.
                     << ", Status: " << current->status << endl; // Print status.
                current = current->next; // Move current to next task.
                return;             // Exit method.
            }                       // End if.
            current = current->next; // Skip non-pending task.
        } while (current != start); // Stop after full circle.
        cout << "No pending task found.\n"; // Print message if none pending.
    }                               // End getNextTask.

    void displayAllTasks() {        // Display all tasks in circular list.
        if (head == nullptr) {      // If list is empty,
            cout << "No tasks to display.\n"; // Print message.
            return;                 // Exit method.
        }                           // End if.
        TaskNode* temp = head;      // Start from head.
        cout << "\n--- All Tasks ---\n"; // Print heading.
        do {                        // Traverse at least once.
            cout << "Name: " << temp->name // Print task name.
                 << ", Priority: " << temp->priority // Print priority.
                 << ", Status: " << temp->status << endl; // Print status.
            temp = temp->next;      // Move to next node.
        } while (temp != head);     // Stop when back to head.
    }                               // End displayAllTasks.

    void updateTaskStatus(string name, string newStatus) { // Update status by name.
        if (head == nullptr) {      // If list is empty,
            cout << "No tasks in the list.\n"; // Print message.
            return;                 // Exit method.
        }                           // End if.
        TaskNode* temp = head;      // Start from head.
        do {                        // Traverse circular list.
            if (temp->name == name) { // If task name matches,
                temp->status = newStatus; // Update status.
                cout << "Task updated -> Name: " << temp->name // Print updated name.
                     << ", Priority: " << temp->priority // Print priority.
                     << ", Status: " << temp->status << endl; // Print updated status.
                return;             // Exit method.
            }                       // End if.
            temp = temp->next;      // Move to next node.
        } while (temp != head);     // Stop when back to head.
        cout << "Task not found.\n"; // Print not found message.
    }                               // End updateTaskStatus.
};                                  // End TaskCircularList class.

int main() {                        // Program starts here.
    TaskCircularList list;          // Create circular task list object.
    int choice;                     // Store user menu choice.
    do {                            // Start menu loop.
        cout << "\n===== Task Scheduling Menu =====\n"; // Print menu heading.
        cout << "1. Add Task\n";    // Print option 1.
        cout << "2. Remove Task\n"; // Print option 2.
        cout << "3. Get Next Task\n"; // Print option 3.
        cout << "4. Display All Tasks\n"; // Print option 4.
        cout << "5. Update Task Status\n"; // Print option 5.
        cout << "6. Exit\n";        // Print option 6.
        cout << "Enter choice: ";   // Prompt for choice.
        cin >> choice;              // Read choice.
        cin.ignore();               // Clear newline from input buffer.
        switch (choice) {           // Handle selected option.
            case 1: {               // Add task case.
                string name, status; // Variables for task name and status.
                int priority;       // Variable for priority.
                cout << "Enter task name: "; // Prompt for name.
                getline(cin, name); // Read full task name.
                cout << "Enter priority: "; // Prompt for priority.
                cin >> priority;    // Read priority.
                cin.ignore();       // Clear newline.
                cout << "Enter status (pending/in-progress/completed): "; // Prompt for status.
                getline(cin, status); // Read status.
                list.addTask(name, priority, status); // Call addTask.
                break;              // Break from switch.
            }                       // End case 1.
            case 2: {               // Remove task case.
                string name;        // Variable for task name.
                cout << "Enter task name to remove: "; // Prompt for name.
                getline(cin, name); // Read task name.
                list.removeTask(name); // Call removeTask.
                break;              // Break from switch.
            }                       // End case 2.
            case 3: {               // Get next task case.
                list.getNextTask(); // Call getNextTask.
                break;              // Break from switch.
            }                       // End case 3.
            case 4: {               // Display all tasks case.
                list.displayAllTasks(); // Call displayAllTasks.
                break;              // Break from switch.
            }                       // End case 4.
            case 5: {               // Update status case.
                string name, newStatus; // Variables for task name and new status.
                cout << "Enter task name to update: "; // Prompt for name.
                getline(cin, name); // Read task name.
                cout << "Enter new status: "; // Prompt for new status.
                getline(cin, newStatus); // Read new status.
                list.updateTaskStatus(name, newStatus); // Call updateTaskStatus.
                break;              // Break from switch.
            }                       // End case 5.
            case 6: {               // Exit case.
                cout << "Exiting program.\n"; // Print exit message.
                break;              // Break from switch.
            }                       // End case 6.
            default: {              // Invalid choice case.
                cout << "Invalid choice.\n"; // Print invalid message.
                break;              // Break from switch.
            }                       // End default.
        }                           // End switch.
    } while (choice != 6);          // Repeat until user chooses exit.
    return 0;                       // Return success.
}                                   // End main.
