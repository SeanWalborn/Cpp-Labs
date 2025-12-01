/* 
    Lab: 21 Problem 01
    Name: Sean Walborn 
    ID: 10763229
    Submission Date: 11/29/25
*/

/*
    - Program that merges two sorted vectors into one new one
    - demonstrates use of vectors
    - input format:
        - first line is size of each vector
        - second line is first vector
        - third line is second vector
        - the vectors elements are all integers
    - must iterators
    - cannot use brackets []
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    // variables used
    string fileName;
    vector <int> v1;
    vector <int> v2;
    vector <int> v3;
    int v1Len = 0;
    int v2Len = 0;

    // collecting user input
    cout << "Enter file name: ";
    cin >> fileName;

    // opening file 
    ifstream vectorFile;
    vectorFile.open(fileName);

    // check if file opened
    if (vectorFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }

    // read first line
    vectorFile >> v1Len >> v2Len;

    // reading second line into vector
    for (int i = 0; i < v1Len; i++){
        int temp = 0;
        vectorFile >> temp;
        v1.push_back(temp);
    }

    // reading third line into vector
    for (int i = 0; i <v2Len; i++ ){
        int temp = 0;
        vectorFile >> temp;
        v2.push_back(temp);
    }

    // setting up iterators
    auto iterV1 = v1.begin();
    auto iterV2 = v2.begin();

    // sorting both arrays into one
    while (iterV1 != v1.end() && iterV2 != v2.end()){
        if (*iterV1 < *iterV2){
            v3.push_back(*iterV1);
            iterV1++;
        }else{
            v3.push_back(*iterV2);
            iterV2++;
        }
    }

    // pushing remaining integers
    while(iterV1 != v1.end()){
        v3.push_back(*iterV1);
        iterV1++;
    }
    while(iterV2 != v2.end()){
        v3.push_back(*iterV2);
        iterV2++;
    }

    // displaying to user
    for (int val:v3){
        cout << val << " ";
    }

}