#ifndef SEED_H
#define SEED_H

#include "Item.h"
#include <fstream>  // for read/write files
#include <string>

using namespace std;

// This class contains information about the seed of a type of plant the player
// can grow, including potato, corn and tomato seeds
// This class inherits from item class

// Forward declaration of the Plant class
class Plant;

// Class representing a seed that can be bought and grown into a plant
class Seed : public Item {
public:
    // Constructor
    Seed(const std::string& n, int price);  // Initializes a Seed object with a name and price

    // Methods
    void display() const override;          // Displays the seed's details (name and price)
    Plant* grow() const;                    // Grows the seed into a Plant
    std::string getPlantType() const;       // Returns the type of plant the seed grows into

    // Serialization
    void serialize(std::ofstream& outFile) const override;   // Serializes the seed to a file (for saving)
    static Seed* deserialize(std::ifstream& inFile);         // Deserializes a seed from a file (for loading)
};

#endif // SEED_H