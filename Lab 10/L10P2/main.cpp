/* 
Lab: 10 Problem 02 
Name: Sean Walborn 
ID: 10763229
Submission Date: 9/28/25
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "usedCar.cpp" // complier wont let me use .h

using namespace std;

// declaring helper functions
void fillArray (ifstream &file, UsedCar*cars);
void printArray(UsedCar*cars, int); 
void sortYearDescending(UsedCar*cars, int);
void sortPriceAscending(UsedCar*cars, int);
void filterCarMake(UsedCar *cars, int, string);


int main(){
    // Declaring variables used
     string runAgain = "y"; 
     string fileName;
     int userChoice;
     string firstLine;
     int arraySize;
     

    // collecting filename from user
     cout << "Enter file name: ";
     cin >> fileName;
     cout << endl << endl;

    // opening text file
     ifstream usedCarFile;
     usedCarFile.open(fileName);

    // check if file opened
    if (usedCarFile.fail()){
        cout << "file error" << endl;
        exit(1);
    }

    // setting up dynamic array reads first line of file to create array size
    getline(usedCarFile, firstLine);
    arraySize = stoi(firstLine);
    UsedCar carList [arraySize];
    
    // Filling array of usedcars with data from file
    fillArray(usedCarFile, carList);
    
    // while loop to run program mutiple times
    while (runAgain == "y"){
        
        // displaying menu options
        cout << "Choose an option:" << endl;
        cout << "1. Display cars by year (descending)" << endl;
        cout << "2. Display cars by price (ascending)" << endl;
        cout << "3. Search cars by manufacturer" << endl << endl ; 
        cout << "*** Enter 1, 2, or 3:";
        cin >> userChoice;

        // input validations and processing input
        if (userChoice < 1 || userChoice > 3){
            cout << "Invalid choice." << endl;
        }else if (userChoice == 1){
            cout << endl << "Cars sorted by year (descending): " << endl;
            // sort cars
            sortYearDescending(carList, arraySize);
            printArray(carList, arraySize);

        }else if (userChoice == 2) {
            cout << endl << "Cars sorted by price (ascending): " << endl;
            // sort cars
            sortPriceAscending(carList, arraySize);
            printArray(carList, arraySize);

        }else {
            string manufacturer;
            cout << "Enter manufacturer name: ";
            cin >> manufacturer;
            cout << endl << "Cars by manufacturer '" << manufacturer << "': " << endl;
            
            //filter by make
            filterCarMake(carList, arraySize, manufacturer);

        }
    
        // prompting to run again
        cout << endl << "*** Choose another option (y/n)?";
        cin >> runAgain;

    }
}

// helper funcitons
void fillArray (ifstream &file, UsedCar *car){
    // var to incrememnt array
    int count = 0;

    // filling array of type usedCar
    while (!file.eof()){
        // temp vars to store file data
        string make,model;
        int price,year;

        // saving data from file to vars
        file >> make >> model >> year >> price;
        
        // saving vars to array of usedcars
        car[count].setMake(make);
        car[count].setModel(model);
        car[count].setYear(year);
        car[count].setPrice(price);

        // incrementing array of used cars s
        count++;

    }
}

void printArray(UsedCar *car, int size){
    for(int i = 0; i < size; i++){
        car[i].printVehicle();
    }
}

void sortYearDescending(UsedCar *car, int size){
    // sorting using nested for loops to compare each elemnt and switch poistions based on compaorisons
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size ; j++){
            if (car[i].getYear() < car[j].getYear()){
                UsedCar tempCar = car[i];
                car[i] = car[j];
                car[j] = tempCar;
            } 
        }
    }
}

void sortPriceAscending(UsedCar *car, int size){
    for (int i = 0; i < size - 1; i++){
            for (int j = i + 1; j < size ; j++){
                if (car[i].getPrice() > car[j].getPrice()){
                    UsedCar tempCar = car[i];
                    car[i] = car[j];
                    car[j] = tempCar;
                } 
            }
        }
}

void filterCarMake(UsedCar *car, int size, string make){
    // loop thorugh array
    for (int i = 0; i < size; i++){
        if (car[i].getMake() == make){
            car[i].printVehicle();
        }
    }
}