/* 
Lab: 07 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 10/05/25
*/

#include <iomanip>
#include <iostream>

using namespace std;

// declaring helper funcitons
bool notDuplicate(int a, int length, int b[]);
bool openElement(int a[], int end);
void sortArray(int a, int count, int b[]);
void copyArray(int A[], int l, int B[]);



int main(){
    // variables used
    int n = 0;
    int inputCount = 1;
    int arrayCount = 0;

    

    cout << "Enter the inital size of the array : ";
    cin >> n;

    // creating dynamic variable
    int* numArray = new int[n]();

    // loops unit -1 is entered inside loop
    while(true){
        // local var
        int input;

        cout << "Enter " << inputCount << "th number: ";
        cin >> input;

        // check if program runs
        if (input == -1){
            delete[] numArray;
            return 0;
        }

        // checks for duplicate or adds input to array and sorts
        if(notDuplicate(input, n, numArray)){
            if (openElement(numArray, n)){
                sortArray(input, arrayCount, numArray);
                arrayCount++;
            }else{
                // informing user of array size increase
                cout << endl << "** Need to increase the size **" << endl << endl; 
                // creates new array 
                int* numArray2 = new int[n*2]();
                // copies old array to new array
                copyArray(numArray, n, numArray2);
                // dealocating memory
                delete[] numArray;
                // changing pointer address
                numArray = numArray2;
                // sorting number and incrementing array count
                sortArray(input, arrayCount, numArray);
                arrayCount++;
                // doubling n size as while loop control
                n = n*2;
            }
        }
        //increment count
        inputCount++;

        // printing array
        for(int i = 0; i < n; i++){
            cout << numArray[i] << " ";
        }
        cout << endl;    
    }  
}

// defining helper funcitons
bool openElement(int a[], int end){
    if (a[end - 1] == 0){
        return true;
    }else{
        return false;
    }
}

bool notDuplicate(int input, int length, int a[]){
    // checking for duplicate in array
    for (int i = 0; i < length; i++){
        if (input== a[i]){
            return false;
        }
    }
    return true;

}

void sortArray(int input, int count, int a[]){
    int i;
    for(i = count - 1; i >= 0 && input < a[i]; i--){
            a[i+1] = a[i];
    }
    a[i+1]=input;
}

void copyArray(int a[], int length, int b[]){
    // copy old array to new array
    for (int i = 0; i < length; i++){
        b[i] = a[i];
    }
}