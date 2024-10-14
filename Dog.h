#ifndef DOG_H
#define DOG_H

#include "Item.h"
#include <string>
#include <fstream>

//This class contains the Dog item, which the user can purchase 
// from the shop (which effectively ends the game).

class Dog : public Item {
public:
    // Constructor to initialize Dog with a name and price
    Dog(const std::string& name, int price);

    // Implementing pure virtual function to display item details
    void display() const override;

    // Implementing the serialize method
    void serialize(std::ofstream& outFile) const override;

    // Static method for deserialization
    static Dog* deserialize(std::ifstream& inFile);
};

#endif // DOG_H