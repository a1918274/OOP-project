#include "Dog.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor that initializes Dog with a name and price
Dog::Dog(const string& name, int price) : Item(name, price) {}


// Implementing the pure virtual function to display item details
void Dog::display() const {
    cout << getName() << " (" << getPrice() << " gold)\n";
}


// Implementing the serialize method
void Dog::serialize(std::ofstream& outFile) const {
    outFile << "Dog " << getName() << " " << getPrice() << "\n";
}


// Static method for deserialization
Dog* Dog::deserialize(std::ifstream& inFile) {
    string name;
    int price;
    inFile >> name >> price;
    return new Dog(name, price);
}
