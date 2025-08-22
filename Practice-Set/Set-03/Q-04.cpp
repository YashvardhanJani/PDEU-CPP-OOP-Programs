/*
Create a class Person that stores a name using a dynamically allocated character array.
Implement:
•	Parameterized constructor
•	Copy constructor
•	Destructor
Task:
•	Demonstrate the difference between shallow copy and deep copy by manipulating the copied object.
•	Explain memory leakage if deep copy isn't used.
*/

#include<bits/stdc++.h>
using namespace std;

class Person{
private:    
    char* name;

public:
    // Parameterized Constructor
    Person(const char *n){
        name = new char[strlen(n)+1];
        strcpy(name,n);
        cout << "Constructor: Created person with name = " << name << endl;
    }

    // Deep Copy Constructor
    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        cout << "Copy Constructor (Deep Copy): Copied person with name = " << name << endl;
    }

    // Destructor
    ~Person() {
        cout << "Destructor: Deleting person with name = " << name << endl;
        delete[] name;
    } 

    // Function to update name
    void updateName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    // Function to display name
    void display() const {
        cout << "Person Name: " << name << endl;
    }
};

int main()
{
    cout << "Creating person1...\n";
    Person person1("Amit");

    cout << "\nCreating person2 as a copy of Person 1...\n";
    Person person2 = person1; // Triggers deep copy constructor

    cout << "\nChanging name of Person 2 to Bharat...\n";
    person2.updateName("Bharat");

    cout << "\nDisplaying both persons:\n";
    person1.display(); // Should still be Amit
    person2.display(); // Should be Bharat
    
    return 0;
}