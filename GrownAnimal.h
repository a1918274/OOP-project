#ifndef GROWNANIMAL_H
#define GROWNANIMAL_H

#include <fstream>
#include <string>

#include "Animal.h"

// GrownAnimal class inherits from animal and contains information about a type
// of grown animal the player can tend to and sell the product of the grown
// animal for gold

class GrownAnimal : public Animal {
 private:
  std::string produceType;  // Type of produce (e.g. milk, wool)
  int produceValue;         // Value of the produce (gold)
  int produceCount;         // Current produce count

 public:
  // Constructor to initialize a GrownAnimal object
  GrownAnimal(const std::string& n, int p, const std::string& t, int value);

  // Getters

  // Returns the current produce count
  int getProduceCount() const;
  // Returns the value of the produce
  int getProduceValue() const;

  // Setter

  // Sets the current produce count
  void setProduceCount(int count);

  // Methods

  // Generates produce and updates the count
  void produceItem();
  // Clears the produce count
  void clearProduce();

  // File operations

  // Serializes the grown animal to a file
  void serialize(std::ofstream& outFile) const override;
  // Deserializes a grown animal from a file
  static GrownAnimal* deserialize(std::ifstream& inFile);

  // Display the grown animal's details including produce count (override)
  void display() const override;
};

#endif  // GROWNANIMAL_H