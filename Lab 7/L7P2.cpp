/* 
Lab: 07 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 10/05/25
*/

#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

// declaring helper functions
int findMax(int a[], int length);
void print2Darr(int** a, int size[], int l);

int main(){
    // varaibles used
    string fileName;
    int n = 0;
    int count = 0;

    // getting file name
    cout << "Enter file name : ";
    cin >> fileName;
    cout << endl;

    // opening text file
     ifstream numArrFile;
     numArrFile.open(fileName);

    // check if file opened
    if (numArrFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }
    // reading first line into int
    numArrFile >> n; 

    // dynamically make 2D array from first line and array to hold the size of each sub array
    int** numArray = new int*[n]();
    int* arrSize = new int[n]();

    // creating array of array and fillinf with numbers
    while(!numArrFile.eof()){
        // saving each array size in an array and dynamicly setting the 2D array
        numArrFile >> arrSize[count];
        numArray[count] = new int[arrSize[count]];
        
        // filling the 2d array
        for (int i = 0; i < arrSize[count]; i++){
            numArrFile >> numArray[count][i];
        }
        count++;        
    }

    // print 2D array
    cout<< "< Two-dimenesional array >" << endl;
    print2Darr(numArray, arrSize, n);

    // finidng max and printing
    cout << "< Max value in each line > " << endl;
    for(int i = 0;i < n; i++){
        int max = findMax(numArray[i], arrSize[i]);
        cout << "Max value of line " << i + 1 << ": " << max << endl;
    }

    // dealocating memory
    for (int i = 0; i < n; i++){
        delete[] numArray[i];
    }

    delete[] numArray;
    delete[] arrSize;
    numArrFile.close();
}


//defining helper functions
int findMax(int a[], int length){
    int max = 0;
    for (int i = 0; i < length ;i++){
        if (a[i] > max){
            max = a[i]; 
        }
    }
    return max;
}

void print2Darr(int** a, int b[], int l){
    for (int i = 0; i < l; i++){
        for(int j = 0; j < b[i] ; j++){
            cout << a[i][j] << " " ;
        }
        cout << endl;
    }

    cout << endl;
}