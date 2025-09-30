/*
Bank Account Simulation with Static ID Generation
Problem:
Create a BankAccount class that includes:
•	Static variable to generate unique account numbers
•	Parameterized constructor to initialize name and balance
•	Destructor to show account closed message
Challenge:
•	Keep track of number of accounts created
•	Use static members and constructor logic
*/

#include<bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    static int nextAccountNumber;
    static int totalAccounts;
    
    int accountNumber;
    string accountHolder;
    long long balance;

public:
    // Parameterized Constructor
    BankAccount(string name, long long initialBalance) {
        accountNumber = ++nextAccountNumber;  // Generate unique account number
        accountHolder = name;
        balance = initialBalance;
        totalAccounts++;
        cout << "Account created: " << accountHolder << " | Account No: " << accountNumber << " | Balance: " << balance << endl; 
    }    
    
    ~BankAccount(){
        cout << "Account closed: " << accountHolder << " | Account No: " << accountNumber << endl;
        totalAccounts--;
    }

    // Function to display account details
    void display() const {
        cout << "Account Holder: " << accountHolder << " | Account No: " << accountNumber << " | Balance: " << balance << endl;
    }

    // Static function to show number of active accounts
    static void showTotalAccounts() {
        cout << "Total active accounts: " << totalAccounts << endl;
    }
};

// Initialize static members
int BankAccount::nextAccountNumber = 1000;
int BankAccount::totalAccounts = 0;

int main()
{
    BankAccount::showTotalAccounts();  // Should be 0
    cout << endl;

    {
        string name;
        long long balance;
        cout << "Enter Name & Balance for acc1: ";
        cin >> name >> balance;
        BankAccount acc1(name, balance);
        // BankAccount acc2("Bob", 3000.00);
        cout << "Enter Name & Balance for acc2: ";
        cin >> name >> balance;
        BankAccount acc2(name, balance);

        cout << endl;
        acc1.display();
        acc2.display();
        cout << endl;

        BankAccount::showTotalAccounts();  // Should be 2
    }  // acc1 and acc2 go out of scope here

    cout << endl;
    BankAccount::showTotalAccounts();  // Should be 0

    return 0;
}