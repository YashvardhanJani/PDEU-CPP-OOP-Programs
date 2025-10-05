/*
Write a console-based programs to:
    Add student records
    View all records
    Search for a student by ID
    Delete a student by ID
All data is stored in a binary file so it persists between runs.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    int id;
    char name[50];
    double gpa;

public:
    // Default constructor
    Student() : id(0), gpa(0.0) {
        name[0] = '\0';
    }

    // Input student details
    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    // Display student details
    void display() const {
        cout << left << setw(10) << id
             << setw(35) << name
             << gpa << endl;
    }

    // Save object to file
    void saveToFile(ofstream &outFile) {
        outFile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }

    // Read object from file
    bool readFromFile(ifstream &inFile) {
    inFile.read(reinterpret_cast<char*>(this), sizeof(*this));
    return static_cast<bool>(inFile);  // converts stream state to bool
    }

    // Getters
    int getId() const { return id; }
    const char* getName() const { return name; }
    double getGpa() const { return gpa; }
};

class StudentManager {
private:
    const char* filename = "students.dat";

public:
    // Add new student
    void addStudent() {
        Student s;
        s.input();

        ofstream outFile(filename, ios::binary | ios::app);
        s.saveToFile(outFile);
        outFile.close();

        cout << "Student record added successfully!\n";
    }

    // View all students
    void viewAllStudents() {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "No student records found.\n";
            return;
        }

        Student s;
        cout << "\nAll Student Records:\n";
        cout << left << setw(10) << "ID"
             << setw(35) << "Name"
             << "GPA" << endl;
        cout << "-------------------------------------------------\n";

        while (s.readFromFile(inFile)) {
            s.display();
        }
        inFile.close();
    }

    // Search student by ID
    void searchStudent() {
        int searchId;
        cout << "Enter Student ID to search: ";
        cin >> searchId;

        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "No student records found.\n";
            return;
        }

        Student s;
        bool found = false;
        while (s.readFromFile(inFile)) {
            if (s.getId() == searchId) {
                cout << "\nStudent Found:\n";
                cout << "ID: " << s.getId()
                     << "\nName: " << s.getName()
                     << "\nGPA: " << s.getGpa() << endl;
                found = true;
                break;
            }
        }
        inFile.close();

        if (!found) {
            cout << "Student with ID " << searchId << " not found.\n";
        }
    }

    // Delete student by ID
    void deleteStudent() {
        int deleteId;
        cout << "Enter Student ID to delete: ";
        cin >> deleteId;

        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "No student records found.\n";
            return;
        }

        ofstream outFile("temp.dat", ios::binary);
        Student s;
        bool deleted = false;

        while (s.readFromFile(inFile)) {
            if (s.getId() != deleteId) {
                s.saveToFile(outFile);
            } else {
                deleted = true;
            }
        }

        inFile.close();
        outFile.close();

        remove(filename);
        rename("temp.dat", filename);

        if (deleted)
            cout << "Student record deleted successfully.\n";
        else
            cout << "Student with ID " << deleteId << " not found.\n";
    }
};

// Main Menu
int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student Record\n";
        cout << "2. View All Records\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Delete Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.viewAllStudents(); break;
            case 3: manager.searchStudent(); break;
            case 4: manager.deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}