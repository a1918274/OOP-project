#include "Animal.h"

// constructor to initialize an animal object with name, price and type
Animal::Animal(const std::string& n, int p, const std::string& t)
    : Item(n, p), type(t) {}

// getter for the type
std::string Animal::getType() const {
  return type;  // returns the animal type
}

Animal* Animal::deserialize(std::ifstream& inFile) {
  // return nullptr as this function is not used in animal class
  return nullptr;
}