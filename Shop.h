#ifndef SHOP_H
#define SHOP_H
#include "Inventory.h"

//This class includes the mechanisms by which 
//the player can buy items with their gold

// Class representing a shop where items can be bought
class Shop{
    private:
    Inventory inventory; // Inventory for the shop

    public:
    // Constructor
    Shop();                 // Initializes the shop's inventory

    // Destructor
    ~Shop();                    // Cleans up dynamically allocated items

    // Methods
    void displayItems() const;  // Function to display available items in the shop
    bool buyItem(int choice, int& gold, Inventory& playerInventory);
    // Function that allows a player to buy an item from the shop, 
    // Deducts their gold accordingly, and adds the item to the player's inventory
};

#endif //SHOP_H