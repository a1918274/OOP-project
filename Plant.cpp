#include"Plant.h"
#include <iostream>

using namespace std;


// Constructor to initialize a Plant object
Plant::Plant(string n, int buyPrice, int sPrice)
    : Item(n, buyPrice), sellPrice(sPrice) {}


// Displays the plant's name and sell price
void Plant::display() const {
    cout << "Plant: " << name << ", Sell Price: " << sellPrice << " gold\n";
}


// Returns the sell price of the plant
int Plant::getSellPrice() const {
    return sellPrice;
}
