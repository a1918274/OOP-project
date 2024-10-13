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


    // Function to buy an item from the shop
    bool buyItem(int choice, int& gold, Inventory& playerInventory);
};


#endif //SHOP_H