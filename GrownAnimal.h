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
  std::string produceType;          // Type of produce (e.g. milk, wool)
  int produceValue;                 // Value of the produce (gold)
  int produceCount;                 // Current produce count

 public:
  // Constructor
  GrownAnimal(const std::string& n, int p, const std::string& t, int value);  // Initializes a GrownAnimal object with a name, price, type and value

  // Getters
  int getProduceCount() const;      // Returns the current produce count
  int getProduceValue() const;      // Returns the value of the produce

  // Setter
  void setProduceCount(int count);  // Sets the current produce count

  // Methods
  void produceItem();               // Generates produce and updates the count
  void clearProduce();              // Clears the produce count
  void display() const override;    // Display the grown animal's details including produce count (override)

  // Serialization
  void serialize(std::ofstream& outFile) const override;    // Serializes the grown animal to a file
  static GrownAnimal* deserialize(std::ifstream& inFile);   // Deserializes a grown animal from a file
};

#endif  // GROWNANIMAL_H