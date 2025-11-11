/* 
    Lab: 17 Problem 01 
    Name: Sean Walborn 
    ID: 10763229
    Submission Date: 11/09/25
*/

/*
    Program that collects an integer from the user and then uses recursion to calculate the sum of the digits. the input number is alway positive. runs until users ends the program
*/

#include <iomanip>
#include <iostream>

using namespace std;

// helper funciton declaration
int sumInput(int);

int main(){
    // varaibles used
    int userInput = 0;
    char runAgain = 'y';
    int sum;

    while(runAgain == 'y'){

        // collecting input
        cout << "Enter a positive integer: "; 
        cin >> userInput;

        // suming integers
        sum = sumInput(userInput);

        // showing user sum
        cout << "Sum of digits: " << sum << endl << endl;
        
        // checking to run again
        cout<< "More (y/n)? "; 
        cin >> runAgain;

    }

}

// helper funciton definition
// function uses recursion to sum integer numbers
int sumInput(int a){
    // base case stops when a becomes zeros
    if (a == 0){
        return a; 
    } 
    
    // returns the tens place digit plus the sum of the recursion - the recursion cuts off the tens place every time it runs
    return(a%10 + sumInput(a/10));
}