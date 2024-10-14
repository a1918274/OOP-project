#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

#include "Item.h"

// Inventory class contains a vector which stores the pointers to items in the inventory for the farm

// Class representing the player's inventory
class Inventory {
private:
  std::vector<Item*> items; // Items stored in the inventory

public:
  // Constructor
  Inventory();                                  // Initializes the inventory

  // Destructor
  ~Inventory();                                 // Cleans up the inventory

  // Getter
  const std::vector<Item*>& getItems() const;   // Returns all items in the inventory

  // Methods
  void display() const;                         // Displays all items in the inventory
  void addItem(Item* item);                     // Adds an item to the inventory
  void removeItem(Item* item);                  // Removes an item from the inventory
  void clear();                                 // Clears the inventory and frees memory
};

#endif // INVENTORY_H