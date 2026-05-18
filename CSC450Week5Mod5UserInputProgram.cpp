#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to reverse a string
string reverseString(const string& input) {
    string reversed = input;
    int left = 0;
    int right = reversed.length() - 1;

    while (left < right) {
        swap(reversed[left], reversed[right]);
        left++;
        right--;
    }

    return reversed;
}

int main() {
    string userInput;

    // Get user input
    cout << "Enter text to append to the file: ";
    getline(cin, userInput);   // Correct: getline allows spaces

    // Append user input to the file
    ofstream outFile("CSC450_CT5_mod5.txt", ios::app);
    if (!outFile) {
        cout << "Error opening CSC450_CT5_mod5.txt for appending." << endl;
        return 1;
    }
    outFile << userInput << endl;
    outFile.close();

    // Read entire file into a string
    ifstream inFile("CSC450_CT5_mod5.txt");
    if (!inFile) {
        cout << "Error opening CSC450_CT5_mod5.txt for reading." << endl;
        return 1;
    }

    string fileData((istreambuf_iterator<char>(inFile)),
                     istreambuf_iterator<char>());
    inFile.close();

    // Reverse the file contents
    string reversedData = reverseString(fileData);

    // Write reversed contents to new file
    ofstream reverseFile("CSC450-mod5-reverse.txt");  // Correct filename
    if (!reverseFile) {
        cout << "Error creating CSC450-mod5-reverse.txt." << endl;
        return 1;
    }
    reverseFile << reversedData;
    reverseFile.close();

    cout << "Data appended and reversed file created successfully." << endl;

    return 0;
}
