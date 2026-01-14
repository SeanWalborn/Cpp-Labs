
/*
    Program that evaluates a polynomial using horner's rule. the program collects the file name and value for x from the user, then uses recursion to evaluate the polynomials.
    The first line of the file represents how many polynomials there are. the subsequect lines each contain one polynomial in the following format: the line only has the coefficients, and the number of coefficients indicates the polynomials degree.
        ex: 2.5 4.1 5.0  = 2.5x^2 + 4.1x^1 + 5.0x^0
    
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// declaring helper functions 
int makeCoefArr(stringstream&, double*&);
double evalPoly(double*, int, double);

int main(){
    // variables used
    string fileName;  
    double xValue = 0;
    double evaluation = 0;
    double* coefArr= nullptr;
    int count = 0 ; // controls array size for recursion
    int numPoly = 0; // determines how many polynomials are present
    string nextLine; // used to read each line in the file
    
    // collecting user input and displaying x value
    cout << "Enter file name: ";
    cin >> fileName;
    cout << "Enter value for x: ";
    cin >> xValue;
    cout << " x = " << xValue << endl << endl; 

    // formating all subsequent numbers to two dec places
    cout << fixed << setprecision(2);

    // opening file
    ifstream polyFile;
    polyFile.open(fileName);

    // check if file opened
    if (polyFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }

    // priming loop for number of runs base on the number of polynomials
    polyFile >> numPoly;
    getline(polyFile, nextLine); // shift to next line to read file properly

    // running loop to access each polynomial and evaluate
    for (int i = 0; i < numPoly; i++){
        cout << "Polynomial " << i + 1 << ": ";
        getline(polyFile, nextLine);
        stringstream ss(nextLine); // used to feed the coef function
        count = makeCoefArr(ss, coefArr); // makes double and gets size of array created 
        evaluation = evalPoly(coefArr, count, xValue); // evaluating polynomial
        cout << "P(" << xValue << ") = " << evaluation << endl; // display results of evaluation  
        
        // recovering memory
        delete[] coefArr;
        coefArr = nullptr;
    }

}

// defining helper function
// makes a double funciton of the coefficients and returns the array size fills the new arr in reverse order for use in evaluation function
int makeCoefArr(stringstream& line, double*& a){
    int count = 0;
    double temp = 0;
    a = nullptr;
   
    while(line >> temp){
        // creates new sized array
        double* tempArr = new double[count +1]; 

        // moves over old values
        for (int i =0; i < count; i++){
            tempArr[i+1] = a[i];
        }

        // fills first spot with new double
        tempArr[0] = temp;
        
        // displays unit to user and increments count
        cout << tempArr[0] << " ";
        count ++;

        // recovering memory
        delete[] a;
        
        // changes pointer and recovers memory
        a = tempArr;
    }

    cout << endl;

    return count;
}

// evaluates the polynomial
double evalPoly(double* coef, int size, double x){
    if (size == 1){
        return coef[0];
    }

    return (coef[0] + x * evalPoly(coef+1, size-1, x));

}
