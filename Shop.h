#ifndef SHOP_H
#define SHOP_H

#include "Inventory.h"

// Shop class represents a shop where the player can buy items with
// their gold.

class Shop {
 private:
  Inventory inventory;  // Inventory for the shop

 public:
  // Constructor
  Shop();  // Initializes the shop's inventory

  // Destructor
  ~Shop();  // Cleans up dynamically allocated items

  // Getter for inventory (for testing)
  Inventory& getInventory();

  // Methods
  void displayItems() const;  // Function to display available items in the shop
  bool buyItem(int choice, int& gold, Inventory& playerInventory);
  // Function that allows a player to buy an item from the shop,
  // Deducts their gold accordingly, and adds the item to the player's inventory
};

#endif  // SHOP_H