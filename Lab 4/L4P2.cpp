/* 
Lab: 04 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/07/25
*/

#include <iostream>
using namespace std;

// function declarations
void printArray(int[]);
void rearrangeArray(int[]);

int main()
{
    // pick which array to use
    //int A[10] = {-2,-5,8,7,9,3,4,2,1,-7};
    int A[10] = {8,-5,-4,2,9,10,-1,-7,1,6};
    cout << " Original Data" << endl;
    cout << "-----------------------" << endl;
    printArray(A);
    rearrangeArray(A);
    cout << "\n Result Data" << endl;
    cout << "-----------------------" << endl;
    printArray(A);
    return 0;
}

// function definitions
void printArray(int numArr[]){
    
    int arrayLength = 10;

    for(int i = 0; i < arrayLength; i++){
        cout << numArr[i] << " ";
    }
    cout << endl;
}

void rearrangeArray(int numArr[]){
    // var to hold pos and neg numbers
    int posArr[10] = {0};
    int negArr[10] = {0};
    int negIndex = 0;
    int posIndex = 0;

    // loop to sort all numbers into pos and neg array
    for (int i = 0; i < 10; i++){
        // push num to arr depending on pos or neg
        if (numArr[i]< 0 ){
            negArr[negIndex] = numArr[i];
            negIndex++;
        }
        else{
            posArr[posIndex] = numArr[i];
            posIndex++;
        }
    }

    // pushing neg numbers back to starting array at the end of the array
    while(negIndex >= 0 ){
        numArr[negIndex + posIndex] = negArr[negIndex];
        negIndex--;
    }

    posIndex--;
    // pushing pos number back to starting array
    while (posIndex >= 0){
        numArr[posIndex] = posArr[posIndex];
        posIndex--;
    }

    
}