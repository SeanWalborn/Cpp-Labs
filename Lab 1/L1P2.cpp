/* 
Lab: 01 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/02/2025
*/

#include <iostream>
using namespace std;

// Function declarations 
void arrayProduct(int array1[]);
void printArray(int array1[]);

//Main
int main(){
    // Declaring variables used
     int arrayA [5] = {0};
     string runAgain = "y"; 

    // while loop to run program mutiple times
    while (runAgain == "y"){
     
        //input- collecting int from user storing in var
        cout << "Enter 5 numbers: " << endl;
        cin >> arrayA[0] >> arrayA[1] >> arrayA[2] >> arrayA[3] >> arrayA[4];

        // prints arrayA
        cout << "A : "; 
        printArray(arrayA);

        //calling function to collect data and compare numbers
        arrayProduct(arrayA);
        
        cout << "Run Again? [y/n]";
        cin >> runAgain;

    }
}

// function definition
void arrayProduct(int array1[]){
    // Variable used in function
    int arrayB [5] = {0};

    // nested for loop that iterates through array1 and gets products of all ints, if statement skips the int at the current index, stores product in arrayB
    for(int i =0; i < 5; i++){
        int product = 1;
        for(int j = 0; j < 5; j++){
            if(j != i){
                product = product * array1[j];
            }
        }
        arrayB[i] = product;
    }

    // printed the updated B array 
    cout << "B : ";
    printArray(arrayB);
}

// function definition
void printArray(int array1[]){
    int arrayLength = 5;
    for(int i = 0; i < arrayLength; i++){
        cout << array1[i] << " ";
    }
    cout << endl;
}