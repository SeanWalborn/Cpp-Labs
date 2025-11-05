/* 
Lab: 16 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 11/04/25
*/

/*
    Program thats generates polynomials using a linked list and finds the sum of two polynomials. polynomial, node, and linkedlist are all classes. input is read from two files the polynomial format in the files is "coefficient " "x" "^" "exponent." the two polynomials and their sum are displayed for the user.
*/

#include <iostream>
#include <iomanip>
#include "node.cpp" // compiler wont use .h
#include "term.cpp" 
#include "polynomialList.cpp"

using namespace std;

// helper function declarations
void createPoly(string, polynomialList& ); // creates a polynomial

int main(){
    polynomialList poly1;
    polynomialList poly2;
    polynomialList poly3;
    string fileName1;
    string fileName2;

    // collecting file names
    cout << "Enter file name 1: ";
    cin >> fileName1;
    cout << "Enter file name 2: ";
    cin >> fileName2;

    // opening files and creating linked lists
    createPoly(fileName1, poly1);
    createPoly(fileName2, poly2);

    //printing two poly after creation
    cout << poly1;
    cout << poly2

    // adding two polynomials together and printing sum
    poly3 = poly1 + poly2;
    cout << poly3;

   



}

// helper funciton definitions
 // creates a polynomial
void createPoly(string fileName, node*& p ){

}


