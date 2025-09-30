#include <iostream>
#include <string>
using namespace std;

class Widget {
private:
    int id;
    static int objectCount;
    static int nextId;

public:
    Widget() {
        id = ++nextId;
        ++objectCount;
        cout << "Widget constructor called. ID: " << id
             << "\nCurrent Widget count: " << objectCount << endl;
    }

    ~Widget() {
        cout << "Widget destructor called. ID: " << id << endl;
        --objectCount;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int Widget::objectCount = 0;
int Widget::nextId = 0;

int main()
{
    cout << "Current Widget count: " << Widget::getObjectCount() << endl;

    // Stack-allocated Widget
    Widget w1; // ID: 1
    Widget* w2 = new Widget(); // ID: 2 (heap)
    Widget* w3 = new Widget(); // ID: 3 (heap)

    // Delete heap object w3
    delete w3;
    std::cout << "Current Widget count after w3 destroyed: " << Widget::getObjectCount() << std::endl;

    // Delete heap object w2
    delete w2;
    std::cout << "Current Widget count after w2 deleted: " << Widget::getObjectCount() << std::endl;

    // Remaining Widget (w1) will be destroyed automatically at scope exit

    return 0;
}