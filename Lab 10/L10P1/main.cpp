/* 
Lab: 10 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 9/28/25
*/


#include "complex.cpp" // compiler wont let me use .h
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    // variables for collecting input
    double real, imaginary;

    // collecting user input for c1
    cout << "Enter real and imaginary number for c1 : " ;
    cin >> real >> imaginary; 

    // creating c1
    Complex c1(real,imaginary);

    // collecting user input for c1
    cout << "Enter real and imaginart number for c2 : ";
    cin >> real >> imaginary;
    cout << endl;

    // creating c2
    Complex c2(real,imaginary);

    // printing both
    cout << "c1 = ";
    c1.print();
    cout << "c2 = ";
    c2.print();
    cout << endl;

    // manipulating data
    Complex c3 = c1.add(c2);
    Complex c4 = c1.subtract(c2);
    Complex c5 = c1.multiply(c2);

    cout << "Sum" << setw(15) << ":";
    c3.print();
    cout << "Subtraction" << setw(7) << ":";
    c4.print();
    cout << "Multiplication" << setw(4) << ":";
    c5.print();



}