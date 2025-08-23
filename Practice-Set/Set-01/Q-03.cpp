// Write a Program to Remove Spaces From a String

#include<iostream>
#include<string>
using namespace std;

string removeSpaces(const string& str) {
    string result;
    for (char ch : str) {
        if (ch != ' ') { // Check if the character is not a space
            result += ch; // Append non-space characters to the result
        }
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string output = removeSpaces(input);
    cout << "String after removing spaces: " << output << endl;

    return 0;
}