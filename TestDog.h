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
    cout << "\nStart testing for Dog:\n\n";
    testConstructor();
    testDisplay();
    testSerializeDeserialize();
    cout << "\nFinished testing for Dog!\n\n";
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
    cout << "Testing for Display:\n";

    {
      Dog dog("Happy", 100);
      cout << "Expected output:\n[ 1x ] Dog: Happy (100 gold)\n";
      cout << "Actual output:\n";
      dog.display();
      cout << "Test 1 passed!" << endl;
    }

    {
      Dog dog("Doggie", 0);
      cout << "Expected output:\n[ 1x ] Dog: Doggie (0 gold)\n";
      cout << "Actual output:\n";
      dog.display();
      cout << "Test 2 passed!" << endl;
    }

    cout << "Test display passed!" << endl;
  }

  void testSerializeDeserialize() {
    cout << "Testing for serialization and deserialization:\n";
    {
      // serialization
      Dog dog("doggie", 100);
      std::ofstream outFile("testDog.txt");
      assert(outFile);  // Error if outFile is not created
      dog.serialize(outFile);
      outFile.close();

      // deserialization
      string type;
      std::ifstream inFile("testDog.txt");
      assert(inFile);  // Error if inFile cannot open
      inFile >> type;
      Dog* deserializedDog = Dog::deserialize(inFile);
      assert(deserializedDog->getName() == "doggie" &&
             deserializedDog->getPrice() == 100 &&
             deserializedDog->getItemCount() == 1);
      delete deserializedDog;
      inFile.close();
    }

    {
      // serialization
      Dog dog("zero", 0);
      std::ofstream outFile("testDog.txt");
      assert(outFile);  // Error if outFile is not created
      dog.serialize(outFile);
      outFile.close();

      // deserialization
      string type;
      std::ifstream inFile("testDog.txt");
      assert(inFile);  // Error if inFile cannot open
      inFile >> type;
      Dog* deserializedDog = Dog::deserialize(inFile);
      assert(deserializedDog->getName() == "zero" &&
             deserializedDog->getPrice() == 0 &&
             deserializedDog->getItemCount() == 1);
      delete deserializedDog;
      inFile.close();
    }

    {
      // serialization
      Dog dog("yappie", 50);
      std::ofstream outFile("testDog.txt");
      assert(outFile);  // Error if outFile is not created
      dog.serialize(outFile);
      outFile.close();

      // deserialization
      std::ifstream inFile("testDog.txt");

      // Read the item type first
      string type;
      inFile >> type;

      assert(inFile);  // Error if inFile cannot open
      Dog* deserializedDog = Dog::deserialize(inFile);
      assert(deserializedDog->getName() == "yappie" &&
             deserializedDog->getPrice() == 50 &&
             deserializedDog->getItemCount() == 1);
      delete deserializedDog;
      inFile.close();
    }

    cout << "Test serialization and deserialization passed!" << endl;
  }
};

#endif  // TESTDOG_H