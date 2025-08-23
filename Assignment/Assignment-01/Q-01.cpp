// WAP in C++, Take name from user and its favorite number & word and print that word 3 times. In last write Goodbye message.

#include <iostream>  // For cin and cout
#include <string>    // For using string type

using namespace std;

int main() {
    string name;
    int favNumber;
    string favWord;

    // Ask user for their name
    cout << "What's your name? ";
    cin >> name;  // Takes input until first space
    cout << "Hello, " << name << "! Nice to meet you." << endl;

    // Ask for favorite number
    cout << "\nWhat's your favorite number? ";
    cin >> favNumber;
    cout << "Did you know " << favNumber << " doubled is " << favNumber * 2 << "?" << endl;

    // Ask for favorite word
    cout << "\nWhat's your favorite word? ";
    cin >> favWord;
    cout << favWord << " " << favWord << " " << favWord << endl;

    // Goodbye message
    cout << "\nGoodbye, " << name << "! See you next time." << endl;

    return 0;
}
