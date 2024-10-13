#include "GrownAnimal.h"

#include <iostream>

using namespace std;

// constructor to initialize a GrownAnimal object
GrownAnimal::GrownAnimal(const std::string& n, int p, const std::string& t,
                         int value)
    : Animal(n, p, t), produceType(t), produceValue(value), produceCount(0) {}

// display the grown animal's details including produce count (override)
void GrownAnimal::display() const {
  cout << "Grown Animal: " << name << ", Price: " << price
       << " gold (Produce: " << produceType
       << ", Produce count: " << produceCount << " )\n";
}

// generate produce and updates the count
void GrownAnimal::produceItem() {
  produceCount++;  // increment the produce count each time produce item is
                   // called
}

// gets the current produce count
int GrownAnimal::getProduceCount() const { return produceCount; }

// clears the produce count
void GrownAnimal::clearProduce() {
  produceCount = 0;  // resets the produce count after selling
}

// gets the produce value
int GrownAnimal::getProduceValue() const {
  return produceValue;  // return the value of the produce
}

// serialize (override) and deserialize the grown animal to and from a file
void GrownAnimal::serialize(std::ofstream& outFile) const {
  outFile << "GrownAnimal: " << name << " " << price << " " << produceType
          << " " << produceValue << " " << produceCount << "\n";
}

GrownAnimal* GrownAnimal::deserialize(std::ifstream& inFile) {
  string name, produceType;
  int price, produceValue, produceCount;

  inFile >> name >> price >> produceType >> produceValue >> produceCount;

  GrownAnimal* animal = new GrownAnimal(name, price, produceType, produceValue);
  animal->produceCount = produceCount; // set the produce count directly
  
  return animal;
}