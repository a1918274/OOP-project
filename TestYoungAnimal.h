#ifndef TESTYOUNGANIMAL_H
#define TESTYOUNGANIMAL_H

// Testing for youngAnimal

#include <iostream>
#include <fstream>
#include <cassert>

#include "YoungAnimal.h"
#include "Animal.h"
#include "GrownAnimal.h"

using namespace std;

class TestYoungAnimal {
 public:
  void runTests() {
    cout << "\nStart testing for YoungAnimal:\n\n";
    testConstructor();
    testGetGrownAnimalType();
    testGrow();
    testDisplay();
    testSerializeDeserialize();
    cout << "\nFinished testing for YoungAnimal!\n\n";
  }

 private:
  void testConstructor() {
    cout << "Testing YoungAnimal constructor:" << endl;
    
    {
      YoungAnimal chick("Chick", 5, "Poultry");
      assert(chick.getName() == "Chick" && "Test 1.1 failed: Incorrect name");
      assert(chick.getPrice() == 5 && "Test 1.2 failed: Incorrect price");
      assert(chick.getType() == "Poultry" && "Test 1.3 failed: Incorrect type");
    }

    {
      YoungAnimal lamb("Lamb", 15, "Mammal");
      assert(lamb.getName() == "Lamb" && "Test 1.4 failed: Incorrect name");
      assert(lamb.getPrice() == 15 && "Test 1.5 failed: Incorrect price");
      assert(lamb.getType() == "Mammal" && "Test 1.6 failed: Incorrect type");
    }

    cout << "All constructor tests passed!" << endl;
  }

  void testGetGrownAnimalType() {
    cout << "Testing getGrownAnimalType:" << endl;

    {
      YoungAnimal chick("Chick", 5, "Poultry");
      assert(chick.getGrownAnimalType() == "Chicken" && "Test 2.1 failed: Chick should grow into Chicken");
    }

    {
      YoungAnimal lamb("Lamb", 15, "Mammal");
      assert(lamb.getGrownAnimalType() == "Sheep" && "Test 2.2 failed: Lamb should grow into Sheep");
    }

    {
      YoungAnimal calf("Calf", 25, "Mammal");
      assert(calf.getGrownAnimalType() == "Cow" && "Test 2.3 failed: Calf should grow into Cow");
    }

    cout << "All getGrownAnimalType tests passed!" << endl;
  }

  void testGrow() {
    cout << "Testing grow method:" << endl;

    {
      YoungAnimal chick("Chick", 5, "Poultry");
      GrownAnimal* grownChick = chick.grow();
      assert(grownChick->getName() == "Chicken" && "Test 3.1 failed: Chick should grow into Chicken");
      assert(grownChick->getPrice() == 16 && "Test 3.2 failed: Chicken price should be 16");
      delete grownChick;  // Clean up dynamically allocated memory
    }

    {
      YoungAnimal lamb("Lamb", 15, "Mammal");
      GrownAnimal* grownLamb = lamb.grow();
      assert(grownLamb->getName() == "Sheep" && "Test 3.3 failed: Lamb should grow into Sheep");
      assert(grownLamb->getPrice() == 20 && "Test 3.4 failed: Sheep price should be 20");
      delete grownLamb;  // Clean up
    }

    cout << "All grow method tests passed!" << endl;
  }

  void testDisplay() {
    cout << "Testing display method:" << endl;

    {
      YoungAnimal chick("Chick", 5, "Poultry");
      chick.display();
      // Manual check required to confirm output is correct
    }

    cout << "Display method tested!" << endl;
  }

  void testSerializeDeserialize() {
    cout << "Testing serialization and deserialization:" << endl;

    {
      // Test serialization
      YoungAnimal chick("Chick", 5, "Poultry");
      std::ofstream outFile("test_YoungAnimal.txt");
      chick.serialize(outFile);
      outFile.close();

      // Test deserialization
      std::ifstream inFile("test_YoungAnimal.txt");

      // Read the item type first
      string itemType;
      inFile >> itemType;
      assert(itemType == "YoungAnimal" && "Test 4.1 failed: Incorrect item type in file");

      YoungAnimal* deserializedChick = YoungAnimal::deserialize(inFile);
      assert(deserializedChick != nullptr && "Test 4.1 failed: Deserialization returned nullptr");
      assert(deserializedChick->getName() == "Chick" && "Test 4.2 failed: Incorrect name after deserialization");
      assert(deserializedChick->getPrice() == 5 && "Test 4.3 failed: Incorrect price after deserialization");
      assert(deserializedChick->getType() == "Poultry" && "Test 4.4 failed: Incorrect type after deserialization");
      delete deserializedChick;  // Clean up
      inFile.close();
    }

    cout << "Serialization and deserialization tests passed!" << endl;
  }
};

#endif  // TESTYOUNGANIMAL_H
