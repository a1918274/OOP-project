#ifndef TESTGROWNANIMAL_H
#define TESTGROWNANIMAL_H

// Testing for GrownAnimal

#include <iostream>
#include <fstream>
#include <cassert>

#include "GrownAnimal.h"
#include "Animal.h"

using namespace std;

class TestGrownAnimal {
 public:
  void runTests() {
    cout << "\nStart testing for GrownAnimal:\n\n";
    testConstructor();
    testProduce();
    testDisplay();
    testSerializeDeserialize();
    cout << "\nFinished testing for GrownAnimal!\n\n";
  }

 private:
  void testConstructor() {
    cout << "Testing GrownAnimal constructor:" << endl;
    {
      GrownAnimal cow("Cow", 25, "Milk", 12);
      assert(cow.getName() == "Cow" && "Test 1.1 failed: Incorrect name");
      assert(cow.getPrice() == 25 && "Test 1.2 failed: Incorrect price");
      assert(cow.getProduceValue() == 12 && "Test 1.3 failed: Incorrect produce value");
      assert(cow.getProduceCount() == 0 && "Test 1.4 failed: Initial produce count should be 0");
    }

    {
      GrownAnimal sheep("Sheep", 20, "Wool", 9);
      assert(sheep.getName() == "Sheep" && "Test 1.5 failed: Incorrect name");
      assert(sheep.getPrice() == 20 && "Test 1.6 failed: Incorrect price");
      assert(sheep.getProduceValue() == 9 && "Test 1.7 failed: Incorrect produce value");
      assert(sheep.getProduceCount() == 0 && "Test 1.8 failed: Initial produce count should be 0");
    }

    cout << "All constructor tests passed!" << endl;
  }

  void testProduce() {
    cout << "Testing produce-related methods:" << endl;
    {
      GrownAnimal cow("Cow", 25, "Milk", 12);
      cow.produceItem();
      assert(cow.getProduceCount() == 1 && "Test 2.1 failed: Produce count should be 1 after one production");

      cow.produceItem();
      assert(cow.getProduceCount() == 2 && "Test 2.2 failed: Produce count should be 2 after two productions");

      cow.clearProduce();
      assert(cow.getProduceCount() == 0 && "Test 2.3 failed: Produce count should be cleared");
    }

    cout << "All produce method tests passed!" << endl;
  }

  void testDisplay() {
    cout << "Testing display method:" << endl;
    {
      GrownAnimal cow("Cow", 25, "Milk", 12);
      cow.display();
      // Manual check required to confirm output is correct
    }

    cout << "Display method tested!" << endl;
  }

  void testSerializeDeserialize() {
    cout << "Testing serialization and deserialization:" << endl;

    {
      // Test serialization
      GrownAnimal cow("Cow", 25, "Milk", 12);
      cow.produceItem();  // Cow has produced 1 Milk
      std::ofstream outFile("test_GrownAnimal.txt");
      cow.serialize(outFile);
      outFile.close();

      // Test deserialization
      std::ifstream inFile("test_GrownAnimal.txt");

      // Read the item type first
      string itemType;
      inFile >> itemType;
      assert(itemType == "GrownAnimal" && "Test 4.1 failed: Incorrect item type in file");

      GrownAnimal* deserializedCow = GrownAnimal::deserialize(inFile);
      assert(deserializedCow != nullptr && "Test 4.2 failed: Deserialization returned nullptr");
      assert(deserializedCow->getName() == "Cow" && "Test 4.3 failed: Incorrect name after deserialization");
      assert(deserializedCow->getPrice() == 25 && "Test 4.4 failed: Incorrect price after deserialization");
      assert(deserializedCow->getProduceValue() == 12 && "Test 4.5 failed: Incorrect produce value after deserialization");
      assert(deserializedCow->getProduceCount() == 1 && "Test 4.6 failed: Incorrect produce count after deserialization");
      delete deserializedCow;  // Clean up
      inFile.close();
    }

    cout << "Serialization and deserialization tests passed!" << endl;
  }
};

#endif  // TESTGROWNANIMAL_H
