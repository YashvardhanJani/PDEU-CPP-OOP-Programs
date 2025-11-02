#include <iostream>
#include <string>
using namespace std;

class BankAccount;

class Wallet {
private:
    int cashAmount;   
    
public:
    Wallet(int cashAmount) {
        this->cashAmount = cashAmount;
    }

    void display(){
        cout << "My Wallet: Cash Amount = $" << cashAmount << endl;
    }

    friend  int  getTotalFunds(const  Wallet&  w,  const BankAccount& ba);    
};

class BankAccount {
private:
    int savings;

public:
    BankAccount(int savings) {
        this->savings = savings;
    }

    void display(){
        cout << "My Bank Account: Savings = $" << savings << endl;
    }

    friend  int  getTotalFunds(const  Wallet&  w,  const BankAccount& ba);
};

int getTotalFunds(const  Wallet&  w,  const BankAccount& ba){
    int total = w.cashAmount + ba.savings;
    return total;
}

int main()
{
    Wallet mywallet(500);
    BankAccount myAccount(1500);

    mywallet.display();
    myAccount.display();

    cout << "\nTotal Funds (Wallet + BankAccount): $" << getTotalFunds(mywallet, myAccount) << endl; 

    return 0;
}