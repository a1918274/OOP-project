#ifndef ITEM_H
#define ITEM_H

#include <fstream>
#include <iostream>
#include <string>

// Abstract class that contains the information about each ‘item’, specifically
// name and price (i.e. the name and price of either a crop or animal).
// Item class is the parent class for seed, plant, animal, dog

class Item {
 protected:
  std::string name;  // Name of the item
  int price;         // Price of the item
  int itemCount;     // Count of the item

 public:
  // Constructor

  // Initializes an item
  Item(const std::string& n, int p, int count);

  // Virtual Destructor
  virtual ~Item();

  // Methods

  // Pure virtual function for displaying item details
  virtual void display() const = 0;
  // Increments the item count
  void incrementCount();
  // Resets the item count to one
  void resetItemCount();

  // Getters

  // Returns the item's name
  std::string getName() const;
  // Returns the item's price
  int getPrice() const;
  // Returns the item's count
  int getItemCount() const;

  // Setters

  // Sets the item's count
  void setItemCount(int count);

  // serialize (override) and deserialize item to and from a file
  virtual void serialize(std::ofstream& outFile) const = 0;
  static Item* deserialize(std::ifstream& inFile);
};

#endif  // ITEM_H