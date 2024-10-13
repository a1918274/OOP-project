#ifndef SEED_H
#define SEED_H

#include <fstream>  // for read/write files
#include <string>

#include "Item.h"


// this class contains information about the seed of a type of plant the player
// can grow, including potato, snow pea and tomato seeds

// this class inherits from item class

// forward declaration of the Plant class
class Plant;

class Seed : public Item {
 public:
  // constructor to initialize a Seed object
  Seed(const std::string& name, int price);

  // displays the seed's details (override display method from Item class)
  void display() const override;

  // growing the seed into a plant (Plant class)
  Plant* grow() const;

  // serialize the seed to a file
    void serialize(std::ofstream& outFile) const override;


  // deserialize a seed from a file
    static Seed* deserialize(std::ifstream& inFile);
};


#endif  // SEED_H