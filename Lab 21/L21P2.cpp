/* 
    Lab: 21 Problem 02 
    Name: Sean Walborn 
    ID: 10763229
    Submission Date: 11/29/25
*/

/*
    - Program that determines how many pairs match formula ai + aj = x(1 <= i < j <= N)
    - demonstrates use of vectors and pairs
    - input format:
        - first line is the number of input in line 2: (N)
        - second line is a sequence of numbers: a1, a2, a3, .... aN
        - third line is a positive integer: (x)
        - the vectors elements are all integers
    - can use iterators or brackets
    - must use 'pair'
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // variables used
    string fileName;
    vector <int> v1;
    vector <pair<int, int>> v2;
    int xValue = 0;
    int len = 0;
    int pairNum = 0;


    // collecting user input
    cout << "Enter file name: ";
    cin >> fileName;

    // opening file
    ifstream pairFile;
    pairFile.open(fileName);

    // check if file opened
    if (pairFile.fail()){
        cout << "file error " << endl;
        exit(1);
    }

    // read first line
    pairFile >> len;

    // reading second line and building vector
    for (int i = 0; i < len; i++){
        int temp;
        pairFile >> temp;
        v1.push_back(temp);
    }

    // saving x value
    pairFile >> xValue;

    // setting up iterator
    auto iter = v1;

    // find pairs
    for(int i = 0; i < v1.size(); i++){
        for(int j = i + 1; j < v1.size(); j++ ){
            // creating pairs
            pair<int, int> p = make_pair(v1[i], v1[j]);
            // checking if pair equals x value
            if (p.first + p.second == xValue){
                // saving pair and incrementing count
                pairNum++;
                // ordering pairs
                if (p.first > p.second){
                    int temp = p.first;
                    p.first = p.second;
                    p.second = temp;
                }
                v2.push_back(p);
            }
        }
    }

    // sorting v2
    sort(v2.begin(), v2.end());



    // displaying pairs
    if (pairNum == 0){
        cout << "\nThere are no pairs that make the number " << xValue ;
    }else{
        cout << endl << pairNum << " Pairs that make the number " << xValue << " >\n";
        for (int i = 0; i < v2.size(); i++){
            cout << "(" << v2[i].first << ", " << v2[i].second << ")\n";
        }
    }
}