#include <iostream>
using namespace std;

int main() {
    int var = 10;

    // declare pointer and store address of var
    int* ptr = &var;
    //*ptr = 44;
    

    // print value and address
    cout << "Value of var: " << var << endl;
    cout << "Address of var: " << &var << endl;
    cout << "Value stored in pointer ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    //cout << "Value is now:" << *ptr << endl;
    return 0;
}
