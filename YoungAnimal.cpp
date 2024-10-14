#include "YoungAnimal.h"

#include <iostream>
using namespace std;

// Constructor to initialise a YoungAnimal object
YoungAnimal::YoungAnimal(const string& n, int p, const string& t)
    : Animal(n, p, t) {}  // ItemCount defaults to 1 in Animal

// Returns the type of gorwn animal that corresponds to the young animal
string YoungAnimal::getGrownAnimalType() const {
  if (getName() == "Chick") {
    return "Chicken";
  } else if (getName() == "Lamb") {
    return "Sheep";
  } else if (getName() == "Calf") {
    return "Cow";
  }

  return "";  // Return an empty string if no matching young animal is found
}

// Logic to grow the young animal into a GrownAnimal
GrownAnimal* YoungAnimal::grow() {
  if (getName() == "Chick") {
    return new GrownAnimal("Chicken", 16, "Egg", 7);
  } else if (getName() == "Lamb") {
    return new GrownAnimal("Sheep", 20, "Wool", 9);
  } else if (getName() == "Calf") {
    return new GrownAnimal("Cow", 25, "Milk", 12);
  }
  return nullptr;  // Return nullptr if no matching young animal is found
}

// Displays the young animal's name, price, and type, with item count in boxes
// (override)
void YoungAnimal::display() const {
  cout << "[ " << getItemCount() << "x ] " << "Young Animal: " << getName()
       << ", Price: " << getPrice() << " gold (Type: " << getType() << ")\n";
}

// serialize and deserialize young animal to and from a file
void YoungAnimal::serialize(std::ofstream& outFile) const {
  outFile << "YoungAnimal " << getName() << " " << getPrice() << " "
          << getType() << " " << getItemCount() << "\n";
}

YoungAnimal* YoungAnimal::deserialize(std::ifstream& inFile) {
  string name, type;
  int price, count;

  // Error checking while reading from file
  if (!(inFile >> name >> price >> type >> count)) {
    cerr << "Error reading young animal data from file." << endl;
    return nullptr;  // Return nullptr if reading fails
  }

  // Create a new young animal object
  YoungAnimal* youngAnimal = new YoungAnimal(name, price, type);
  // Use the setter method to set item count
  youngAnimal->setItemCount(count);
  return youngAnimal;
}