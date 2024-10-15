#ifndef TESTSEED_H
#define TESTSEED_H
#include<iostream>
#include <fstream>
#include <cassert>

#include "Item.h"
#include "Seed.h"
#include "Plant.h"

using namespace std;

class TestSeed {
public:
    void runTests(){
        cout << "\n Running tests for Seed: \n\n";
        testConstructor();
        testDisplay();
        testGetPlantType();
        testGrow();
        testSerializeDeserialize();
        cout << "\nFinished tests for Plant.\n\n";
    }

private:
void testConstructor(){
    cout << "Testing Seed constructor:\n";
    {
     Seed seed("Strawberry(Seeds))", 6);
     assert((seed.getName() == "Strawberry(Seeds)") && (seed.getPrice() == 6));
    }
    {
     Seed seed("Lettuce(Seeds)", 11);
     assert((seed.getName() == "Lettuce(Seeds)") && (seed.getPrice() == 11));
    }
    {
     Seed seed("Watermelon(Seeds)", 15);
     assert((seed.getName() == "Watermelon(Seeds)") && (seed.getPrice() == 15));
    }
    cout << "Test 1 (constructor) passed" << endl;
}

void testDisplay(){
    cout << "Testing Seed display:\n";

    {Seed seed("Corn(Seeds)", 5);
    // Manually check the subsequent output to confirm display format is correct
    cout << "Expected output: [ 1x ] Plant: Corn, Sell Price: 9 gold\n";
      cout << "Actual output: ";
      seed.display();
    }

}

void testGetPlantType(){
    cout<< "Testing Seed GetPlantType:\n";
    {Seed seed("Corn(Seeds)", 5);
    if (seed.getPlantType() != "Corn"){
        cout << "Test 3.1 failed" << endl;
    }
    }
    {Seed seed("Potato(Seeds)", 6);
    if (seed.getPlantType() != "Potatoes"){
        cout << "Test 3.2 failed" << endl;
    }
    }
    {Seed seed("Tomato(Seeds)", 5);
    if (seed.getPlantType() != "Tomatoes"){
        cout << "Test 3.3 failed" << endl;
    }
    }
    cout << "Test 3 (getSellPrice) passed" << endl;
}

void testGrow(){
    cout << "Testing Seed Grow:" << endl;

    {
      Seed seed("Corn(Seeds)", 8);
      Plant* sproutedSeed = seed.grow();
      assert(sproutedSeed->getName() == "Corn" && "Test 4.1 failed: Corn seeds grow into Corn");
      assert(sproutedSeed->getSellPrice() == 8 && "Test 4.2 failed: Corn buy price should be 8");
      assert(sproutedSeed->getSellPrice() == 14 && "Test 4.3 failed: Corn sell price should be 14");
      delete sproutedSeed;  // Clean up dynamically allocated memory
    }

    {
      Seed seed("Potato(Seeds)", 4);
      Plant* sproutedSeed = seed.grow();
      assert(sproutedSeed->getName() == "Potatoes" && "Test 4.1 failed: Potato seeds grow into Potatoes");
      assert(sproutedSeed->getSellPrice() == 4 && "Test 4.2 failed: Potato buy price should be 4");
      assert(sproutedSeed->getSellPrice() == 5 && "Test 4.3 failed: Potato sell price should be 5");
      delete sproutedSeed;  // Clean up dynamically allocated memory
    }

    {
      Seed seed("Tomato(Seeds)", 11);
      Plant* sproutedSeed = seed.grow();
      assert(sproutedSeed->getName() == "Potatoes" && "Test 4.1 failed: Tomato seeds grow into Tomatoes");
      assert(sproutedSeed->getSellPrice() == 11 && "Test 4.2 failed: Tomato buy price should be 11");
      assert(sproutedSeed->getSellPrice() == 22 && "Test 4.3 failed: Tomato sell price should be 22");
      delete sproutedSeed;  // Clean up dynamically allocated memory
    }

    cout << "Test 4 (grow) passed" << endl;
  }

  void testSerializeDeserialize() {
    // The serialize and deserialize functions are grouped together for testing,
    // as retrieving the information from the file containing the serialized
    // data is equivalent to deserialization
    cout << "Testing serialization and deserialization:" << endl;
    
    {
      // Serialization testing
      Seed seed("Corn(seeds)", 8);
      ofstream outFile("testSeed.txt");
      assert(outFile); // Error is outfile is not created
      seed.serialize(outFile);
      outFile.close();

      // Deserialization testing
      ifstream inFile("testSeed.txt");
      string type;
      inFile>>type;
      assert(inFile); // Error if inFile cannot open

      Seed* deserializedSeed = Seed::deserialize(inFile);
      assert(deserializedSeed != nullptr && "Test 5.1 failed: Deserialization returned nullptr");
      assert(deserializedSeed->getName() == "Corn(seeds)" && "Test 5.2 failed: Incorrect name after deserialization");
      assert(deserializedSeed->getPrice() == 8 && "Test 5.3 failed: Incorrect buy price after deserialization");
      delete deserializedSeed;  // Clean up
      inFile.close();
    }

    {
      // Serialization testing
      Seed seed("Potato(seeds)", 4);
      ofstream outFile("testSeed.txt");
      assert(outFile); // Error is outfile is not created
      seed.serialize(outFile);
      outFile.close();

      // Deserialization testing
      ifstream inFile("testSeed.txt");
      string type;
      inFile>>type;
      assert(inFile); // Error if inFile cannot open

      Seed* deserializedSeed = Seed::deserialize(inFile);
      assert(deserializedSeed != nullptr && "Test 5.1 failed: Deserialization returned nullptr");
      assert(deserializedSeed->getName() == "Potato(seeds)" && "Test 5.2 failed: Incorrect name after deserialization");
      assert(deserializedSeed->getPrice() == 4 && "Test 5.3 failed: Incorrect buy price after deserialization");
      delete deserializedSeed;  // Clean up
      inFile.close();
    }

    {
      // Serialization testing
      Seed seed("Tomato(seeds)", 11);
      ofstream outFile("testSeed.txt");
      assert(outFile); // Error is outfile is not created
      seed.serialize(outFile);
      outFile.close();

      // Deserialization testing
      ifstream inFile("testSeed.txt");
      string type;
      inFile>>type;
      assert(inFile); // Error if inFile cannot open

      Seed* deserializedSeed = Seed::deserialize(inFile);
      assert(deserializedSeed != nullptr && "Test 5.1 failed: Deserialization returned nullptr");
      assert(deserializedSeed->getName() == "Tomato(seeds)" && "Test 5.2 failed: Incorrect name after deserialization");
      assert(deserializedSeed->getPrice() == 11 && "Test 5.3 failed: Incorrect buy price after deserialization");
      delete deserializedSeed;  // Clean up
      inFile.close();
    }

    cout << "Test 5 (serialization and deserialization) passed" << endl;
  }

};


#endif //TESTSEED_H