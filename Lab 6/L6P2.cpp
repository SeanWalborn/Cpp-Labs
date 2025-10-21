/* 
Lab: 06 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 9/11/25
*/

#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;

// global variable for length of array
const int LEN = 10;

int main(){
    // varaibles used for array and decrementing switch from end to begining of array
    int A[LEN] = {0};
    int decrement = LEN - 1;
    int increment = 0; 
    int frontIndex = true;

    // setting up rand num generator
    srand(time(NULL));


    // filling array with random distinct number between 0 and 99
    for (int i = 0; i < LEN;){
        // temp var for duplicates
        bool duplicate = false;
        A[i] = rand() % 100;

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

    // printing orginal array
    cout << "A:  ";
    for (int i = 0; i < LEN; i++){
        cout << setw(3) << A[i];
    }
    cout << endl << "-----------------------------------" << endl;

    // sorting array bases on guidance
    for (int i = 0; i < LEN; i++){
        // starting number to find largest
        int largestNum = A[increment]; 
        int largestIndex = increment;

        for(int j = increment; j <= decrement; j++ ){
            if (A[j] > largestNum){
                largestNum = A[j];
                largestIndex = j;
            }
        }

        if (frontIndex){
            A[largestIndex] = A[increment];
            A[increment] =  largestNum;
            frontIndex = false;
            increment++;
        }else{
            A[largestIndex] = A[decrement];
            A[decrement] = largestNum;
            frontIndex = true; 
            decrement-- ;
        }
        // printing current array
        cout << setw(2) << i + 1 << ": ";
        for(int k = 0; k < LEN; k++){
            cout << setw(3) << A[k];
        }
        cout << endl;
    }

}
