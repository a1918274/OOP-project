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
    // testDisplayItems();
    // testBuyItem();
    cout << "\nFinished testing for Shop!\n\n";
  }

 private:
  void testConstructor() {
    cout << "Testing for shop constructor:\n";

    {
      // Inventory inventory;
      Shop shop;
      Inventory& inventory = shop.getInventory();
      cout<<"checking for assert:\n";
      assert(!inventory.getItems().empty());
      cout<<"assert run\n";
    }

    cout << "All tests for constructor passed!" << endl;
  }

  // void testDisplayItems() {}
  // void testBuyItem() {}
};

#endif  // TESTSHOP_H