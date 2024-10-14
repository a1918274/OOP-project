#ifndef SHOP_H
#define SHOP_H
#include "Inventory.h"

//This class includes the mechanisms by which 
//the player can buy items with their gold


class Shop{
    private:
    Inventory inventory; //Inventory for the shop

    public:
    // Constructor to initialize shop inventory
    Shop();

    // Destructor to clean up dynamically allocated items
    ~Shop();

    // Function to display available items in the shop
    void displayItems() const;

    // Function that allows a player to buy an item from the shop, deducts 
    // their gold accordingly, and adds the item to the player's inventory
    bool buyItem(int choice, int& gold, Inventory& playerInventory);
};


#endif //SHOP_H