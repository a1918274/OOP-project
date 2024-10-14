#ifndef ANIMAL_H
#define ANIMAL_H

// this class inherits from item and is the parent class for young and grown
// animals this class differentiates young and grown animals from a pure item
// (cannot be sold like plant)

#include "Item.h"
#include <string>

// Class representing an animal that inherits from Item
class Animal : public Item {
protected:
  std::string type;   // Animal type

public:
  // Constructor
  Animal(const std::string& n, int p, const std::string& t);  // Initializes an Animal object with a name, price and type

  // Getter
  std::string getType() const;                                // Returns the type of the animal

  // Pure virtual method
  virtual void display() const = 0;                           // Must be implemented by derived classes

  // Serialization
  virtual void serialize(std::ofstream& outFile) const = 0;   // Virtual Serializes the animal to a file (for saving)
  static Animal* deserialize(std::ifstream& inFile);          // Deserializes an animal from a file (for loading)
};

#endif // ANIMAL_H