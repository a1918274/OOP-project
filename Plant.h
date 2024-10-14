#ifndef PLANT_H
#define PLANT_H

#include"Item.h"
#include<string>
#include<fstream>

//This class contains information about a type of plant the 
//player can grow (potato, corn, or tomato).

// Class representing a plant that can be sold
class Plant: public Item{
private:
    int sellPrice;  // The selling price of the plant

public:
    // Constructor
    Plant(const std::string n, int buyPrice, int sPrice);   // Initializes a Plant object with a name, buy price, and sell price

    // Methods
    void display() const override;                          // Displays the plant's name and sell price

    // Getters
    int getSellPrice() const;                               // Returns the sell price of the plant

    // Serialization
    void serialize(std::ofstream& outFile) const override;  // Serialize the plant to a file (for saving)
    static Plant* deserialize(std::ifstream& inFile);       // Deserialize a plant from a file (for loading)
};

#endif // PLANT_H