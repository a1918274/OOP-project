#ifndef PLANT_H
#define PLANT_H

#include"Item.h"
#include<string>
#include<fstream>

class Plant: public Item{
    private:
    int sellPrice; // The selling price of the plant


    public:
    // Constructor to initialize a Plant object
    Plant(std::string n, int buyPrice, int sPrice);


    // Displays the plant's name and sell price
    void display() const override;


    // Returns the sell price of the plant
    int getSellPrice() const;

};


#endif // PLANT_H