#ifndef TESTYOUNGANIMAL_H
#define TESTYOUNGANIMAL_H

// Testing for youngAnimal

#include <iostream>
#include <fstream>
#include <cassert>

#include "YoungAnimal.h"

using namespace std;

class TestYoungAnimal {
 public:
  void runTests() {
    cout << "\nStart testing for YoungAnimal:\n\n";
    testConstructor();
    testGetGrownAnimalType();
    testGrow();
    testDisplay();
    testSerialization();
    cout << "\nFinished testing for YoungAnimal!\n\n";
  }

 private:
  void testConstructor() {
    cout << "Testing YoungAnimal constructor:" << endl;
    {
      YoungAnimal chick("Chick", 5, "Poultry");
      assert(chick.getName() == "Chick" && "Test 1 failed: Incorrect name");
      assert(chick.getPrice() == 5 && "Test 1 failed: Incorrect price");
      assert(chick.getType() == "Poultry" && "Test 1 failed: Incorrect type");
    }

    {
      YoungAnimal lamb("Lamb", 15, "Mammal");
      assert(lamb.getName() == "Lamb" && "Test 2 failed: Incorrect name");
      assert(lamb.getPrice() == 15 && "Test 2 failed: Incorrect price");
      assert(lamb.getType() == "Mammal" && "Test 2 failed: Incorrect type");
    }

    cout << "All constructor tests passed!" << endl;
  }

  void testGetGrownAnimalType() {
    cout << "Testing getGrownAnimalType:" << endl;
    {
      YoungAnimal chick("Chick", 5, "Poultry");
      assert(chick.getGrownAnimalType() == "Chicken" && "Test 1 failed: Chick should grow into Chicken");
    }

    {
      YoungAnimal lamb("Lamb", 15, "Mammal");
      assert(lamb.getGrownAnimalType() == "Sheep" && "Test 2 failed: Lamb should grow into Sheep");
    }

    {
      YoungAnimal calf("Calf", 25, "Mammal");
      assert(calf.getGrownAnimalType() == "Cow" && "Test 3 failed: Calf should grow into Cow");
    }

    cout << "All getGrownAnimalType tests passed!" << endl;
  }

  void testGrow() {
    cout << "Testing grow method:" << endl;
    {
      YoungAnimal chick("Chick", 5, "Poultry");
      GrownAnimal* grownChick = chick.grow();
      assert(grownChick->getName() == "Chicken" && "Test 1 failed: Chick should grow into Chicken");
      assert(grownChick->getPrice() == 16 && "Test 1 failed: Chicken price should be 16");
      delete grownChick;  // Clean up dynamically allocated memory
    }

    {
      YoungAnimal lamb("Lamb", 15, "Mammal");
      GrownAnimal* grownLamb = lamb.grow();
      assert(grownLamb->getName() == "Sheep" && "Test 2 failed: Lamb should grow into Sheep");
      assert(grownLamb->getPrice() == 20 && "Test 2 failed: Sheep price should be 20");
      delete grownLamb;  // Clean up
    }

    cout << "All grow method tests passed!" << endl;
  }

  void testDisplay() {
    cout << "Testing display method:" << endl;
    {
      YoungAnimal chick("Chick", 5, "Poultry");
      chick.display();
      // Manual check required to confirm output correctness
    }

    cout << "Display method tested!" << endl;
  }

  void testSerialization() {
    cout << "Testing serialization and deserialization:" << endl;

    {
      // Test serialization
      YoungAnimal chick("Chick", 5, "Poultry");
      ofstream outFile("test_animal.txt");
      chick.serialize(outFile);
      outFile.close();

      // Test deserialization
      ifstream inFile("test_animal.txt");
      YoungAnimal* deserializedChick = YoungAnimal::deserialize(inFile);
      assert(deserializedChick != nullptr && "Test 1 failed: Deserialization returned nullptr");
      assert(deserializedChick->getName() == "Chick" && "Test 1 failed: Incorrect name after deserialization");
      assert(deserializedChick->getPrice() == 5 && "Test 1 failed: Incorrect price after deserialization");
      assert(deserializedChick->getType() == "Poultry" && "Test 1 failed: Incorrect type after deserialization");
      delete deserializedChick;  // Clean up
      inFile.close();
    }

    cout << "Serialization and deserialization tests passed!" << endl;
  }
};

#endif  // TESTYOUNGANIMAL_H
