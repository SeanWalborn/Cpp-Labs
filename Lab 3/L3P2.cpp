/* 
Lab: 03 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 09/07/25
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Function declarations 
void longestString(ifstream &file, string &longest);


// Main
int main(){
    // Declaring variables used
    string longestStr = "";
        

    // opening text file
    ifstream songFile;
    songFile.open("song.txt");

    // check if file opened
    if (songFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }
        
        
    longestString(songFile, longestStr);

        
    cout << "The longest line: " << longestStr << endl; 
    cout << "The length: " << longestStr.length() << endl;
        
    songFile.close();

}

// function definition

void longestString(ifstream &songFile, string &longest){
    // local var to hold current line
    string currentString = "";

    // getting each ling from the song and checking if its the longest or not 
        while(getline(songFile, currentString)){
            
            if (currentString.length() > longest.length()){
                longest = currentString;
            }
            
        }
}

