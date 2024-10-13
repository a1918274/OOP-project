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

// Serialize the plant to a file
void Plant::serialize(std::ofstream& outFile) const {
    outFile << "Plant " << name << " " << price << " " << sellPrice << "\n";
}


// Deserialize a plant from a file
Plant* Plant::deserialize(std::ifstream& inFile) {
    string name;
    int buyPrice, sellPrice;
    inFile >> name >> buyPrice >> sellPrice;
    return new Plant(name, buyPrice, sellPrice);
}