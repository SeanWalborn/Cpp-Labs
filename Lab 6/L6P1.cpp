
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;

// global variable for length of array
const int LEN = 10;
int main(){
    // varaibles used
    int A[LEN] = {0};
    int size = 0;
    int count = 0;

    // setting up rand num generator
    srand(time(NULL));

    // filling array with random distinct number
    for (int i = 0; i < LEN;){
        // temp var for duplicates
        bool duplicate = false;
        A[i] = rand() % 20 + 1;
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
    cout << "< Original Array >" << endl; 
    for(int i = 0; i < LEN; i++){
        cout << setw(3) << A[i];
    }
    cout<< endl << endl;

    // collecting input 
    cout<< "Enter size for reversing (1-10) : ";
    cin >> size;
    cout<< endl;


    // setting up count and size to manipulate indexes
    count = size - 1;
    size = size / 2;

    // reversing array based on size enters
    for (int i = 0; i < size; i++){
        // temp var for switching
        int temp = A[i];
        A[i] = A[count]; 
        A[count] = temp;
        count --;
    }

    // printing same array updated
    cout << "< After reversing > " << endl;
    for (int i = 0; i < LEN; i++){
        cout<< setw(3) << A[i]; 
    }


}


