#include "Inventory.h"

#include <algorithm>
#include <iostream>

using namespace std;

// Constructor to initialize the inventory
Inventory::Inventory() {
  // Inventory initializes without items (items vector is empty)
}

// Destructor to clean up the inventory
Inventory::~Inventory() {
  clear();  // Reuse the clear method for clean up
}

// Getter: returns all items in the inventory
const std::vector<Item*>& Inventory::getItems() const { return items; }

// Displays all items in the inventory
void Inventory::display() const {
  if (items.empty()) {
    cout << "\nYour inventory is empty.\n";
    return;
  }
  cout << "\nInventory items:\n";
  for (const auto& item : items) {
    item->display();  // Call the display method of each item
  }
}

// Adds an item to the inventory
void Inventory::addItem(Item* item) {
  items.push_back(item);  // Push the item into the vector
}

// Removes an item from the inventory
void Inventory::removeItem(Item* item) {
  auto it = std::find(items.begin(), items.end(), item);
  if (it != items.end()) {
    delete *it;       // Free memory for the item
    items.erase(it);  // Remove the item from the vector
  }
}

// Clears the inventory
void Inventory::clear() {
  // Free memory for each item
  for (Item* item : items) {
    delete item;
  }
  items.clear();  // Clear the vector
}