/* 
    Lab: 20 Problem 01 
    Name: Sean Walborn 
    ID: 10763229
    Submission Date: 11/27/25
*/

/*
    - Program that computes the median of an array
    - demonstartes use of template 
    - works for ints or double arrays of even or odd size
    - char arrays are always odd
    - main function is provided
    - three helper functions are created bubbleSort/findmedian/printArray
*/

#include <iostream>

// declaring helper functions that can handle multiple types
template <class T>
T* bubbleSort(T[], int);
template <class T>
void findMedian(T, int);
template <class T>
void printArray(T, int);

int main(){
    int A[] = { 5, 7, 26, 28, 53, 9, 100, 59, 22 }; // 9 elements
    double B[] = { 56.3, 12.5, 33.8, 24.1, 30.7, 78.3, 22.6, 54.1 }; // 8 elements
    char C[] = { 't', 'a', 'o', 's', 'm', 'p', 'w'}; // 7 elements

    int* Ap = bubbleSort(A, 9);
    double* Bp = bubbleSort(B, 8);
    char* Cp = bubbleSort(C, 7);

    cout << "Sorted array A: "; printArray(Ap, 9);
    cout << "Sorted array B: "; printArray(Bp, 8);
    cout << "Sorted array C: "; printArray(Cp, 7);

    cout << endl;

    int median_A = findMedian(Ap, 9);
    double median_B = findMedian(Bp, 8);
    char median_C = findMedian(Cp, 7);

    cout << "Median of A : " << median_A << endl;
    cout << "Median of B : " << median_B << endl;
    cout << "Median of C : " << median_C << endl;

    return 0;
}

void bubbleSort(){

}
void findMedian(){

};
void printArray(){

};