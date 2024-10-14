#include "YoungAnimal.h"

#include <iostream>
using namespace std;

// Constructor to initialise a YoungAnimal object
YoungAnimal::YoungAnimal(const std::string& n, int p, const std::string& t)
    : Animal(n, p, t) {} // ItemCount defaults to 1 in Animal


// logic to grow the young animal into an adult animal
GrownAnimal* YoungAnimal::grow() {
  if (name == "Chick") {
    return new GrownAnimal("Chicken", 16, "Egg", 7);
  } else if (name == "Lamb") {
    return new GrownAnimal("Sheep", 20, "Wool", 9);
  } else if (name == "Calf") {
    return new GrownAnimal("Cow", 25, "Milk", 12);
  }
  return nullptr;  // return nullptr if no matching young animal is found
}

// Displays the young animal's name, price, and type, with item count in boxes (override)
void YoungAnimal::display() const {
  cout <<"[ "<<getItemCount()<< "x ] "<< "Young Animal: " << name << ", Price: " << price
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