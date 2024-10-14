#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
private:
    std::vector<Item*> items; // Vector to store pointers to items

public:
    // Destructor to clean up dynamically allocated items
    ~Inventory();

    // Adds an item to the inventory
    void addItem(Item* item);

    // Removes an item from the inventory
    void removeItem(Item* item);

    // Displays all items currently in the inventory
    void display() const;

    // Returns a const reference to the vector of items in the inventory
    const std::vector<Item*>& getItems() const;

    // Clears the inventory
    void clear();
};

#endif // INVENTORY_H