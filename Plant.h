#ifndef PLANT_H
#define PLANT_H

#include"Item.h"
#include<string>
#include<fstream>

//This class contains information about a type of plant the 
//player can grow (potato, corn, or tomato).

class Plant: public Item{
private:
    int sellPrice; // The selling price of the plant


public:
    // Constructor to initialize a Plant object
    Plant(const std::string n, int buyPrice, int sPrice);

    // Displays the plant's name and sell price
    void display() const override;

    // Returns the sell price of the plant
    int getSellPrice() const;

    // Serialize the plant to a file (for saving)
    void serialize(std::ofstream& outFile) const override;

    // Deserialize a plant from a file (for loading)
    static Plant* deserialize(std::ifstream& inFile);
};


#endif // PLANT_H