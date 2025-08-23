// Write a Program to Calculate the Greatest Common Divisor of Two Numbers

#include<iostream>
using namespace std;

int findGCD(int a, int b){
    int gcd = 1;
    for(int i=1;i<=a;i++){
        if(a%i==0 && b%i== 0){
            gcd = i;
        }
    }
    cout << "GCD of " << a << " & " << b << " is : " << gcd << endl;
}

int main(){
    int a,b;
    cout << "Enter the two numbers : ";
    cin >> a >> b;

    findGCD(a, b);

    return 0;
}