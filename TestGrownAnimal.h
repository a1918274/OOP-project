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

    {
      GrownAnimal bird("THAT bird", 25, "Carwash", 12);
      bird.produceItem();
      assert(bird.getProduceCount() == 1 && "Test 2.4 failed: Produce count should be 1 after one production");

      bird.produceItem();
      assert(bird.getProduceCount() == 2 && "Test 2.5 failed: Produce count should be 2 after two productions");

      bird.clearProduce();
      assert(bird.getProduceCount() == 0 && "Test 2.6 failed: Produce count should be cleared");
    }

    cout << "All produce method tests passed!" << endl;
  }

  void testDisplay() {
    cout << "Testing display method:" << endl;
    {
      GrownAnimal cow("Mooey", 25, "Milk", 12);
      cout << "Expected Output:\n[ 1x ] Grown Animal: Mooey, Price: 25 gold (Produce: Milk, Produce count: 0 )\n";
      cout << "Actual Output:\n";
      cow.display();
      cout << "Test 1 Passed" << endl;
    }

    {
      GrownAnimal bird("THAT bird", 100, "Carwash", 15);
      cout << "Expected Output:\n[ 1x ] Grown Animal: THAT bird, Price: 100 gold (Produce: Carwash, Produce count: 0 )\n";
      cout << "Actual Output:\n";
      bird.display();
      cout << "Test 2 Passed" << endl;
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

    {
      // Test serialization with different values
      GrownAnimal goat("Goat", 30, "Milk", 15);
      goat.produceItem();  // Goat has produced 1 Milk
      std::ofstream outFile("test_GrownAnimal2.txt");
      goat.serialize(outFile);
      outFile.close();

      // Test deserialization
      std::ifstream inFile("test_GrownAnimal2.txt");

      // Read the item type first
      string itemType;
      inFile >> itemType;
      assert(itemType == "GrownAnimal" && "Test 5.1 failed: Incorrect item type in file");

      GrownAnimal* deserializedGoat = GrownAnimal::deserialize(inFile);
      assert(deserializedGoat != nullptr && "Test 5.2 failed: Deserialization returned nullptr");
      assert(deserializedGoat->getName() == "Goat" && "Test 5.3 failed: Incorrect name after deserialization");
      assert(deserializedGoat->getPrice() == 30 && "Test 5.4 failed: Incorrect price after deserialization");
      assert(deserializedGoat->getProduceValue() == 15 && "Test 5.5 failed: Incorrect produce value after deserialization");
      assert(deserializedGoat->getProduceCount() == 1 && "Test 5.6 failed: Incorrect produce count after deserialization");
      delete deserializedGoat;  // Clean up
      inFile.close();
    }

    {
      // Test serialization with different values
      GrownAnimal chicken("Chicken", 20, "Egg", 5);
      chicken.produceItem();  // Chicken has produced 1 Egg
      std::ofstream outFile("test_GrownAnimal3.txt");
      chicken.serialize(outFile);
      outFile.close();

      // Test deserialization
      std::ifstream inFile("test_GrownAnimal3.txt");

      // Read the item type first
      string itemType;
      inFile >> itemType;
      assert(itemType == "GrownAnimal" && "Test 6.1 failed: Incorrect item type in file");

      GrownAnimal* deserializedChicken = GrownAnimal::deserialize(inFile);
      assert(deserializedChicken != nullptr && "Test 6.2 failed: Deserialization returned nullptr");
      assert(deserializedChicken->getName() == "Chicken" && "Test 6.3 failed: Incorrect name after deserialization");
      assert(deserializedChicken->getPrice() == 20 && "Test 6.4 failed: Incorrect price after deserialization");
      assert(deserializedChicken->getProduceValue() == 5 && "Test 6.5 failed: Incorrect produce value after deserialization");
      assert(deserializedChicken->getProduceCount() == 1 && "Test 6.6 failed: Incorrect produce count after deserialization");
      delete deserializedChicken;  // Clean up
      inFile.close();
    }

    cout << "Serialization and deserialization tests passed!" << endl;
  }
};

#endif  // TESTGROWNANIMAL_H
