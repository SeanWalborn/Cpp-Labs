/* 
Lab: 02 Problem 03 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/05/25
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Function declarations 
void fileToArray(ifstream &file, int[]);
void printArray(int[], int);
void filterArr(int[], int[],int, int&);


// Main
int main(){
    // Declaring variables used
    int numListArr [20] = {0};
    int filteredArr [20] = {0}; 
    int count = 0;
    int arrayLength = 20;

    // opening text file
     ifstream numbersFile;
     numbersFile.open("list.txt");

    // check if file opened
    if (numbersFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }

    //pushing numbers in list to array
    fileToArray(numbersFile, numListArr);
    
    // filtering numbers
    filterArr(numListArr,filteredArr, arrayLength, count);

    // creating array without 0s from filtered array increment count 1 to have correct num indexes
    count++;
    int finalFilteredArr [count] = {0};

    // filling array without 0s for printing
    for (int i = 0; i < count; i++){
        finalFilteredArr[i] = filteredArr [i];
    }

    //printing array
    printArray(finalFilteredArr, count);

    // close file
    numbersFile.close();
    
}

// function definition
void fileToArray(ifstream &file, int filesArray[]){

    // counter to move array index
    int counter = 0; 

    // collects input from file and stores in array
    while (!file.eof()){
        file >> filesArray[counter];
        counter ++;
    }

}

void printArray(int array1[], int length){

    int arrayLength = length;
    cout << "output:  ";

    for(int i = 0; i < arrayLength; i++){
        cout << array1[i] << " ";
    }
    cout << endl;
}

void filterArr(int startArr[], int endArr[], int length, int& count){
    // first number in start arr to end arr before looping
    endArr[0] = startArr[0];

    // loop through starting array check num and push to new array if greater
    for (int i = 1; i < length; i++){
        if (startArr[i] > endArr[count]){
            endArr[count+1] = startArr[i];
            count++; 
        }
    }

}