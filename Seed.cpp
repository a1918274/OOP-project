#include "Seed.h"
#include "Plant.h"

#include <iostream>

using namespace std;

// constructor to initialize a seed object to item class
Seed::Seed(const string& name, int price) : Item(name, price) {}

// display the seed's name and price (override method from parent class)
void Seed::display() const {
  cout << "Seed: " << name << ", Price: " << price << " gold\n";
}

// grow the seed into a plant
Plant* Seed::grow() const {
  // turn seed into plant and return plant pointer
  if (name == "Potato(Seeds)") {
    return new Plant("Potatoes", 4, 5);
  } else if (name == "Corn(Seeds)") {
    return new Plant("Corn", 8, 14);
  } else if (name == "Tomato(Seeds)") {
    return new Plant("Tomatoes", 11, 22);
  }

  // return nullptr if no matching seed is found
  return nullptr;
}

//Serialize the seed to a file
void Seed::serialize(std::ofstream& outFile) const {
    outFile << "Seed " << name << " " << price << "\n";
}

// Deserialize a seed from a file
Seed* Seed::deserialize(std::ifstream& inFile) {
    string name;
    int price;
    inFile >> name >> price;
    return new Seed(name, price);
}
