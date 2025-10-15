/* 
Lab: 01 Problem 3 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/04/2025
*/

#include <iostream>
#include <random>
using namespace std;

// Function declarations 
void fillArray(int array1[], int length);
void sortArray(int array1[], int lenght);
void printArray(int array1[], int length);


// Main
int main(){
    // Declaring variables used
     string runAgain = "y";
     int arrayLength = 10; 
     int numArray[arrayLength] = {0};
     

    // while loop to run program mutiple times
    while (runAgain == "y"){
        
        // calling functions to fill the array, sort it then print it 
        fillArray(numArray, arrayLength);
        sortArray(numArray, arrayLength);
        printArray(numArray, arrayLength);
    

        // prompting user to run again
        cout << "more? (y/n)";
        cin >> runAgain;

    }
}

// function definitions
void fillArray(int array1[], int length){
    // prompt user for numbers
    cout << "Enter " << length << " Numbers from 1 to 15: ";

    // store numbers in array
    for (int i = 0; i < length; i++){
       cin >> array1[i];
    }
}

void sortArray(int array1[], int length){

    // sorting array numerically 
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){

            // Temp Vars to hold index places and index values
            int index1 = j;
            int index2 = index1 + 1;
            int currentIndex = array1[index1];
            int nextIndex = array1[index2];


            // compares vlaues and switches if larger number is in front 
            if (currentIndex > nextIndex){
                array1[index1]= nextIndex;
                array1[index2] = currentIndex;
            }
            
        }
        
    }

}

void printArray(int array1[], int length){
    int arrayLength = length;
    for(int i = 0; i < arrayLength; i++){
        cout << array1[i] << " ";
    }
    cout << endl;
}