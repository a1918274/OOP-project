#include "Shop.h"
#include "Seed.h"
#include "YoungAnimal.h"
#include "GrownAnimal.h"
#include "Dog.h"
#include <iostream>

using namespace std;

//Initializing the shop with items
Shop::Shop(){
    inventory.addItem(new Seed("Potato(Seeds)", 4));
    inventory.addItem(new Seed("Corn(Seeds)", 8));
    inventory.addItem(new Seed("Tomato(Seeds)", 11));
    inventory.addItem(new YoungAnimal("Chick", 16, "Growable"));
    inventory.addItem(new YoungAnimal("Lamb", 20, "Growable"));
    inventory.addItem(new YoungAnimal("Calf", 25, "Growable"));
    inventory.addItem(new Dog("The Cutest Dog", 200));
}


//Destructor to clean up dynamically allocated items
Shop::~Shop() {
    for (auto item : inventory.getItems()) {
        delete item; // Free memory for each item
    }
}


//Displaying available items for purchase
void Shop::displayItems() const {
    cout << "\n( Available items to buy: )\n";
    for (size_t i = 0; i < inventory.getItems().size(); ++i) {
        cout << i + 1 << ". " << inventory.getItems()[i]->getName() << " ("
             << inventory.getItems()[i]->getPrice() << " gold)\n";
    }
}


//Item purchasing logic
bool Shop::buyItem(int choice, int& gold, Inventory& playerInventory) {
    if (choice < 1 || choice > inventory.getItems().size()) {
        cout << "Invalid choice.\n";
        return false;
    }


    Item* item = inventory.getItems()[choice - 1];

//Method for purchasing the Dog item
if (Dog* dog = dynamic_cast<Dog*>(item)) {
        if (gold >= item->getPrice()) {
            gold -= item->getPrice(); // Deduct the gold
            cout << "\nLooking into the doggo's eyes, you can't help but to bring the good boi home.\n\n";
            return true; // Indicate a special action (e.g., quit)
        } else {
            cout << "You don't have enough gold now but promise to someday return to the good boi...\n";
            return false;
        }
    }


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
