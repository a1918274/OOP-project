#include"Plant.h"
#include <iostream>

using namespace std;

// Constructor to initialize a Plant object, as well as initialzing item count to 1
Plant::Plant(string n, int buyPrice, int sPrice)
    : Item(n, buyPrice, 1), sellPrice(sPrice) {}

// Displays the plant's name and sell price
void Plant::display() const {
    cout << "[ " << getItemCount() << "x ] "
         << "Plant: " << getName()
         << ", Sell Price: " << getSellPrice() << " gold\n";
}

// Returns the sell price of the plant
int Plant::getSellPrice() const {
    return sellPrice;
}

// Serialize the plant to a file
void Plant::serialize(std::ofstream& outFile) const {
    outFile << "Plant " << getName() << " "
            << getPrice() << " " << getSellPrice() << " "
            << getItemCount() << "\n";
}

// Deserialize a plant from a file
Plant* Plant::deserialize(std::ifstream& inFile) {
    string name;
    int buyPrice, sellPrice, count;

    // Error checking while reading from file
    if (!(inFile >> name >> buyPrice >> sellPrice >> count)) {
        cerr << "Error reading plant data from file." << endl;
        return nullptr; // Return nullptr if reading fails
    }

    Plant* plant = new Plant(name, buyPrice, sellPrice); // Create a new plant object
    plant->setItemCount(count); // Use the setter method to set item count
    return plant;
}
