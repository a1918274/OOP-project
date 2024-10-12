#include "Shop.h"
#include <iostream>

using namespace std;

//Initializing the shop with items
Shop::Shop(){
    //to be filled in
}


// Insert Destructor to clean up dynamically allocated items


// Insert Displaying available items for purchase


// Insert item purchasing logic


// Insert purchasing the Dog item


// Handle purchasing other items
    if (gold >= item->getPrice()) {
        gold -= item->getPrice(); // Deduct the gold
        playerInventory.addItem(item); // Add to player's inventory
        cout << "You bought " << item->getName() << " for " << item->getPrice() << " gold.\n";
        return false;
    } else {
        cout << "You're broke lol.\n";
        return false;
    }
