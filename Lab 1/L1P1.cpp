

#include <iostream>
using namespace std;

// Function declarations 
int maxNum(int, int&, int&);


//Main
int main(){
    // Declaring variables used
    int numOfData = 0; 
    int max1 = 0;
    int max2 = 0; 

    //input- collecting int from user storing in var
    cout << "Enter number of data: " << endl;
    cin >> numOfData;

    //calling function to collect data and compare numbers
    maxNum(numOfData, max1, max2);

    //if statment to handle only 1 input - output -returns largest and second largest number
    if(numOfData == 1){
        cout << "Max 1: " << max1 << endl
        << "Max 2: not exist" << endl;
    }
    else {
        cout << "Max 1: " << max1 << endl
        << "Max 2: " << max2 << endl;
    }
}

// function definition
int maxNum(int data, int& max1, int& max2){
    // var to store input
    int numInput;

    // Collecting first number and assigning to max1
    cout << "Enter number 1 : " << endl;
    cin >> numInput;
    max1 = numInput;
    

    // for loop collects subsequent number and compares collects first number
    for (int i = 2; i <= data; i++){
        cout << "Enter number " << i << " : ";
        cin >> numInput;

        // if statement to compare numbers changed max 1 or 2 depending on size
        if (numInput > max1) {
            max2 = max1;
            max1 = numInput;
        }
        else if (numInput > max2){
            max2 = numInput;
        }
    }
}




