#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string inputFileName, outputFileName;

    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    ifstream inputFile(inputFileName, ios::in);
    ofstream outputFile(outputFileName, ios::out);

    if(!inputFile) {
        cerr << "Error: Could not open input file '" << inputFileName << "'." << endl;
        return 1;
    }

    if(!outputFile){
        cerr << "Error: Could not open output file '" << outputFileName << "'." << endl;
        return 1;
    }

    set<string> uniqueLines;
    string line;

    while (getline(inputFile, line)) {
        uniqueLines.insert(line); // Insert into set (automatically removes duplicates)
    }

    for (const auto& uniqueLine : uniqueLines) {
        outputFile << uniqueLine << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "-> Unique lines have been written to " << outputFileName << endl;

    return 0;
}