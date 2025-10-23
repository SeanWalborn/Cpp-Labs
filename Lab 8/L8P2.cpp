/* 
Lab: 08 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 10/05/25
*/

#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

// structs and declaring helper functio
struct Polynomial{
    int coef;
    int exp;
    
};
struct DynArr{
    int length;
    Polynomial* polyArr;
};
DynArr createArray ();
DynArr addPoly(DynArr a, DynArr b);
void printPoly(DynArr a);


int main(){
    // creating polynomial arrays inside dynArr structures
    DynArr arrA = createArray();
    DynArr arrB = createArray();

    // adding polynomials
    DynArr arrC = addPoly(arrA, arrB);

    // printing polynomials
    cout << endl << "A = "; 
    printPoly(arrA);
    cout << "B = ";
    printPoly(arrB);
    cout << "C = ";
    printPoly(arrC);


    delete[] arrA.polyArr;
    delete[] arrB.polyArr;
    delete[] arrC.polyArr;
}

// defining helper functions
DynArr createArray (){
    string fileName;
    int arrLen = 0;

    //collect file name
    cout << "Enter file name: ";
    cin >> fileName; 
    

    // opening text file
    ifstream polyFile;
    polyFile.open(fileName);

    // check if file opened
    if (polyFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }

    // setting up array
    polyFile >> arrLen;
    Polynomial* polyArr = new Polynomial[arrLen]();
    
    // filling Pollynomial
    for (int i = 0; i < arrLen; i++){
        polyFile >> polyArr[i].coef;
        polyFile >> polyArr[i].exp;
    }
    
    // building dynArr type for return
    DynArr newArr = {arrLen, polyArr};

    // closing file any returning arr
    polyFile.close();
    return newArr ;

}

DynArr addPoly(DynArr a, DynArr b){
    // setting up polynomial
    int len = a.length + b.length;
    Polynomial* arrC = new Polynomial[len]();
    int count = 0;
    int j = 0;
    int i = 0;

    
    while( i < a.length && j < b.length){
        if(a.polyArr[i].exp == b.polyArr[j].exp){
            arrC[count].coef = a.polyArr[i].coef + b.polyArr[j].coef;
            arrC[count].exp = a.polyArr[i].exp;
            i++;
            j++;
            count ++;
        }else if (a.polyArr[i].exp > b.polyArr[j].exp){
            arrC[count].coef = a.polyArr[i].coef;
            arrC[count].exp = a.polyArr[i].exp;
            count++;
            i++;
        }else if(a.polyArr[i].exp < b.polyArr[j].exp){
            arrC[count].coef = b.polyArr[j].coef;
            arrC[count].exp = b.polyArr[j].exp;
            count++;
            j++;
        }
    }

    // checking for remaining variables
    for (int k = j; k < b.length; k++){
        arrC[count].coef = b.polyArr[k].coef;
        arrC[count].exp = b.polyArr[k].exp;
        count++;
    }
    for (int k = i; k < a.length; k++){
        arrC[count].coef = a.polyArr[k].coef;
        arrC[count].exp = a.polyArr[k].exp;
        count++;
    }
    
    // creating and returning DynArr structure
    DynArr C = {count, arrC};
    return C;

}

void printPoly(DynArr a){
    int len = a.length;

    // print first var
    cout << a.polyArr[0].coef << "x^" << a.polyArr[0].exp;

    for (int i = 1; i < len; i++){
        if (a.polyArr[i].exp == 0 ){
            if (a.polyArr[i].coef >0){
                cout << " +" << a.polyArr[i].coef;
            } else {
                cout << " " << a.polyArr[i].coef;
            }
        }else if (a.polyArr[i].coef >0){
            cout << " +" << a.polyArr[i].coef << "x^" << a.polyArr[i].exp;
        }else {
            cout << " " << a.polyArr[i].coef << "x^" << a.polyArr[i].exp;
        }
    }

    cout << endl;
    
}