#include "Item.h"

#include <fstream>
#include <iostream>
#include <string>

#include "GrownAnimal.h"
#include "Plant.h"
#include "Seed.h"
#include "YoungAnimal.h"

using namespace std;

// Constructor to initialize name, price, and item count
Item::Item(const string& n, int p, int count)
    : name(n), price(p), itemCount(count) {};

// Virtual destructor to proper clean up derived classes
Item::~Item() = default;

// Getter for item's name
string Item::getName() const { return name; };

// Getter for item's price
int Item::getPrice() const { return price; };

// Getter for item's count
int Item::getItemCount() const { return itemCount; }

// Set the item's count
void Item::setItemCount(int count) {
  if (count < 0) {
    cout << "Invalid count. Count must be a positive number. Count is now zero."
         << endl;
    count = 0;
  } else {
    itemCount = count;
  }
}

// Increment the item count
void Item::incrementCount() { itemCount++; }

// Reset the item count to one
void Item::resetItemCount() { itemCount = 1; }

// Log error messages to standard error
void logError(const string& message) { std::cerr << message << "\n"; }

// Deserialize an item from a file based on its type
Item* Item::deserialize(std::ifstream& inFile) {
  string type;
  inFile >> type;  // Read the type of item

  if (inFile.fail()) {
    logError("Error reading item type from file.");
    return nullptr;
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

  logError("Unknown item type: " + type);
  return nullptr;
};