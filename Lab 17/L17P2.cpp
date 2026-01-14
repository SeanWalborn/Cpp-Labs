/*
    Program that creates a static array with ten slots and fills them with random number between 1 and 10. the numbers can repeat. 
    a recursive helper function adds all the integers together and displays to the user
    the progrm asks the user if the want to repeat it 
*/
const int SIZE = 10;

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// declaring helper funciton
int sumArray(int[], int);

int main(){
    // varaibles
    char runAgain = 'y';
    int intArr[SIZE] = {0};
    int sum = 0;

    // setting up for random integers
     srand(time(0));

    while(runAgain == 'y'){

        cout << "Array elements: ";
        // filling array with random numbers and displaying to user 
        for(int i = 0; i < SIZE; i++){
            intArr[i] = (rand() % 10) + 1; // random number 1-10
            cout << intArr[i] << " ";
        }
        cout << endl;
        
        // calling function to sum numbers
        sum = sumArray(intArr, 0);
        
        // displaying sum to user
        cout << "Sum of array elements: " << sum << endl << endl;

        // checking if user wants to run again
        cout << "More (y/n)? ";
        cin >> runAgain;

    }
    
    
}

// defining helper functions
int sumArray(int a[],  int count){
    if (count == SIZE){
        return 0;
    } 

    return(a[count] + sumArray(a, count+1));

}
