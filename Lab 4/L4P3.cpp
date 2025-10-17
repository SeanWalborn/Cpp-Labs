/* 
Lab: 04 Problem 03 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/07/25
*/

#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <ctime> 
using namespace std;

// function declarations
void fillArray(int[]);
void removeDuplicate(int[]);
void printArray(int[]);

int main()
{
    srand(time(0)); // sedding random num
    int A[10] = { 0 };
    fillArray(A);
    cout << " Original Data" << endl;
    cout << "--------------------------" << endl;
    printArray(A);
    sort(A, A+10); // Sort the array
    cout << "\n After Sorting" << endl;
    cout << "--------------------------" << endl;
    printArray(A);
    removeDuplicate(A);
    cout << "\n After Removing Duplicate" << endl;
    cout << "-----------------------------" << endl;
    printArray(A);
    return 0;
}
// Add function definitions

void fillArray(int numArr[]){
    // for loop to fill with random num from 1 to 15
    for (int i = 0; i < 10; i++){
        numArr[i] = (rand() % 15) + 1;
    }
}

void removeDuplicate(int numArr[]){
    int length = 10;

    for (int i = 0; i < length; i++){
        for (int j = i + 1; j < length; ){
            if(numArr[i] == numArr[j]){
                // shifting array over
                for (int k = j; k < length -1; k++){
                    numArr[k] = numArr[k+1];
                }
                numArr[length - 1] = 0;
                length--;
            }
            else{
                j++;
            }
        }
    } 
}

void printArray(int numArr[]){
    
    int arrayLength = 10;

    for(int i = 0; i < arrayLength; i++){
        cout << numArr[i] << " ";
    }
    cout << endl;
}