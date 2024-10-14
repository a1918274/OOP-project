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
  YoungAnimal(const std::string& n, int p, const std::string& t); // Initialise a YoungAnimal object

  // Getters 
  std::string getGrownAnimalType() const;   // Returns the type of grown animal corresponding to the young animal

  // Methods
  GrownAnimal* grow();                      // Logic to grow the young animal into an adult animal
  void display() const override;            // Displays the young animal's details (override)

  // Serialization
  void serialize(std::ofstream& outFile) const override;    // Serializes the young animal to a file (for saving)
  static YoungAnimal* deserialize(std::ifstream& inFile);   // Deserializes a young animal from a file (for loading)
};

#endif  // YOUNGANIMAL_H