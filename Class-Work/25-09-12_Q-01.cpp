// Write a program to demonstarate the sequence of constructor and destructor call in case of single inheritance, multiple inheritance, multi-level inheritance and hiereichal inheritance.

#include <iostream>
using namespace std;

class a1 {
public: 
    a1() {
        cout << "Constructor of a1 called.." << endl;
    }

    ~a1(){
        cout << "Destructor of a1 called.." << endl;
    }
};

class b1 {
public: 
    b1() {
        cout << "Constructor of b1 called.." << endl;
    }

    ~b1(){
        cout << "Destructor of b1 called.." << endl;
    }
};

class c1 : public a1 {
public:    
    c1() {
        cout << "Constructor of c1 called..(Single Inheritance)" << endl;
    }

    ~c1(){
        cout << "Destructor of c1 called.." << endl;
    }
};

class d1 : public c1 {
public:
    d1() {
        cout << "Constructor of d1 called..(Multi-level Inheritance)" << endl;
    }

    ~d1(){
        cout << "Destructor of d1 called.." << endl;
    }
};

class e1 : public a1, public b1 {
public:
    e1() {
        cout << "Constructor of e1 called..(Multiple Inheritance)" << endl;
    }

    ~e1(){
        cout << "Destructor of e1 called.." << endl;
    }
};

class f1 : public a1 {
public:    
    f1() {
        cout << "Constructor of f1 called..(Single Inheritance)" << endl;
    }

    ~f1(){
        cout << "Destructor of f1 called.." << endl;
    }
};

class g1 : public c1, public f1 {
public:
    g1() {
        cout << "Constructor of g1 called..(Hybrid Inheritance)" << endl;
    }

    ~g1(){
        cout << "Destructor of g1 called.." << endl;
    }
};


int main()
{
    cout << "\n--------------------Single Inheritance-----------------" << endl;
    c1 myC;
    cout << "\n-----------------Multi-level Inheritance---------------" << endl;
    d1 myD;
    cout << "\n------------------Multiple Inheritance-----------------" << endl;
    e1 myE;
    cout << "\n-------------------Hybrid Inheritance------------------" << endl;
    g1 myG;
    cout << "-------------------------------------------------------" << endl;
    cout << ":: Note: We inherited c1 & f1 from a1.\nThat is an example of Hiereichal Inheritance." << endl;
    cout << "-------------------------------------------------------" << endl;
    return 0;
}