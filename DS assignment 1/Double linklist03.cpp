#include <iostream>                 // Include input-output stream
#include <string>                   // Include string class
using namespace std;                // Use standard namespace

struct Item {                       // Node for an item
    string name;                    // Item name
    string location;                // Location inside section
    Item* next;                     // Pointer to next item
    Item* prev;                     // Pointer to previous item
};                                  // End Item structure

struct Section {                    // Node for a section
    string name;                    // Section name
    Item* itemHead;                 // Head of items in this section
    Section* next;                  // Pointer to next section
    Section* prev;                  // Pointer to previous section
};                                  // End Section structure

struct Store {                      // Node for a store
    string name;                    // Store name
    Section* sectionHead;           // Head of sections in this store
    Store* next;                    // Pointer to next store
    Store* prev;                    // Pointer to previous store
};                                  // End Store structure

class Inventory {                   // Inventory management class
private:                            // Private members
    Store* storeHead;               // Head of stores list
public:                             // Public methods
    Inventory() {                   // Constructor
        storeHead = nullptr;        // Initially no stores
    }                               // End constructor

    Store* findStore(string storeName) { // Find store by name
        Store* temp = storeHead;    // Start from head
        while (temp != nullptr) {   // Traverse stores
            if (temp->name == storeName) return temp; // Found
            temp = temp->next;      // Move next
        }                           // End while
        return nullptr;             // Not found
    }                               // End findStore

    Section* findSection(Store* store, string sectionName) { // Find section in store
        if (store == nullptr) return nullptr; // Invalid store
        Section* temp = store->sectionHead;   // Start from section head
        while (temp != nullptr) {             // Traverse sections
            if (temp->name == sectionName) return temp; // Found
            temp = temp->next;                // Move next
        }                                     // End while
        return nullptr;                       // Not found
    }                                         // End findSection

    void addStore(string storeName) {         // Add a new store
        Store* newStore = new Store;          // Allocate new store
        newStore->name = storeName;           // Set store name
        newStore->sectionHead = nullptr;      // No sections yet
        newStore->next = nullptr;             // Next null
        newStore->prev = nullptr;             // Prev null
        if (storeHead == nullptr) {           // If no stores
            storeHead = newStore;             // New store becomes head
        } else {                              // If stores exist
            Store* temp = storeHead;          // Start from head
            while (temp->next != nullptr) {   // Go to last store
                temp = temp->next;            // Move next
            }                                 // End while
            temp->next = newStore;            // Link last to new store
            newStore->prev = temp;            // Link new store back
        }                                     // End if-else
    }                                         // End addStore

    void addSection(string storeName, string sectionName) { // Add section to store
        Store* store = findStore(storeName);  // Find store
        if (store == nullptr) {               // If store not found
            cout << "Store not found\n";      // Print error
            return;                           // Exit
        }                                     // End if
        Section* newSection = new Section;    // Allocate new section
        newSection->name = sectionName;       // Set section name
        newSection->itemHead = nullptr;       // No items yet
        newSection->next = nullptr;           // Next null
        newSection->prev = nullptr;           // Prev null
        if (store->sectionHead == nullptr) {  // If no sections
            store->sectionHead = newSection;  // New section becomes head
        } else {                              // If sections exist
            Section* temp = store->sectionHead; // Start from head
            while (temp->next != nullptr) {   // Go to last section
                temp = temp->next;            // Move next
            }                                 // End while
            temp->next = newSection;          // Link last to new
            newSection->prev = temp;          // Link new back
        }                                     // End if-else
        cout << "Section added.\n";           // Confirmation
    }                                         // End addSection

    void addItem(string storeName, string sectionName, string itemName, string location) { // Add item
        Store* store = findStore(storeName);  // Find store
        if (store == nullptr) {               // If store not found
            cout << "Store not found\n";      // Print error
            return;                           // Exit
        }                                     // End if
        Section* section = findSection(store, sectionName); // Find section
        if (section == nullptr) {             // If section not found
            cout << "Section not found\n";    // Print error
            return;                           // Exit
        }                                     // End if
        Item* newItem = new Item;             // Allocate new item
        newItem->name = itemName;             // Set item name
        newItem->location = location;         // Set item location
        newItem->next = nullptr;              // Next null
        newItem->prev = nullptr;              // Prev null
        if (section->itemHead == nullptr) {   // If no items
            section->itemHead = newItem;      // New item becomes head
        } else {                              // If items exist
            Item* temp = section->itemHead;   // Start from head
            while (temp->next != nullptr) {   // Go to last item
                temp = temp->next;            // Move next
            }                                 // End while
            temp->next = newItem;             // Link last to new item
            newItem->prev = temp;             // Link new item back
        }                                     // End if-else
        cout << "Item added.\n";              // Confirmation
    }                                         // End addItem

