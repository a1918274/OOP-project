#include "Animal.h"

using namespace std;

// Constructor to initialize an Animal object
Animal::Animal(const string& n, int p, const string& t)
  : Item(n, p, 1), type(t) {}

// Getter for the animal type
string Animal::getType() const {
  return type; // Returns the animal type
}

// Deserialize an animal from a file
Animal* Animal::deserialize(std::ifstream& inFile) {
  return nullptr; // Return nullptr as this function is not used in animal class
}