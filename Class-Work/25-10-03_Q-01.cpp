// Implement Singly Linked-List in cpp.

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val) , next(nullptr) {}
};

template <typename T>
class LinkedList {
private:    
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtPosition(int data, int position) {
        Node<T>* newNode = new Node<T>(data);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node<T>* current = head;
        // Traverse to the node *before* the desired insertion point
        for (int i = 1; current != nullptr && i < position - 1; ++i) {
            current = current->next;
        }

        // Handle invalid position (position exceeds list length + 1)
        if (current == nullptr) {
            delete newNode; 
            return; 
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty, cannot delete.\n";
            return;
        }

        // Delete head node
        if (position == 1) {
            Node<T>* temp = head;
            head = head->next;
            cout << temp->data << " deleted from position " << position << ".\n";
            delete temp;
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;

        // Traverse to node before the one to be deleted
        for (int i = 1; current != nullptr && i < position; ++i) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid position! No node deleted.\n";
            return;
        }

        prev->next = current->next;
        cout << "-> " << current->data << " deleted from Position " << position << ".\n";
        delete current;
    }

    void display() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }

        cout << "Linked List: ";
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

int main()
{
    LinkedList<int> myLL;
    myLL.insertAtPosition(10,1);
    myLL.insertAtPosition(20,2);
    myLL.insertAtPosition(30,3);
    myLL.display();
    myLL.deleteAtPosition(2);
    myLL.display();

    return 0;
}