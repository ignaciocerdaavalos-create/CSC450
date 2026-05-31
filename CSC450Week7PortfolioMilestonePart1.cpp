#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

void countUp() {
    for (int i = 1; i <= 20; i++) {
        cout << "Counting up: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

void countDown() {
    for (int i = 20; i >= 0; i--) {
        cout << "Counting down: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main() {
    cout << "Starting Thread 1 (Count Up)" << endl;

    thread t1(countUp);
    t1.join();  // Wait for thread 1 to finish

    cout << "\nThread 1 finished. Starting Thread 2 (Count Down)" << endl;

    thread t2(countDown);
    t2.join();  // Wait for thread 2 to finish

    cout << "\nBoth threads completed successfully." << endl;

    return 0;
}
