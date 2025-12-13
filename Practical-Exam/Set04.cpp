/* [OOP Practical Eaxm 2025 - Set 04]
a) You are required to design a Library Book Management System using OOP.
Create a base class Book with: Data members: title, author, price
Constructors: Default constructor, Parameterized constructor. A function showBook() to display details.
b) Derive two classes: TextBook: Additional data: subject, Override showBook()
class ReferenceBook: Additional data: edition, Override showBook()
Write a program to: Create objects of both derived classes
Use a Book* pointer to call showBook() (runtime polymorphism)
c) Overload the + operator in the Book class to add prices of two books:
float operator+(Book b);
Usage:
float total = bl + b2: Display the total price.
d) In main():
Create 1 TextBook and 1 ReferenceBook
Display both using base class pointer
Add their prices using overloaded + operator
Display final amount to pay
*/

#include <iostream>
using namespace std;

class Book {
protected:
    string title;
    string author;
    float price;

public:
    Book() {
        title = "NULL";
        author = "NULL";
        price = 0.0;
    }

    Book(string t, string a, float p) {
        title = t;
        author = a;
        price = p;
    }

    // Virtual function for runtime polymorphism
    virtual void showBook() {
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Price  : Rs. " << price << endl;
    }

    // Operator Overloading (+)
    float operator+(Book b) {
        return this->price + b.price;
    }

    virtual ~Book() {}
};

class TextBook : public Book {
private:
    string subject;

public:
    TextBook(string t, string a, float p, string s)
        : Book(t, a, p) {
        subject = s;
    }

    void showBook() override {
        cout << "\n--- Text Book Details ---\n";
        Book::showBook();
        cout << "Subject: " << subject << endl;
    }
};

class ReferenceBook : public Book {
private:
    int edition;

public:
    ReferenceBook(string t, string a, float p, int e)
        : Book(t, a, p) {
        edition = e;
    }

    void showBook() override {
        cout << "\n--- Reference Book Details ---\n";
        Book::showBook();
        cout << "Edition: " << edition << endl;
    }
};

int main() {
    TextBook tb("OOP with C++", "Bjarne Stroustrup", 450.0, "Computer Science");
    ReferenceBook rb("Database System", "Korth", 650.0, 7);

    // Base class pointer
    Book* b;

    // Runtime Polymorphism
    b = &tb;
    b->showBook();

    b = &rb;
    b->showBook();

    // Operator Overloading usage
    float totalPrice = tb + rb;

    cout << "\nTotal Amount to Pay: Rs. " << totalPrice << endl;

    return 0;
}