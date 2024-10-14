#ifndef ITEM_H
#define ITEM_H

#include <fstream>
#include <iostream>
#include <string>

// Abstract class that contains the information about each ‘item’, specifically
// name and price (i.e. the name and price of either a crop or animal).
// The class also contains a pure virtual function for displaying item
// information.

class Item {
 protected:  // The user should not be able to change the name or price of items
  std::string name;  // The name of the item
  int price;         // The price of the item

 public:
  // Constructor
  Item(const std::string& n, int p);

  // Virtual Destructor
  virtual ~Item();

  // Pure virtual item for displaying item details
  virtual void display() const = 0;

  // Pure virtual function for serialization
  virtual void serialize(std::ofstream& outFile) const = 0;

  // Static method for deserialization
  static Item* deserialize(std::ifstream& inFile);

  // Getter for item name
  std::string getName() const;

  // Getter for item price
  int getPrice() const;
};

#endif  // ITEM_H