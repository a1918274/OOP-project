#ifndef YOUNGANIMAL_H
#define YOUNGANIMAL_H

// this class inherits from animal and contains information about a type of baby
// animal the player can buy and tend to

#include <fstream>
#include <string>

#include "Animal.h"
// #include "GrownAnimal.h"

class YoungAnimal : public Animal {
 public:
  // constructor to initialise a YoungAnimal object
  YoungAnimal(const std::string& n, int price, const std::string& t);

  // logic to grow the young animal into an adult animal
  // function to return grown animal: grow()

  // displays the young animal's details (override)
  void display() const override;

  // serialize and deserialize young animal to and from a file
  void serialize(std::ofstream& outFile) const override;
  static YoungAnimal* deserialize(std::ifstream& inFile);
};

#endif  // YOUNGANIMAL_H