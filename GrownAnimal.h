#ifndef GROWNANIMAL_H
#define GROWNANIMAL_H

// this class inherits from animal and contains information about a type of
// grown animal the player can tend to and sell the product of the grown animal
// for gold

#include <Animal.h>

#include <fstream>
#include <string>

class GrownAnimal : public Animal {
 private:
  std::string produceType;  // Type of produce (e.g. milk, wool)
  int produceValue;         // Value of the produce (gold)
  int produceCount;         // Current produce count

 public:
    // constructor to initialize a GrownAnimal object
    GrownAnimal(const std::string& n, int p, const std::string& t, int value);

    // display the grown animal's details including produce count (override)
    void display() const override;

    // generate produce and updates the count
    void produceItem();

    // gets the current produce count
    int getProduceCount() const;

    // clears the produce count
    void clearProduce();

    // gets the produce value
    int getProduceValue() const;

    // serialize (override) and deserialize the grown animal to and from a file
    void serialize(std::ofstream& outFile) const override;
    static GrownAnimal* deserialize(std::ifstream& inFile);
};

#endif  // GROWNANIMAL_H