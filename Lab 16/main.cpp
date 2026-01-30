/*
    Program thats generates polynomials using a linked list and finds the sum of two polynomials. polynomial, node, and linkedlist are all classes. input is read from two files the polynomial format in the files is "coefficient " "x" "^" "exponent." the two polynomials and their sum are displayed for the user.
*/

#include <iostream>
#include <iomanip>
#include <fstream> 
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

    // collecting file names and creating polynomial
    cout << "Enter file name 1: ";
    cin >> fileName1;
     createPoly(fileName1, poly1);

    cout << "Enter file name 2: ";
    cin >> fileName2;
    createPoly(fileName2, poly2);


    //printing two poly after creation
    cout << "Polynomial 1: " << poly1 << endl;
    cout << "Polynomial 2: " << poly2 << endl;

    // adding two polynomials together and printing sum
    poly3 = poly1 + poly2;
    cout << "Sum: " << poly3;

}

// helper funciton definitions
 // creates a polynomial
void createPoly(string fileName, polynomialList& pList ){
    //variables used
    int coef = 0; // hold coef
    int degree = 0; // holds degree
    node* temp = nullptr; // node used to add to linked list
            
    // opening file
    ifstream polyFile;
    polyFile.open(fileName);

    // check if file opened
    if (polyFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }

    while(polyFile >> coef >> degree){
        temp = new node();
        temp->data.setCoef(coef);
        temp->data.setDegree(degree);
        pList.insertRear(temp);

    }

    
    polyFile.close();
}



