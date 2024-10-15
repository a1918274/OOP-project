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
      // Inventory inventory;
      Shop shop;
      const Inventory& inventory = shop.getInventory();
      assert(!inventory.getItems().empty());
      // shop.~Shop();
    }

    cout << "All tests for constructor passed!" << endl;
  }

  void testDisplayItems() {
    cout<<"Testing for displayItems:\n";

    {

    }
  }
  void testBuyItem() {}
};

#endif  // TESTSHOP_H