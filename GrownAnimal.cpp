#include "GrownAnimal.h"

#include <iostream>

using namespace std;

// Constructor to initialize a GrownAnimal object
GrownAnimal::GrownAnimal(const std::string& n, int p, const std::string& t,
                         int value)
    : Animal(n, p, t), produceType(t), produceValue(value), produceCount(0) {}

// Display the grown animal's details with item count in boxes (override)
void GrownAnimal::display() const {
  cout << "[ " << getItemCount() << "x ] " << "Grown Animal: " << getName()
       << ", Price: " << getPrice() << " gold (Produce: " << produceType
       << ", Produce count: " << getProduceCount() << " )\n";
}

// Generates produce and updates the count
void GrownAnimal::produceItem() { produceCount++; }

// Gets the current produce count
int GrownAnimal::getProduceCount() const { return produceCount; }

// Clears the produce count
void GrownAnimal::clearProduce() { produceCount = 0; }

// Gets the produce value
int GrownAnimal::getProduceValue() const { return produceValue; }

// Set the produce count
void GrownAnimal::setProduceCount(int count) {
  if (count < 0) {
    cout << "Invalid count. Count must be a positive number.\n";
  } else {
    produceCount = count;
  }
}

// serialize (override) and deserialize the grown animal to and from a file
void GrownAnimal::serialize(std::ofstream& outFile) const {
  outFile << "GrownAnimal " << getName() << " " << getPrice() << " "
          << produceType << " " << getProduceValue() << " " << getProduceCount()
          << " " << getItemCount() << "\n";
}

GrownAnimal* GrownAnimal::deserialize(std::ifstream& inFile) {
  string name, produceType;
  int price, produceValue, produceCount, count;

  // Error checking while reading from the file
  if (!(inFile >> name >> price >> produceType >> produceValue >> produceCount >> count)) {
    cerr << "Error reading grown animal data from file." << endl;
    return nullptr;
  }

  GrownAnimal* animal = new GrownAnimal(name, price, produceType, produceValue);
  animal->setProduceCount(produceCount);
  animal->setItemCount(count);
  return animal;
}