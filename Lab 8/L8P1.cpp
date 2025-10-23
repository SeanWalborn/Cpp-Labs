/* 
Lab: 08 Problem 01 
Name: Sean Walborn 
ID: 10763229
Submission Date: 10/05/25
*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// declaring helper funciton
struct Student{
    string name;
    int id;
    int score;
};
void printStudent(Student s);


int main(){
    // variables used
    string fileName;
    int arrLength = 0;
    int count = 0;
    int highScoreIndex = 0;
    int highScore = 0;


    //collect file name
    cout << "Enter file name: ";
    cin >> fileName; 
    cout << endl;


    // opening text file
     ifstream studentFile;
     studentFile.open(fileName);

    // check if file opened
    if (studentFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }

    // prepping output
    cout << setw(19) << "Students List" << endl;
    cout << string(25, '-') << endl;

    // setting up array of students
    studentFile >> arrLength;
    Student* studentArray = new Student[arrLength]();

    // filling array of students
    while (!studentFile.eof()){
        
        // filling student array from file
        studentFile >> studentArray[count].id;
        studentFile >> studentArray[count].name;
        studentFile >> studentArray[count].score;

        // checking for high score
        if (studentArray[count].score > highScore){
            highScore = studentArray[count].score;
            highScoreIndex = count;
        }

        printStudent(studentArray[count]);

        count++;
    }
    
    // printing max scors and students with score
    cout << endl << "*** Max score : " << highScore << endl << endl;
    cout << "Students with max score" << endl << string(25, '-') << endl;

    // finding and print high score students
    for (int i = 0; i < arrLength; i++){
        if (studentArray[i].score == highScore){
            printStudent(studentArray[i]);
        }
    }

    // dealocating memory
    delete [] studentArray;
    studentFile.close();
}

// Defining helper function
void printStudent(Student s){
    cout << s.id << setw(10) << s.name << setw(5) << s.score << endl;
}


