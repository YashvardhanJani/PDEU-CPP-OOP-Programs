#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // for isspace, isalpha

using namespace std;

int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;

    ifstream file(filename);

    // Check if file opened successfully
    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1;
    }

    cout << "File opened successfully.\n";

    int charCount = 0, wordCount = 0, sentenceCount = 0;
    char ch;
    bool inWord = false;

    while (file.get(ch)) {
        // Count every character (excluding newline for clarity if desired)
        if (ch != '\n' && ch != '\r')
            charCount++;

        // Check if we are in a word
        if (isspace(ch)) {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
        } else {
            inWord = true;
        }

        // Count sentences
        if (ch == '.' || ch == '?') {
            sentenceCount++;
        }
    }

    // If file ends while inside a word, count that word
    if (inWord) {
        wordCount++;
    }

    file.close();

    // Display the final results
    cout << "\nFile Analysis:\n";
    cout << "Total Characters: " << charCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Sentences: " << sentenceCount << endl;

    return 0;
}