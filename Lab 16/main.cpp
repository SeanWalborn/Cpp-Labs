/* 
Lab: 16 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 11/01/25
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
void createPoly(string, LinkedList& ); // creates a polynomial
void sumPoly(LinkedList, LinkedList, LinkedList&); // sums two polynomials

int main(){
    LinkedList poly1;
    LinkedList poly2;
    LinkedList poly3;
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
    poly1.printList();
    poly2.printList();

    // adding two polynomials together and printing sum
    sumPoly(poly1, poly2, poly3);
    poly3.printList();

   



}

// helper funciton definitions
 // creates a polynomial
void createPoly(string fileName, Node*& p ){

}

// sums polynomial a and b into a new polynomial c
void sumPoly(Node* a, Node* b , Node*& c){

}

