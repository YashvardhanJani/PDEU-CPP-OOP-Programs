// Write a C++ program to create a class called Triangle that has private member variables for the lengths of its three sides. Implement member functions to determine if the triangle is equilateral, isosceles or scalene.

#include<bits/stdc++.h>
using namespace std;

class Triangle
{
private:   
    int s1;
    int s2;
    int s3;
   
public:
    Triangle(){
        s1 = 0;
        s2 = 0;
        s3 = 0; 
        cout << "Default Constructor." << endl;
    }
    
    Triangle(int s1, int s2, int s3){
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        cout << "Parameterized Constuctor" << endl;
    }

    bool isValid(){
        return (s1+s2>s3 && s1+s3>s2 && s2+s3>s1);
    }

    void checkTriangle(int s1, int s2, int s3){
        if(isValid() && s1==s2 && s2==s3 && s3==s1){
            cout << "\nThe triangle is Equilateral.\n";
        }
        else if(isValid() && (s1==s2 || s2==s3 || s3==s1)){
            cout << "\nThe triangle is Isosceles.\n";
        }    
        else if(isValid() && s1!=s2 && s2!=s3 && s3!=s1){
            cout << "\nThe triangle is Scalene.\n";
        }
        else {
            cout << "\nThe given sides do not form a valid triangle.\n";
        }
    }
    
};

int main()
{
    int s1,s2,s3;
    cout << "Enter value of all three sides: ";
    cin >> s1 >> s2 >> s3;

    Triangle t1(s1, s2, s3);
    t1.checkTriangle(s1,s2,s3);

    return 0;
}