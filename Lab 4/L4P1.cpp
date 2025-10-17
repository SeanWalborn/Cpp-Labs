/* 
Lab: 04 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/07/25
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


// Function declarations
void fillArray(int array1[], int length); 
void printArray(int[], int);
bool checkPrime(int);



// Main
int main(){
    // Declaring variables used
     string runAgain = "y";
     int arrLength = 10; 
     

    // while loop to run program mutiple times
    while (runAgain == "y"){
        // var to reset after each run
        int inputArr[10] = {0};
        int primeArr[10] = {0};
        int primeIndex = 0;

        // collecting input
        fillArray (inputArr, arrLength);
        
        // finding prime
        for (int i = 0; i < arrLength; i++){
            if (checkPrime(inputArr[i])){
                primeArr[primeIndex] = inputArr[i];
                primeIndex++;
            }
        }

        // sorting prime arr
        sort(primeArr, primeArr + primeIndex);

        // print both arrays with formatting
        cout << "A :  ";
        printArray(inputArr, arrLength);
        cout << "There are " << primeIndex << " prime numbers in A" << endl; 
        cout <<"B : ";
        printArray(primeArr, arrLength);

        // ask to run again
        cout << "Run Again? [y/n]";
        cin >> runAgain;

    }
}

// function definition

void fillArray(int array1[], int length){
    // prompt user for numbers
    cout << "Enter " << length << " Numbers from 1 to 20: ";

    // store numbers in array
    for (int i = 0; i < length; i++){
       cin >> array1[i];
    }
}
    
void printArray(int array1[], int length){

    int arrayLength = length;

    for(int i = 0; i < arrayLength; i++){
        cout << array1[i] << " ";
    }
    cout << endl;
}

bool checkPrime(int userInput){

    // var use to control loop
    int limit = sqrt(userInput);

    // if statement check for num 2 or less 
    if (userInput < 2){
        return false;
    }
    
    // for loop checks all numbers up to square root to confirm prime
    for (int i = 2; i<=limit; i++){
        if (userInput % i == 0 ){
            return false;
        }
    }

    return true;

}