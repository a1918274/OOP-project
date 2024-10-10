#include "Inventory.h"

#include <algorithm>
#include <iostream>

using namespace std;

// Destructor to clean up dynamically allocated items
Inventory::~Inventory() {
  // a clear function here
}

// Adds an item to the inventory
void Inventory::addItem(Item* item) {
  items.push_back(item);  // Store the item in the vector
}

// Removes an item from the inventory
void Inventory::removeItem(Item* item) {
  items.erase(remove_if(items.begin(), items.end(),
                        [item](Item* i) { return i == item; }),
              items.end());  // remove item by pointer??
}

// Displays all items in the inventory (might want to use count)
void Inventory::display() const {
  if (items.empty()) {
    cout << "Your inventory is empty.\n";
    return;
  }
  cout << "\nYour inventory:\n";
  for (const auto& item : items) {
    // Call the display function of each item
  }
}
