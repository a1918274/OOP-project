#ifndef TESTINVENTORY_H
#define TESTINVENTORY_H
#include <iostream>
#include <cassert>
#include <vector>

#include "Inventory.h"
#include "Item.h"
#include "Seed.h" 
//Including seed as an example of class of items that can be added to inventory

//Testing for Inventory files

using namespace std;

class TestInventory {
public:
    void runTests(){
    cout << "\n Running tests for Inventory: \n\n";
    testConstructor();
    testDestructor();
    testGetter();
    testDisplay();
    testAddItem();
    testRemoveItem();
    testClear();
    cout << "\nFinished tests for Inventory.\n\n";
    }

private:
    void testConstructor(){
        cout << "Testing Inventory constructor:\n";
        Inventory inventory;
        if (inventory.getItems().empty())
        assert(inventory().getItems().empty() == nullptr && "Test failed, inventory is not initialised");
        cout << "Test 1 (constructor) passed" << endl;
    }

    void testDestructor() {
        cout << "Testing Inventory deconstructor:\n";
        Inventory inventory;
        assert(~inventory() == nullptr && "Test failed, inventory has not been cleared");
        cout << "Test 2 (deconstructor) passed" << endl;
    }

    void testGetter(){
        cout << "Testing Inventory addItem:\n";
        {
        // Returning empty inventory
        Inventory inventory;
        inventory.getItems();
        }
        {
        // Returning inventory with single item
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        inventory.getItems();
        }
        {
        // Returning inventory with multiple items
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        inventory.addItem(new Seed("Corn(Seeds)", 8));
        inventory.getItems();
        }
        cout << "Test 3 (getItem) passed" << endl;
    }

    void testDisplay(){
        {// Displaying empty inventory
        Inventory inventory;
        cout << "Expected Output:\n";
        cout << "Actual Output:\n";
        inventory.display();
        }
        {
        // Returning inventory with single item
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        cout << "Expected Output:\n[ 1x ] Seed: Potato(Seeds), Price: 4 gold\n";
        cout <<"Actual Output:\n";
        inventory.display();
        }
        {
        // Returning inventory with multiple items
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        inventory.addItem(new Seed("Corn(Seeds)", 8));
        cout << "Expected Output:\n[ 1x ] Seed: Potato(Seeds), Price: 4 gold\n[ 1x ] Seed: Corn(Seeds), Price: 8 gold\n";
        cout << "Actual Output:\n";
        inventory.display();
        }
        cout << "Test 4 (display) passed" << endl;
    }

    void testAddItem(){
        cout << "Testing Inventory addItem:\n";
        {
        // Adding an item to empty inventory
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        inventory.getItems();
        }
        {
        // Adding an item to inventory with prior items
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        inventory.addItem(new Seed("Corn(Seeds)", 8));
        inventory.getItems();
        }
    cout << "Test 5 (addItem) passed" << endl;
    }

    void testRemoveItem(){
      cout << "Testing Inventory removeItem:\n";
        {
        // Adding an item to empty inventory
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        inventory.getItems();
        }
        {
        // Adding an item to inventory with prior items
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        inventory.addItem(new Seed("Corn(Seeds)", 8));
        inventory.getItems();
        }
    cout << "Test 6 (addItem) passed" << endl;

    }  

    void testClear(){
        Inventory inventory;
        assert(~inventory() == nullptr && "Test failed, inventory has not been cleared");
        cout << "Test 7 (Clear) passed" << endl;
    }
};


#endif //TESTINVENTORY_H