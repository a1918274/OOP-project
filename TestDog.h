#ifndef TESTDOG_H
#define TESTDOG_H

// Testing for Dog

#include <cassert>
#include <fstream>
#include <iostream>

#include "Dog.h"
#include "Item.h"

using namespace std;

class TestDog {
 public:
  void runTests() {
    testConstructor();
    testDisplay();
    testSerializeDeserialize();
  }

 private:
  void testConstructor() {
    cout << "Testing for constructor:\n";

    {
      Dog dog("Happy", 100);
      assert((dog.getName() == "Happy") && (dog.getPrice() == 100));
    }

    {
      Dog dog("doggie", 0);
      assert((dog.getName() == "doggie") && (dog.getPrice() == 0));
    }

    {
      Dog dog("Tofu", -1);
      assert((dog.getName() == "Tofu") && (dog.getPrice() == -1));
    }

    cout << "All test passed!" << endl;
  }

  void testDisplay() {
    {
      Dog dog("dog", 9);
      dog.display();
      cout << "Test 1 passed!" << endl;
    }
  }

  void testSerializeDeserialize() {}
};

#endif  // TESTDOG_H