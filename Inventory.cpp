#include "Inventory.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Destructor to clean up dynamically allocated items
Inventory::~Inventory() {
    clear(); // Ensure items are deleted when inventory is destroyed
}

// Adds an item to the inventory
void Inventory::addItem(Item* item) {
    items.push_back(item); // Store the item in the vector
}

// Removes an item from the inventory
void Inventory::removeItem(Item* item) {
    items.erase(remove_if(items.begin(), items.end(),
        [item](Item* i) { return i == item; }), items.end()); // Remove item by pointer
}

// Displays all items in the inventory
void Inventory::display() const {
    if (items.empty()) {
        cout << "Your inventory is empty.\n";
        return;
    }
    cout << "\nYour inventory:\n";
    for (const auto& item : items) {
        item->display(); // Call the display method of each item
    }
}

// Returns a const reference to the vector of items in the inventory
const vector<Item*>& Inventory::getItems() const {
    return items;
}

// Clears the inventory
void Inventory::clear() {
    for (auto item : items) {
        delete item; // Delete each item to prevent memory leaks
    }
    items.clear(); // Clear the vector
}