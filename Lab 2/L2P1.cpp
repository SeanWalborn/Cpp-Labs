

#include <iostream>
#include <cmath>
using namespace std;

// Function declarations 
int collectInput(int& num);
bool checkPrime(int num);

// Main
int main(){
    // Declaring variables 
     string runAgain = "y"; 

    // while loop to run program mutiple times
    while (runAgain == "y"){
        // variable to store user input
        int userInt;
        // input
        collectInput(userInt);
        
        // checking if number is pos and prime
        if (userInt <= 0 ){
            cout << "Please enter a positive integer." << endl;
        } else if (checkPrime(userInt)){
            cout << userInt << " is a prime number" << endl;
        } else {
            cout << userInt << " is not a prime number." <<endl;
        }

        cout << "More? (y/n)";
        cin >> runAgain;

    }
}

// function definition
int collectInput(int& userInput){
    cout << "Enter a positive integer: ";
    cin >> userInput;
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
