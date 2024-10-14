#ifndef DOG_H
#define DOG_H

#include "Item.h"
#include <string>
#include <fstream>

//This class contains the Dog item, which the user can purchase 
// from the shop (which effectively ends the game).

class Dog : public Item {
public:
    // Constructor
    Dog(const std::string& name, int price);                // Initializes a dog object with a name and price

    // Methods
    void display() const override;                          // Displays item details

    // Serialization
    void serialize(std::ofstream& outFile) const override;  // Serializes the dog object
    static Dog* deserialize(std::ifstream& inFile);         // Deserializes a dog object
};

#endif // DOG_H