#include "Item.h"
#include <fstream>
#include <string>
#include <iostream>

//Constructor
Item::Item(const std::string& n, int p) : name(n), price(p){}; 

//Virtual destructor to properly clean up derived classes
Item::~Item() = default; 

//Getter for item name
std::string Item::getName() const{
    return name;
};

//Getter for item price
int Item::getPrice() const {
    return price;
};

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

};
