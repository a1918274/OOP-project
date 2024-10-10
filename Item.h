#ifndef ITEM_H
#define ITEM_H

// Abstract class that contains the information about each ‘item’, specifically
// name and price (i.e. the name and price of either a crop or animal).
// The class also contains a pure virtual function for displaying item
// information.

#include <fstream>
#include <iostream>
#include <string>

class Item {
 protected:  // The user should not be able to change the name or price of items
  std::string name;  // The name of the item
  int price;         // The price of the item

 public:
  Item(const std::string& n, int p);  // Constructor
  virtual ~Item();                    // Virtual Destructor
};

#endif