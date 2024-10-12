#ifndef INVENTORY_H
#define INVENTORY_H

// This class contains a vector which stores the pointers to items in the
// inventory. This class can also add or remove an item from the inventory, as
// well as display everything that is within the inventory.

#include <vector>

#include "Item.h"

class Inventory {
 private:
  std::vector<Item*> items;  // Vector to store pointers to items

 public:
  //  Destructor to clean up dynamically allocated items
  ~Inventory();

  // Adds an item to the inventory
  void addItem(Item* item);

  // Removes an item from the inventory
  void removeItem(Item* item);

  // Displays all items currently in the inventory
  void display() const;
};

#endif