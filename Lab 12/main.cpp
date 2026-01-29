
#include <iostream>
#include <fstream>
#include "polynomial.cpp"

using namespace std;

// helper funcitons
Polynomial openFile(string f);


int main (){
    // variables
    string fileName;
    Polynomial poly1, poly2, poly3, poly4;

    // collecting file name/ opening file/ and setting up polynomials
    cout << "Enter file name 1 : ";
    cin >> fileName;
    poly1 = openFile(fileName);

    cout << "Enter file name 2 : ";
    cin >> fileName; 
    poly2 = openFile(fileName);



    // displaying polynomials
    cout << endl << "Polynomial 1 : " << poly1 << endl;
    cout << "Polynomial 2 : " << poly2 << endl;

    // adding and subtracting polys
    poly3 = poly1 + poly2;
    poly4 = poly1 - poly2;

    // displaying results
    cout << "Addition     : " << poly3 << endl;
    cout << "Subtraction  : " << poly4 << endl;

    // desconstructing everything
    
}

// defining funcitons
Polynomial openFile(string f){
    // Variables
    int deg = 0;

    // opening file
    ifstream polyFile;
    polyFile.open(f);

    // check if file opened
    if (polyFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }

    // setting up dynamic arr to hold input
    polyFile >> deg;
    int* polyArr = new int[deg+1] {0};

    // variables to hold input from file
    int tempCoef;
    int tempExp;

    while(polyFile >> tempCoef >> tempExp){
        polyArr[tempExp] = tempCoef;
    }

    Polynomial p(polyArr, deg);
    
    polyFile.close();
    delete[]polyArr;
    
    return p;


}
