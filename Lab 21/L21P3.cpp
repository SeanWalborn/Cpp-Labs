/* 
    Lab: 21 Problem 03
    Name: Sean Walborn 
    ID: 10763229
    Submission Date: 11/29/25
*/


/*
    - Program that keeps tracks of how many employees are present in the building
    - Process a file that has a log of empolyees entering and exiting a building
    - must pick appropriate data structure for processing
    - justify choice with time complexity 
        - using set due to o(log n) time complexity and auto sorting
*/

#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    // variables
    string fileName, name, status;
    set<string> inBuilding;


    // collecting fileName
    cout << "Enter file name: ";
    cin >> fileName;

    // opening file
    ifstream nameFile;
    nameFile.open(fileName);

    if (nameFile.fail()){
        cout << "file error\n";
        exit(1);
    }

    // checking each log
    while (nameFile >> name >> status){
        if (status == "enter"){
            inBuilding.insert(name);
        }else if (status == "leave"){
            inBuilding.erase(name);
        }
    }

    // Displaying user results
    cout << endl << inBuilding.size() << " people are in the company now.\n";

    // displaying names
    for (string names : inBuilding){
        cout << names << endl;
    }
}