/* 
Shopping Cart System 
Domain: E-Commerce 
Objective: Use constructors to initialize cart items and destructors to clean up. 
Problem Statement: 
Design a class CartItem with attributes like productName, quantity, pricePerItem. 
* Use a default constructor to initialize empty values. 
* Use a parameterized constructor to initialize items when added to cart. 
* Use a destructor to print a message like "Item <productName> removed from cart." 
In main(), allow the user to add multiple items to the cart (via object creation) and simulate checkout. 
*/

#include<bits/stdc++.h>
using namespace std;

class CartItem {
private:
    string productName;
    int quantity;
    double pricePerItem;

    
public:   
    // Default Constructor
    CartItem(){
        productName = "";
        quantity = 0;
        pricePerItem = 0.0;
        cout << "Default Constructor Called";
    }    

    // Parameterized constructor
    CartItem(string name, int qty, double price) {
        productName = name;
        quantity = qty;
        pricePerItem = price;
    }

    // Calculate total price of item
    double getTotalPrice() const {
        return quantity * pricePerItem;
    }

    // Display item details
    void displayItem() const {
        cout << "Product: " << productName
             << ", Quantity: " << quantity
             << ", Price per Item: Rs." << pricePerItem
             << ", Total: Rs." << getTotalPrice() << endl;
    }

    // Destructor
    ~CartItem() {
        cout << "Item \"" << productName << "\" removed from cart." << endl;
    }

};

int main() {
    int n;
    cout << "Enter number of items to add to cart: ";
    cin >> n;

    vector<CartItem*> cart; // Using pointers to see destructor messages at cleanup

    for (int i = 0; i < n; i++) {
        string name;
        int qty;
        double price;

        cout << "\nEnter details for item " << i + 1 << ":\n";
        cout << "Product Name: ";
        cin.ignore(); // To handle input buffer
        getline(cin, name);
        cout << "Quantity: ";
        cin >> qty;
        cout << "Price per item (Rs.): ";
        cin >> price;

        // Create a new CartItem using parameterized constructor
        CartItem* item = new CartItem(name, qty, price);
        cart.push_back(item);
    }

    // Display cart summary
    cout << "\n----- Cart Summary -----\n";
    double grandTotal = 0.0;
    for (CartItem* item : cart) {
        item->displayItem();
        grandTotal += item->getTotalPrice();
    }
    cout << "-------------------------\n";
    cout << "Grand Total: Rs." << grandTotal << endl;
    cout << endl;

    // Cleanup: simulate checkout (destroy objects)
    for (CartItem* item : cart) {
        delete item; // Triggers destructor
    }

    return 0;
}