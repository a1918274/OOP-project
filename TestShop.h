#ifndef TESTSHOP_H
#define TESTSHOP_H

// Testing for Shop

#include <algorithm>
#include <cassert>
#include <iostream>

#include "Shop.h"

using namespace std;

class TestShop {
 public:
  void runTests() {
    cout << "\nStart testing for Shop:\n\n";
    testConstructor();
    testDisplayItems();
    testBuyItem();
    cout << "\nFinished testing for Shop!\n\n";
  }

 private:
  void testConstructor() {
    cout << "Testing for shop constructor:\n";

    {
      Shop shop;
      const Inventory& inventory = shop.getInventory();
      assert(!inventory.getItems().empty());
    }

    {
      Shop shop;
      const Inventory& inventory = shop.getInventory();
      assert(inventory.getItems().size() == 7);
    }

    cout << "All tests for constructor passed!" << endl;
  }

  void testDisplayItems() {
    cout << "Testing for displayItems:\n";

    {
      Shop shop;
      shop.displayItems();
      cout << "Shop's inventory displayed. Test for displayItems passed!"
           << endl;
    }
  }
  void testBuyItem() {
    cout << "Testing for buyItem:\n";

    {
      Shop shop;
      Inventory inventory;
      int gold = 12;
      assert(shop.buyItem(0, gold, inventory) == 0);
    }

    {
      Shop shop;
      Inventory inventory;
      int gold = 0;
      assert(shop.buyItem(1, gold, inventory) == 0);
    }

    {
      Shop shop;
      Inventory inventory;
      int gold = 12;
      assert(shop.buyItem(1, gold, inventory) == 0);
    }

    {
      Shop shop;
      Inventory inventory;
      int gold = 200;
      assert(shop.buyItem(7, gold, inventory) == 1);
    }

    cout << "All tests for buyItem passed!" << endl;
  }
};

#endif  // TESTSHOP_H