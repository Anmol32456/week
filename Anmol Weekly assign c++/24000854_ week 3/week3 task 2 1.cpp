#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
public:
    string registrationNumber;
    string color;

    void setData(string regNum, string col) {
        registrationNumber = regNum;
        color = col;
    }
};

class Car : public Vehicle {
public:
    int numberOfSeats;

    void setCarData(string regNum, string col, int seats) {
        setData(regNum, col);
        numberOfSeats = seats;
    }

    void writeToFile() {
        ofstream file("car.txt");
        file << "Car Details:\n";
        file << "Registration Number: " << registrationNumber << "\n";
        file << "Color: " << color << "\n";
        file << "Number of Seats: " << numberOfSeats << "\n";
        file.close();
    }
};

class Bike : public Vehicle {
public:
    int engineCapacity;

    void setBikeData(string regNum, string col, int capacity) {
        setData(regNum, col);
        engineCapacity = capacity;
    }

    void writeToFile() {
        ofstream file("bike.txt");
        file << "Bike Details:\n";
        file << "Registration Number: " << registrationNumber << "\n";
        file << "Color: " << color << "\n";
        file << "Engine Capacity: " << engineCapacity << " cc\n";
        file.close();
    }
};

int main() {
    Car c;
    c.setCarData("Tesla", "Red", 5);
    c.writeToFile();

    Bike b;
    b.setBikeData("duke", "Black", 150);
    b.writeToFile();

    return 0;
}

