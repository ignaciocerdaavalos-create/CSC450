#include <iostream>
using namespace std;

int main() {
    // Step 1: Variables
    int a, b, c;

    cout << "Enter three integer values: ";
    cin >> a >> b >> c;

    // Step 2: Dynamic memory allocation
    int* p1 = new int;
    int* p2 = new int;
    int* p3 = new int;

    // Step 3: Store values in dynamic memory
    *p1 = a;
    *p2 = b;
    *p3 = c;

    // Step 4: Display results
    cout << "\n--- Variable Values ---\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "\n--- Pointer Values (Dereferenced) ---\n";
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    cout << "*p3 = " << *p3 << endl;

    cout << "\n--- Pointer Memory Addresses ---\n";
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;

    // Step 5: Free memory
    delete p1;
    delete p2;
    delete p3;

    // Step 6: Avoid dangling pointers
    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;

    return 0;
}
