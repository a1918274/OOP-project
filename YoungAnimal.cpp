#include "YoungAnimal.h"

#include <iostream>
using namespace std;

// constructor to initialise a YoungAnimal object
YoungAnimal::YoungAnimal(const std::string& n, int p, const std::string& t)
    : Animal(n, p, t) {}

// logic to grow the young animal into an adult animal
// function to return grown animal: grow()

// displays the young animal's details (override)
void YoungAnimal::display() const {
  cout << "Young Animal: " << name << ", Price: " << price
       << " gold (Type: " << getType() << ")\n";
}

// serialize and deserialize young animal to and from a file
void YoungAnimal::serialize(std::ofstream& outFile) const {
  outFile << "YoungAnimal " << name << " " << price << " " << getType() << "\n";
}

YoungAnimal* YoungAnimal::deserialize(std::ifstream& inFile) {
  string name, type;
  int price;
  inFile >> name >> price >> type;
  return new YoungAnimal(name, price, type);
}