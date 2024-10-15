#include "Shop.h"

#include <algorithm>  //Library for handling vectors
#include <iostream>

#include "Dog.h"
#include "GrownAnimal.h"
#include "Seed.h"
#include "YoungAnimal.h"

using namespace std;

// Initializing the shop with items
Shop::Shop() {
  inventory.addItem(new Seed("Potato(Seeds)", 4));
  inventory.addItem(new Seed("Corn(Seeds)", 8));
  inventory.addItem(new Seed("Tomato(Seeds)", 11));
  inventory.addItem(new YoungAnimal("Chick", 16, "Growable"));
  inventory.addItem(new YoungAnimal("Lamb", 20, "Growable"));
  inventory.addItem(new YoungAnimal("Calf", 25, "Growable"));
  inventory.addItem(new Dog("The Cutest Dog", 200));
}

// Destructor to clear the inventory, freeing memory
Shop::~Shop() {
  inventory.clear();  // call delete on each dynamically allocated item
}

// Getter for inventory (for testing)
Inventory& Shop::getInventory() { return inventory; }

// Displaying available items for purchase
void Shop::displayItems() const {
  cout << "\n_____________________________________\n\n";
  cout << "( Available items to buy: )\n";
  for (size_t i = 0; i < inventory.getItems().size(); ++i) {
    cout << i + 1 << ". " << inventory.getItems()[i]->getName() << " ("
         << inventory.getItems()[i]->getPrice() << " gold)\n";
  }
  cout << "\n";
}

// Handles item purchasing logic
bool Shop::buyItem(int choice, int& gold, Inventory& playerInventory) {
  if (choice < 1 || choice > static_cast<int>(inventory.getItems().size())) {
    cout << "Invalid choice.\n";
    return false;
  }

  Item* shopItem =
      inventory.getItems()[choice - 1];  // Get the selected item from the shop

  // Handle purchasing the Dog item
  if (dynamic_cast<Dog*>(shopItem)) {
    if (gold >= shopItem->getPrice()) {
      gold -= shopItem->getPrice();  // Deduct the gold
      cout << "\nLooking into the doggo's eyes, you can't help but to bring "
              "the good boi home.\n\n";
      return true;  // Indicate a special action (e.g., quit game after
                    // purchase)
    } else {
      cout << "You don't have enough gold now but promise to someday return to "
              "the good boi...\n";
      return false;
    }
  }

  // Handle purchasing other items
  if (gold >= shopItem->getPrice()) {
    gold -= shopItem->getPrice();  // Deduct the gold

    // Check if the item already exists in the player's inventory
    auto it = std::find_if(
        playerInventory.getItems().begin(), playerInventory.getItems().end(),
        [shopItem](Item* i) { return i->getName() == shopItem->getName(); });

    if (it != playerInventory.getItems().end()) {
      // If the item already exists in the player's inventory, increment the
      // count
      (*it)->incrementCount();
      cout << "\nYou bought another " << shopItem->getName()
           << ". Total count: " << (*it)->getItemCount() << ".\n";
    } else {
      // If the item doesn't exist in the player's inventory, create a new one
      // and add it
      if (Seed* seed = dynamic_cast<Seed*>(shopItem)) {
        playerInventory.addItem(
            new Seed(*seed));  // Add a new Seed item to player's inventory
      } else if (YoungAnimal* animal = dynamic_cast<YoungAnimal*>(shopItem)) {
        playerInventory.addItem(new YoungAnimal(
            *animal));  // Add a new YoungAnimal to player's inventory
      } else if (Dog* dog = dynamic_cast<Dog*>(shopItem)) {
        playerInventory.addItem(
            new Dog(*dog));  // Adds the Dog to player's inventory
      }

      cout << "\nYou bought " << shopItem->getName() << " for "
           << shopItem->getPrice() << " gold.\n";
    }

    return false;  // Return false to indicate the player can't afford the item
  } else {
    cout << "\n Uhhhh.... You're broke lol.\n";
    return false;
  }
}