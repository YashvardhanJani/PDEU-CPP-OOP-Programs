#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    string inputFileName, outputFileName;

    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;
 
    ifstream inputFile(inputFileName, ios::in);     // open for reading
    ofstream outputFile(outputFileName, ios::out);  // open for writing

    if (!inputFile) {
        cerr << "Error: Could not open input file '" << inputFileName << "'." << endl;
        return 1;
    }
    if (!outputFile) {
        cerr << "Error: Could not open output file '" << outputFileName << "'." << endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        // Convert to uppercase safely
        ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
        // Write to output file
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    cout << "-> File has been converted to uppercase and saved to '" 
         << outputFileName << "' successfully." << endl;

    return 0;
}