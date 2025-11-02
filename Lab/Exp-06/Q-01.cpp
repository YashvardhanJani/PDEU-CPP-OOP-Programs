// Write a C++ program to demonstrate single inheritance using Person and Student classes.

#include<iostream>
#include<string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:   
    Person(string name, int age){
        this->name = name;
        this->age = age;
        cout << "Person constructor called.." << endl;
    }

    void displayPerson(){
        cout << "Person Details:" << endl;
        cout << "   Name: " << name << endl;
        cout << "   Age: " << age << endl;
    }
};

class Student : public Person {
private:
    string studentId;
    string major;

public:
    Student(string name, int age, string studentId, string major) : Person(name, age){
        this->studentId = studentId;
        this->major = major;
        cout << "Student constructor called.." << endl;
    }

    void displayStudent(){
        displayPerson();
        cout << "Student Details:" << endl;
        cout << "   Student-ID: " << studentId << endl;
        cout << "   Major: " << major << endl;
    }
};

int main()
{
    Student s1("Veerbhadra Bhatt", 18, "23ABC123", "CSE");
    s1.displayStudent();
    return 0;
}