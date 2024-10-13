#ifndef ANIMAL_H
#define ANIMAL_H

// this class inherits from item and is the parent class for young and grown
// animals this class differentiates young and grown animals from a pure item
// (cannot be sold like plant)

#include <string>

#include "Item.h"

class Animal : public Item {  // inherits from item
 protected
     :  // can be accessed by the child class (young animal and grown animal)
  std::string type;  // animal type

 public:
  // constructor to initialize an animal object with name, price and type
  Animal(const std::string& n, int p, const std::string& t);

  // getter for the type
  std::string getType() const;

  // virtual display method
  virtual void display() const = 0;  // pure virtual function

  // virtual serialize and deserialize method
  virtual void serialize(std::ofstream& outFile) const = 0;
  static Animal* deserialize(std::ifstream& inFile);
};

#endif  // ANIMAL_H