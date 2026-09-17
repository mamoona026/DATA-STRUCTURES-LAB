#include <iostream>
using namespace std;

int* getPointer() {
    int x = 10;
    
    // returning address of local variable
    return &x; 
}

int main() {
    
    // ptr becomes dangling here
    int* ptr = getPointer(); 
    
    // Undefined behavior
     cout << *ptr; 
    return 0;
}
