#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

#include "Item.h"

// Inventory class contains a vector which stores the pointers to items in the
// inventory for the farm

class Inventory {
 private:
  std::vector<Item*> items;  // Item stored in the inventory

 public:
  // Constructor to initialize the inventory
  Inventory();

  // Destructor to clean up the inventory
  ~Inventory();

  // Getter

  // Returns all items in the inventory
  const std::vector<Item*>& getItems() const;

  // Methods

  // Displays all items currently in the inventory
  void display() const;
  // Adds an item to the inventory
  void addItem(Item* item);
  // Removes an item from the inventory
  void removeItem(Item* item);
  // Clears the inventory and frees memory
  void clear();
};

#endif  // INVENTORY_H