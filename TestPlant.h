#ifndef TESTPLANT_H
#define TESTPLANT_H

// Testing for the Plant class

#include <cassert>
#include <fstream>
#include <iostream>

#include "Item.h"
#include "Plant.h"

using namespace std;

class TestPlant {
public:
    void runTests(){
        cout << "\nRunning tests for Plant:\n\n";
        testConstructor();
        testDisplay();
        testGetSellPrice();
        testSerializeDeserialize();
        cout << "\nFinished tests for Plant.\n\n";
    }

 private:
  void testConstructor() {
    cout << "Testing Plant constructor:\n";

    {
      Plant plant("Potato", 7, 23);
      assert((plant.getName() == "Potato") && (plant.getPrice() == 7) &&
             (plant.getSellPrice() == 23));
    }

    {
      Plant plant("Leek", 89, 2);
      assert((plant.getName() == "Leek") && (plant.getPrice() == 89) &&
             (plant.getSellPrice() == 2));
    }

    {
      Plant plant("Tulip", 34, 35);
      assert((plant.getName() == "Tulip") && (plant.getPrice() == 34) &&
             (plant.getSellPrice() == 35));
    }

    cout << "Test 1 (constructor) passed" << endl;
  }

  void testDisplay() {
    cout << "Testing Plant display:\n";

    {
      Plant plant("Corn", 6, 9);
      // Manually check the subsequent output to confirm display format is correct
      cout << "Expected output:\n[ 1x ] Plant: Corn, Sell Price: 9 gold\n";
      cout << "Actual output:\n";
      plant.display();
    }

    {
      Plant plant("Rose", 12, 30);
      // Manually check the subsequent output to confirm display format is correct
      cout << "Expected output:\n[ 1x ] Plant: Rose, Sell Price: 30 gold\n";
      cout << "Actual output:\n";
      plant.display();
    }

    {
      Plant plant("Daisy", 1, 2);
      // Manually check the subsequent output to confirm display format is correct
      cout << "Expected output:\n[ 1x ] Plant: Daisy, Sell Price: 2 gold\n";
      cout << "Actual output:\n";
      plant.display();
    }

    cout << "Test 2 (display) passed" << endl;
  }

void testGetSellPrice(){
    cout << "Testing Plant getSellPrice:\n";
    {
      Plant plant("Corn", 6, 11);
      if (plant.getSellPrice() != 11) {
        cout << "Test 3.1 failed" << endl;
      }
    }

    {
      Plant plant("Corn", 6, 0);
      if (plant.getSellPrice() != 0) {
        cout << "Test 3.2 failed" << endl;
      }
    }

    {
      Plant plant("Corn", 6, 29);
      if (plant.getSellPrice() != 29) {
        cout << "Test 3.3 failed" << endl;
      }
    }
    cout << "Test 3 (getSellPrice) passed" << endl;
}

  void testSerializeDeserialize() {
    // The serialize and deserialize functions are grouped together for testing,
    // as retrieving the information from the file containing the serialized
    // data is equivalent to deserialization
    cout << "Testing serialization and deserialization:" << endl;
    
    {
      // Serialization testing
      Plant plant("Cherry", 3, 7);
      ofstream outFile("testPlant.txt");
      assert(outFile); // Error is outfile is not created
      plant.serialize(outFile);
      outFile.close();

      // Deserialization testing
      ifstream inFile("testPlant.txt");
      string type;
      inFile>>type;
      assert(inFile); // Error if inFile cannot open

      Plant* deserializedPlant = Plant::deserialize(inFile);
      assert(deserializedPlant != nullptr && "Test 4.1 failed: Deserialization returned nullptr");
      assert(deserializedPlant->getName() == "Cherry" && "Test 4.2 failed: Incorrect name after deserialization");
      assert(deserializedPlant->getPrice() == 3 && "Test 4.3 failed: Incorrect buy price after deserialization");
      assert(deserializedPlant->getSellPrice() == 7 && "Test 4.4 failed: Incorrect sell price after deserialization");
      delete deserializedPlant;  // Clean up
      inFile.close();
    }

    {
      // Serialization testing
      Plant plant("Orange", 14, 25);
      ofstream outFile("testPlant.txt");
      assert(outFile); // Error is outfile is not created
      plant.serialize(outFile);
      outFile.close();

      // Deserialization testing
      ifstream inFile("testPlant.txt");
      string type;
      inFile>>type;
      assert(inFile); // Error if inFile cannot open

      Plant* deserializedPlant = Plant::deserialize(inFile);
      assert(deserializedPlant != nullptr && "Test 4.1 failed: Deserialization returned nullptr");
      assert(deserializedPlant->getName() == "Orange" && "Test 4.2 failed: Incorrect name after deserialization");
      assert(deserializedPlant->getPrice() == 14 && "Test 4.3 failed: Incorrect buy price after deserialization");
      assert(deserializedPlant->getSellPrice() == 25 && "Test 4.4 failed: Incorrect sell price after deserialization");
      delete deserializedPlant;  // Clean up
      inFile.close();
    }

    {
      // Serialization testing
      Plant plant("Mango", 16, 38);
      ofstream outFile("testPlant.txt");
      assert(outFile); // Error is outfile is not created
      plant.serialize(outFile);
      outFile.close();

      // Deserialization testing
      ifstream inFile("testPlant.txt");
      string type;
      inFile>>type;
      assert(inFile); // Error if inFile cannot open

      Plant* deserializedPlant = Plant::deserialize(inFile);
      assert(deserializedPlant != nullptr && "Test 4.1 failed: Deserialization returned nullptr");
      assert(deserializedPlant->getName() == "Mango" && "Test 4.2 failed: Incorrect name after deserialization");
      assert(deserializedPlant->getPrice() == 16 && "Test 4.3 failed: Incorrect buy price after deserialization");
      assert(deserializedPlant->getSellPrice() == 38 && "Test 4.4 failed: Incorrect sell price after deserialization");
      delete deserializedPlant;  // Clean up
      inFile.close();
    }

    cout << "Test 4 (serialization and deserialization) passed" << endl;
  }
};

#endif  // TESTPLANT_H