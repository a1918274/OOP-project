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