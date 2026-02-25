

#include <iomanip>
#include <iostream> 
#include <algorithm>

using namespace std;

// Function declarations:
void printArray(int[], int);
int numComElements(int[], int, int[], int);
void commonElements(int[], int, int[], int, int[]);

// Main
int main(){
    // var for tesing and finding size
    int A[] = { 10, 20, 30};
    int B[] = { 10 };
    int C[] = { 1, 4, 7, 10, 20, 30 };
    int comNum1Len = 0;
    int finComNumLen = 0;
    int aLen = sizeof(A)/ sizeof(A[0]); 
    int bLen = sizeof(B)/ sizeof(B[0]); 
    int cLen = sizeof(C)/ sizeof(C[0]);

    // Sorting Arrays
    sort(A, A + aLen);
    sort(B, B + bLen);
    sort(C, C + cLen);

    // generating array to store common elements of A and B
    comNum1Len = numComElements(A, aLen, B, bLen);
    int comNum1[comNum1Len] = {0};

    // finding common elements in first two arrays
    commonElements(A, aLen, B, bLen, comNum1);

    // generating array to store the common ints of comNum1 array and C
    finComNumLen = numComElements(comNum1, comNum1Len, C, cLen);
    int finalComNum[finComNumLen] = {0};

    // finding common elements in comNum1 and C
    commonElements(comNum1, comNum1Len, C, cLen, finalComNum);

    // printing arrays
    cout << "< Original arrays >" << endl;
    cout << "-----------------------" << endl;
    cout << "A: "; 
    printArray(A, aLen);
    cout << "B: ";
    printArray(B, bLen);
    cout << "C: ";
    printArray(C, cLen);
    cout << endl;

    //printing common elements
    cout << "Common elements : "; 
    printArray(finalComNum, finComNumLen);
    
}

// Function definitions:

// Print the array
void printArray(int A[], int length)
{  
    for (int i = 0; i < length; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

// finding the num of common elements in two arrays
int numComElements(int A[], int aLen, int B[], int bLen){
    
    int numComm = 0;

    // loops through both arrays and counts matches
    for (int i = 0; i < aLen; i++){
        for (int j = 0; j < bLen; j++){
            if(A[i] == B[j]){
                numComm ++;
                break;
            }
        }
    }

    return numComm;
}

// finding common elements of two array
void commonElements(int A[], int aLen, int B[], int bLen, int C[] ){
    int count = 0;

    // loops through both arrays and pushes matches to refrence arr
    for (int i = 0; i < aLen; i++){
        for (int j = 0; j < bLen; j++){
            if(A[i] == B[j]){
                C[count] = A[i];
                count++;
                break;
            }
        }
    }
    

}