    void removeItem(string storeName, string sectionName, string itemName) { // Remove item
        Store* store = findStore(storeName);  // Find store
        if (store == nullptr) {               // If store not found
            cout << "Store not found\n";      // Print error
            return;                           // Exit
        }                                     // End if
        Section* section = findSection(store, sectionName); // Find section
        if (section == nullptr) {             // If section not found
            cout << "Section not found\n";    // Print error
            return;                           // Exit
        }                                     // End if
        Item* temp = section->itemHead;       // Start from item head
        while (temp != nullptr && temp->name != itemName) { // Search item
            temp = temp->next;                // Move next
        }                                     // End while
        if (temp == nullptr) {                // If not found
            cout << "Item not found\n";       // Print error
            return;                           // Exit
        }                                     // End if
        if (temp == section->itemHead) {      // If removing head item
            section->itemHead = temp->next;   // Move head forward
        }                                     // End if
        if (temp->prev != nullptr) {          // If has previous
            temp->prev->next = temp->next;    // Link previous to next
        }                                     // End if
        if (temp->next != nullptr) {          // If has next
            temp->next->prev = temp->prev;    // Link next to previous
        }                                     // End if
        delete temp;                          // Free memory
        cout << "Item removed.\n";            // Confirmation
    }                                         // End removeItem

    void displaySectionItems(string storeName, string sectionName) { // Display items in section
        Store* store = findStore(storeName);  // Find store
        if (store == nullptr) {               // If store not found
            cout << "Store not found\n";      // Print error
            return;                           // Exit
        }                                     // End if
        Section* section = findSection(store, sectionName); // Find section
        if (section == nullptr) {             // If section not found
            cout << "Section not found\n";    // Print error
            return;                           // Exit
        }                                     // End if
        cout << "Items in " << storeName << " / " << sectionName << ":\n"; // Header
        Item* temp = section->itemHead;       // Start from item head
        while (temp != nullptr) {             // Traverse items
            cout << temp->name << " (Location: " << temp->location << ")\n"; // Print item
            temp = temp->next;                // Move next
        }                                     // End while
    }                                         // End displaySectionItems

    void displayStoreItems(string storeName) { // Display all items in a store
        Store* store = findStore(storeName);  // Find store
        if (store == nullptr) {               // If store not found
            cout << "Store not found\n";      // Print error
            return;                           // Exit
        }                                     // End if
        cout << "Items in store " << storeName << ":\n"; // Header
        Section* sec = store->sectionHead;    // Start from section head
        while (sec != nullptr) {              // Traverse sections
            cout << "Section: " << sec->name << "\n"; // Print section
            Item* item = sec->itemHead;       // Start from item head
            while (item != nullptr) {         // Traverse items
                cout << "  " << item->name << " (Location: " << item->location << ")\n"; // Print item
                item = item->next;            // Move next
            }                                 // End while
            sec = sec->next;                  // Move next section
        }                                     // End while
    }                                         // End displayStoreItems
};                                            // End Inventory class

int main() {                                  // Main function
    Inventory inv;                            // Create inventory object
    inv.addStore("StoreA");                   // Add store A
    inv.addSection("StoreA", "Toys");         // Add Toys section
    inv.addItem("StoreA", "Toys", "Car", "A1"); // Add item Car
    inv.addItem("StoreA", "Toys", "Doll", "A2"); // Add item Doll
    inv.addSection("StoreA", "Grocery");      // Add Grocery section
    inv.addItem("StoreA", "Grocery", "Apple", "B1"); // Add item Apple
    inv.displaySectionItems("StoreA", "Toys"); // Display Toys items
    inv.displayStoreItems("StoreA");          // Display all StoreA items
    inv.removeItem("StoreA", "Toys", "Car");  // Remove Car
    inv.displaySectionItems("StoreA", "Toys"); // Display Toys again
    return 0;                                 // Return success
}                                             // End main
