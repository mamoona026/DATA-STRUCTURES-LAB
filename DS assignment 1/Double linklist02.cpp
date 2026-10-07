#include <iostream>                 // Include input-output stream
#include <string>                   // Include string class
using namespace std;                // Use standard namespace

struct Song {                       // Node for a song
    string title;                   // Song title
    Song* next;                     // Pointer to next song
    Song* prev;                     // Pointer to previous song
};                                  // End Song structure

class Playlist {                    // Playlist class using doubly linked list
private:                            // Private members
    Song* head;                     // First song
    Song* tail;                     // Last song
    Song* current;                  // Currently playing song
public:                             // Public methods
    Playlist() {                    // Constructor
        head = nullptr;             // Initially empty
        tail = nullptr;             // Initially empty
        current = nullptr;          // No current song
    }                               // End constructor

    void addSong(string title) {    // Add song at end of playlist
        Song* newSong = new Song;   // Allocate new song node
        newSong->title = title;     // Set song title
        newSong->next = nullptr;    // Next is null
        newSong->prev = nullptr;    // Prev is null
        if (head == nullptr) {      // If playlist empty
            head = newSong;         // Head becomes new song
            tail = newSong;         // Tail becomes new song
            current = newSong;      // Current becomes new song
        } else {                    // If playlist not empty
            tail->next = newSong;   // Old tail points to new song
            newSong->prev = tail;   // New song points back to old tail
            tail = newSong;         // Update tail
        }                           // End if-else
    }                               // End addSong

    void removeSong(string title) { // Remove song by title
        Song* temp = head;          // Start from head
        while (temp != nullptr && temp->title != title) { // Search for title
            temp = temp->next;      // Move to next song
        }                           // End while
        if (temp == nullptr) {      // If not found
            cout << "Song not found: " << title << endl; // Print message
            return;                 // Exit method
        }                           // End if
        if (temp == head) {         // If removing head
            head = temp->next;      // Move head forward
        }                           // End if
        if (temp == tail) {         // If removing tail
            tail = temp->prev;      // Move tail backward
        }                           // End if
        if (temp->prev != nullptr) { // If node has previous
            temp->prev->next = temp->next; // Link previous to next
        }                           // End if
        if (temp->next != nullptr) { // If node has next
            temp->next->prev = temp->prev; // Link next to previous
        }                           // End if
        if (current == temp) {      // If removing current song
            current = (temp->next != nullptr) ? temp->next : head; // Update current
        }                           // End if
        delete temp;                // Free memory
    }                               // End removeSong

    void displayForward() {         // Display playlist from first to last
        Song* temp = head;          // Start from head
        while (temp != nullptr) {   // Until end
            cout << temp->title;    // Print title
            if (temp->next != nullptr) cout << " <-> "; // Separator
            temp = temp->next;      // Move next
        }                           // End while
        cout << endl;               // New line
    }                               // End displayForward

    void displayBackward() {        // Display playlist from last to first
        Song* temp = tail;          // Start from tail
        while (temp != nullptr) {   // Until beginning
            cout << temp->title;    // Print title
            if (temp->prev != nullptr) cout << " <-> "; // Separator
            temp = temp->prev;      // Move prev
        }                           // End while
        cout << endl;               // New line
    }                               // End displayBackward

    void playNext() {               // Play next song
        if (current == nullptr) {   // If no current song
            current = head;         // Set current to head
        } else if (current->next != nullptr) { // If next exists
            current = current->next; // Move to next
        } else {                    // If at end
            current = head;         // Wrap around to head
        }                           // End if-else
        if (current != nullptr)     // If current exists
            cout << "Playing: " << current->title << endl; // Display
    }                               // End playNext

    void playPrevious() {           // Play previous song
        if (current == nullptr) {   // If no current song
            current = tail;         // Set current to tail
        } else if (current->prev != nullptr) { // If previous exists
            current = current->prev; // Move to previous
        } else {                    // If at beginning
            current = tail;         // Wrap around to tail
        }                           // End if-else
        if (current != nullptr)     // If current exists
            cout << "Playing: " << current->title << endl; // Display
    }                               // End playPrevious
};                                  // End Playlist class

int main() {                        // Main function
    Playlist pl;                    // Create playlist object
    pl.addSong("Song A");           // Add song A
    pl.addSong("Song B");           // Add song B
    pl.addSong("Song C");           // Add song C
    pl.addSong("Song D");           // Add song D
    cout << "Forward: ";            // Print label
    pl.displayForward();            // Display forward
    cout << "Backward: ";           // Print label
    pl.displayBackward();           // Display backward
    pl.playNext();                  // Play next
    pl.playNext();                  // Play next
    pl.playPrevious();              // Play previous
    pl.removeSong("Song B");        // Remove Song B
    cout << "After removal: ";      // Print label
    pl.displayForward();            // Display forward again
    return 0;                       // Return success
}                                   // End main
