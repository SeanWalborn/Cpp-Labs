

#include <iomanip>
#include <iostream>
#include <algorithm> 

using namespace std;

// Function declarations:
void printArray(int[], int);
int numComElements(int[], int, int[], int, int [], int);
void commonElements(int[], int, int[], int, int[], int, int []);

// main
int main(){
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int B[] = { 2, 5, 6, 10, 11, 13, 17, 18, 19 };
    int C[] = { 3, 5, 7, 8, 11, 18, 20 };
    int abLen = 0;
    int bcLen = 0;
    int acLen = 0;
    int aLen = sizeof(A)/ sizeof(A[0]); 
    int bLen = sizeof(B)/ sizeof(B[0]); 
    int cLen = sizeof(C)/ sizeof(C[0]);

    // Sorting Arrays
    sort(A, A + aLen);
    sort(B, B + bLen);
    sort(C, C + cLen);

    // finding length and creating arrays for common numbers of ab, bc, ac 
    abLen = numComElements(A, aLen, B, bLen, C, cLen);
    bcLen = numComElements(B, bLen, C, cLen, A, aLen);
    acLen = numComElements(A, aLen, C, cLen, B, bLen);
    int abCommon [abLen] = {0};
    int bcCommon [bcLen] = {0};
    int acCommon [acLen] = {0};

    // filling common arrays
    commonElements(A, aLen, B, bLen, C, cLen, abCommon);
    commonElements(B, bLen, C, cLen, A, aLen, bcCommon);
    commonElements(A, aLen, C, cLen, B, bLen, acCommon);

    

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

    cout << "Numbers in A and B, not C : ";
    printArray(abCommon, abLen);
    cout << "Numbers in A and C, not B : "; 
    printArray(acCommon, acLen);
    cout << "Numbers in B and C, not A : "; 
    printArray(bcCommon, bcLen);


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
int numComElements(int A[], int aLen, int B[], int bLen, int C[], int cLen){
    
    int numComm = 0;

    // loops through first array
    for (int i = 0; i < aLen; i++){
        // loops thorugh second arr
        for (int j = 0; j < bLen; j++){
            // checks for matches
            if(A[i] == B[j]){
                // bool to check if match for arr 1 and 2 is in third array
                bool tripleCommonNum = false;
                // loops through third array
                for(int k = 0; k < cLen; k++){
                   if (B[j] == C[k]){
                        tripleCommonNum = true;
                        break;
                   } 
                }
                // increments count only if number match in first two arrays and not in third
                if(!tripleCommonNum){
                    numComm ++;
                    break;
                }
            }
        }
    }

    return numComm;
}

// finding common elements of two array
void commonElements(int A[], int aLen, int B[], int bLen, int C[], int cLen, int result[] ){
    int count = 0;

    // loops through first array
    for (int i = 0; i < aLen; i++){
        //loops though second array
        for (int j = 0; j < bLen; j++){
            // checks for matches in first two arrays
            if(A[i] == B[j]){
                // bool to check if match for arr 1 and 2 is in third array
                bool tripleCommonNum = false;
                // loops through third array
                for(int k = 0; k < cLen; k++){
                   if (B[j] == C[k]){
                        tripleCommonNum = true;
                        break;
                   } 
                }

                // only moves number to new array if in first two arrays but not in the third
                if (!tripleCommonNum){
                result[count] = A[i];
                count++;
                break;
                }
            }
        }
    }
    
}

