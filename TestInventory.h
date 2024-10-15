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
        //if (inventory.getItems().empty());
        assert(inventory.getItems().empty() && "Test failed, inventory is not initialised");
        cout << "Test 1 (constructor) passed\n" << endl;
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
        cout << "Test 2 (getItem) passed\n" << endl;
    }

    void testDisplay(){
        cout << "Testing Inventory Display:\n";
        {// Displaying empty inventory
        Inventory inventory;
        cout << "Expected Output: Your inventory is empty\n";
        cout << "Actual Output:";
        inventory.display();
        }
        {
        // Returning inventory with single item
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        cout << "Expected Output:\n[ 1x ] Seed: Potato(Seeds), Price: 4 gold\n";
        cout <<"Actual Output:";
        inventory.display();
        }
        {
        // Returning inventory with multiple items
        Inventory inventory;
        inventory.addItem(new Seed("Potato(Seeds)", 4));
        inventory.addItem(new Seed("Corn(Seeds)", 8));
        cout << "Expected Output:\n[ 1x ] Seed: Potato(Seeds), Price: 4 gold\n[ 1x ] Seed: Corn(Seeds), Price: 8 gold\n";
        cout << "Actual Output:";
        inventory.display();
        }
        cout << "Test 3 (display) passed\n" << endl;
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
    cout << "Test 4 (addItem) passed\n" << endl;
    }

    void testRemoveItem(){
      cout << "Testing Inventory removeItem:\n";
        {
        // Removing item from an empty inventory
        Inventory inventory;
        Seed* seed = new Seed("Potato(Seeds)", 4);
        inventory.removeItem(seed);
        assert(inventory.getItems().empty() && "Test failed, inventory storage issue");
        }
        {
        // Removing only item to create empty inventory
        Inventory inventory;
        Seed* seed = new Seed("Potato(Seeds)", 4);
        inventory.addItem(seed);
        inventory.removeItem(seed);
        assert(inventory.getItems().empty() && "Test failed, item has not been removed");
        }
        {
        // Removing an item from inventory with multiple items
        Inventory inventory;
        Seed* seed1 = new Seed("Potato(Seeds)", 4);
        Seed* seed2 = new Seed("Corn(Seeds)", 8);
        inventory.addItem(seed1);
        inventory.addItem(seed2);
        inventory.removeItem(seed1);
        assert(inventory.getItems().front() == seed2 && "Test failed, item removal unsuccesful");
        }
    cout << "Test 5 (removeItem) passed\n" << endl;

    }  

    void testClear(){
        Inventory inventory;
        inventory.clear();
        assert(inventory.getItems().empty() && "Test failed, inventory has not been cleared");
        cout << "Test 6 (Clear) passed" << endl;
    }
};


#endif //TESTINVENTORY_H