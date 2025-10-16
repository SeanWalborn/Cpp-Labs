/* 
Lab: 03 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/07/25
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function declarations 
bool checkArray(int[], int);
void printArray(int[], int);


// Main
int main(){
    // Declaring variables used
     string runAgain = "y"; 

    // while loop to run program mutiple times
    while (runAgain == "y"){
        // variables that reset when program is run again
        int numArr [5] = {0};
        int userInput;
        int count = 1;
        int index = 0;
        
        

        // loop that collect user input until array is full        
        while(numArr[4] == 0 ){
            // collecting input
            cout << "Enter " << count << "th number : ";
            cin >> userInput;

            // check if input was already used
            if (checkArray(numArr, userInput)){
                numArr[index] = userInput;
                index ++;
            }

            //sorting arr
            sort(numArr, numArr + index);

            // printing most updated array
            printArray(numArr, 5);

            // incrementing count
            count++;
        }
        
        cout << "Run Again? [y/n]";
        cin >> runAgain;

    }
}

// function definition

void printArray(int array1[], int length){

    int arrayLength = length;

    for(int i = 0; i < arrayLength; i++){
        cout << array1[i] << " ";
    }
    cout << endl;
}

bool checkArray(int checkArr[], int userInput){
    // loop that checks each index for a  match
    for (int i = 0; i < 5; i++){
        if (checkArr[i] == userInput){
            return false;
        }
    }

    // returns true if no matches
    return true;
}
