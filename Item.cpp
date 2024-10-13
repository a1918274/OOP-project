#include "Item.h"
#include "Seed.h"
#include "Plant.h"
#include "YoungAnimal.h"
#include "GrownAnimal.h"
#include <fstream>
#include <string>
#include <iostream>

//Constructor
Item::Item(const std::string& n, int p) : name(n), price(p){}; 

//Virtual destructor to properly clean up derived classes
Item::~Item() = default; 

//Getter for item name
std::string Item::getName() const{ return name; };

//Getter for item price
int Item::getPrice() const { return price; };

//Setter for item name
void Item::setName(std::string name){
    name = name;
};

//Setter for item price
void Item::setPrice(int price){
    price = price;
};

//Static method to deserialize an item from a file
Item* Item::deserialize(std::ifstream& inFile) {
    std::string type;
    inFile >> type; // Read the type of item


    std::cout << "Type read: " << type << std::endl; // Debug output


    if (inFile.fail()) {
        std::cerr << "Error reading item type from file.\n";
        return nullptr; // Handle error
    }


    if (type == "Seed") {
        return Seed::deserialize(inFile);
    } else if (type == "Plant") {
        return Plant::deserialize(inFile);
    } else if (type == "YoungAnimal") {
          return YoungAnimal::deserialize(inFile);
    } else if (type == "GrownAnimal") {
        return GrownAnimal::deserialize(inFile);
    }

    std::cerr << "Unknown item type: " << type << "\n"; // Log unknown type
    return nullptr; // Return nullptr for unknown types


};