#include "Dog.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor that initializes Dog with a name and price
Dog::Dog(const string& name, int price) : Item(name, price, 1) {}


// Implementing the pure virtual function to display item details
void Dog::display() const {
     cout << "[ " << getItemCount() << "x ] "
         << "Dog: " << getName()
         << " (" << getPrice() << " gold)\n";
}



// Implementing the serialize method
void Dog::serialize(std::ofstream& outFile) const {
    outFile << "Dog " << getName() << " " << getPrice()
            << " " << getItemCount() << "\n"; // Use getter for item count
}



// Static method for deserialization
Dog* Dog::deserialize(std::ifstream& inFile) {
    string name;
    int price, count;
    
    // Error checking while reading from file
    if (!(inFile >> name >> price >> count)) {
        cerr << "Error reading dog data from file." << endl;
        return nullptr; // Return nullptr if reading fails
    }


    Dog* dog = new Dog(name, price);
    dog->setItemCount(count); // Set the item count after deserialization using setter
    return dog;
}

