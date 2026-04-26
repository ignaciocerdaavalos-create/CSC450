#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2, result;

    cout << "This program will take two strings from the user 3 times,\n";
    cout << "concatenate them, and display the result.\n\n";

    for (int i = 1; i <= 3; i++) {
        cout << "---- Input Set " << i << " ----\n";

        cout << "Enter first string: ";
        getline(cin, str1);

        cout << "Enter second string: ";
        getline(cin, str2);

        // Concatenate strings
        result = str1 + str2;

        cout << "Concatenated result: " << result << "\n\n";
    }

    return 0;
}
