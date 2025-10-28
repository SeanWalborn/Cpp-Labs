/* 
Lab: 11 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 10/7/25
*/


#include "complex2.cpp" // compiler wont let me use .h
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    // creating c1 and c2
    Complex c1;
    Complex c2;

    // collecting user input for c1
    cout << "Enter real and imaginary number for c1 : " ;
    cin >> c1;

    // collecting user input for c2
    cout << "Enter real and imaginary number for c2 : ";
    cin >> c2;
    cout << endl;
  

    // printing both
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << endl;

    // declaring complex numbers to holder results
    Complex c3, c4, c5;

    // manipulating data
    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;

    cout << "Sum" << setw(15) << ": " << c3 << endl;
    cout << "Subtraction" << setw(7) << ": " << c4 << endl;
    cout << "Multiplication" << setw(4) << ": " << c5 << endl;
    
}