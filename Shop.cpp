#include "Shop.h"
#include "Seed.h"
#include <iostream>

using namespace std;

//Initializing the shop with items
Shop::Shop(){
    inventory.addItem(new Seed("Potato(Seeds)", 4));
    inventory.addItem(new Seed("Corn(Seeds)", 8));
    inventory.addItem(new Seed("Tomato(Seeds)", 11));
    //add Dog and animals later
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
