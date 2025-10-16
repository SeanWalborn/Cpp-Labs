/* 
Lab: 02 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/05/25
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// Function declarations 
void fileToArray(ifstream &file, int[]);
void printArray(int[], int);
void sortArray(int[], int);
bool checkPrime(int);


// Main
int main(){
    // Declaring variables used
     int numFiles [30] = {0};
     int counter = 0; // counter for prime array
     int primeNum [30] = {0};

    // opening text file
     ifstream numbersFile;
     numbersFile.open("numbers.txt");

    // check if file opened
    if (numbersFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }
    
    // pushing numbers in file to array 
    fileToArray(numbersFile, numFiles);

    // pushing prime numbers from first array to seperate array
    for (int i = 0; i < 30; i++){
        if (checkPrime(numFiles[i])){
            primeNum[counter] = numFiles[i];
            counter++;
        }
    }
    
    // create arrays with same number of indexs as prime numbers to store sorted/unsorted primes in
    int primeNum2 [counter] = {0};
    int sortedPrimeNum [counter] = {0};

    //push prime nums to arrays one sorted and one unsorted with exact number of indexs
    for (int i = 0; i < counter; i++){
        primeNum2[i] = primeNum[i];
        sortedPrimeNum[i] = primeNum[i];
    }
   
    //sorting prime number
    sortArray(sortedPrimeNum, counter);

    
    // print numbers
    cout << "< Prime numbers in unsorted form >" << endl;
    printArray(primeNum, counter);

    cout << "< Prime numbers in sorted form >" << endl;
    printArray(sortedPrimeNum,counter);
    
    
    // closing file
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

void sortArray(int array1[], int length){

    // sorting array numerically 
    for (int i = 0; i < length -1 ; i++){
        for (int j = 0; j < length - 1 - i; j++){

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
        cout << setw(3) << i << " : " << setw(10) << array1[i] << endl;
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