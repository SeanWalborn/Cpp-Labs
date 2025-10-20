/* 
Lab: 05 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/09/25
*/

#include <iostream>
#include <iomanip>
#include <ctime>


using namespace std;
const int N = 10;

// Fill the array A with all distinct numbers between 1 and 15
void fillArray(int A[])
{
    // loop that goes through each element of the array and places a random number 
    for (int i = 0; i < N;){
     // temp var for duplicates
        bool duplicate = false;
        A[i] = rand() % 15 + 1;
        // checking for repeats 
        for (int j = 0; j < i; j++){
            if (A[j] == A[i]){
                duplicate = true;
                break;
            }
        }
        // incremnent only if no duplicates
        if (!duplicate){
            i++;
        }
    }
}

// Print the array
void printArray(int A[])
{
    for (int i = 0; i < N; i++)
    cout << setw(3) << A[i];
    cout << endl;
}

// Shift array A to the left by n positions
void shiftArray(int A[], int n)
{
      
    // loop that runs shift as many times as prompted by n
    for (int i = 0; i < n; i++){

        // var to hold int being shifted until end
        int currentInt = A[0];

        // loop to shift each variable over one space
        for(int j = 0; j < N - 1 ; j++){
            A[j] = A[j+1];
        }

        // places first int in the last spot of array
        A[N-1] = currentInt;
    }
    
}

// Do not modify main function
int main()
{
    int A[N] = { 0 };
    srand(time(NULL));
    fillArray(A);
    cout << " < Original Array >" << endl;
    cout << "-------------------------------" << endl;
    printArray(A);
    int n;
    cout << "\nEnter the number of shifts : ";
    cin >> n;
    shiftArray(A, n);
    cout << "\n < Shifted Array >" << endl;
    cout << "-------------------------------" << endl;
    printArray(A);
    return 0;
}