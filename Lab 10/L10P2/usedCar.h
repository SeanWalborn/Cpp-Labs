// Interface for UsedCar class

#include <iomanip>

using namespace std;

class UsedCar {
    public: 
        // constructors
        UsedCar();
        UsedCar(string, string, int, int);
        
        // setters
        void setMake(string);
        void setModel(string);
        void setYear(int);
        void setPrice(int);
        
        // getters
        string getMake();
        string getModel();
        int getYear();
        int getPrice();

        //operators
        void printVehicle();
       
    private:
        // private variables
        string make;
        string model;
        int year; 
        int price;

};
