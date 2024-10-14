#ifndef YOUNGANIMAL_H
#define YOUNGANIMAL_H

#include <fstream>
#include <string>

#include "Animal.h"
#include "GrownAnimal.h"

// This class inherits from animal and contains information about a type of baby
// animal the player can buy and tend to

class YoungAnimal : public Animal {
 public:
  // Constructor

  // Initialise a YoungAnimal object
  YoungAnimal(const std::string& n, int p, const std::string& t);

  // Getters

  // Returns the type of grown animal corresponding to the young animal
  std::string getGrownAnimalType() const;

  // Methods

  // Logic to grow the young animal into an adult animal
  GrownAnimal* grow();
  // displays the young animal's details (override)
  void display() const override;

  // serialize (override) and deserialize young animal to and from a file
  void serialize(std::ofstream& outFile) const override;
  static YoungAnimal* deserialize(std::ifstream& inFile);
};

#endif  // YOUNGANIMAL_H