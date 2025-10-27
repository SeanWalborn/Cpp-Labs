// implementation of UsedCar class

#include <iomanip>
#include <iostream>
#include "usedCar.h"

using namespace std;

// constructors
UsedCar::UsedCar() : make("unkown"), model("unkown"), year(0), price(0) {}
UsedCar::UsedCar(string ma, string mod, int y, int p): make(ma), model(mod), year(y), price(p) {}

// setters
void UsedCar::setMake(string ma){
    make = ma;
}
void UsedCar::setModel(string mod){
    model = mod;
}
void UsedCar::setYear(int y){
    year = y;
}
void UsedCar::setPrice(int p){
    price = p;
}

// getters
string UsedCar::getMake() {
    return make;
}
string UsedCar::getModel(){
    return model;
}
int UsedCar::getYear(){
    return year;
}
int UsedCar::getPrice(){
    return price;
}

//operators
void UsedCar::printVehicle(){
    cout << setw(10) << make << setw(10) << model << setw(5) << year << setw(6) << price << endl;
}

  

