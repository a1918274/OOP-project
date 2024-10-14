#include "Seed.h"
#include "Plant.h"

#include <iostream>

using namespace std;

// constructor to initialize a seed object to item class
// itemCount is initialized ti 1 via the base constructor
Seed::Seed(const string& n, int p) : Item(n, p, 1) {}

// display the seed's name and price (override method from parent class)
void Seed::display() const {
  cout << "[ " << getItemCount() << "x ] "
         << "Seed: " << getName()
         << ", Price: " << getPrice() << " gold\n";
}

// returns the type of plant that the seed grows into
string Seed::getPlantType() const {
    if (getName() == "Potato(Seeds)") {
        return "Potatoes";
    } else if (getName() == "Corn(Seeds)") {
        return "Corn";
    } else if (getName() == "Tomato(Seeds)") {
        return "Tomatoes";
    }
    return ""; // Return an empty string if no matching seed is found
}


// grow the seed into a plant
Plant* Seed::grow() const {
  // turn seed into plant and return plant pointer
  if (getName() == "Potato(Seeds)") {
    return new Plant("Potatoes", 4, 5);
  } else if (getName() == "Corn(Seeds)") {
    return new Plant("Corn", 8, 14);
  } else if (getName() == "Tomato(Seeds)") {
    return new Plant("Tomatoes", 11, 22);
  }

  // return nullptr if no matching seed is found
  return nullptr;
}

// serialize the seed to a file
void Seed::serialize(std::ofstream& outFile) const {
  // using the getting methods for name and price
    outFile << "Seed " << getName() << " " << getPrice() << " " << getItemCount() << "\n";
}


// deserialize a seed from a file
Seed* Seed::deserialize(std::ifstream& inFile) {
    string name;
    int price, count;


    // Error checking for reading from file
    if (!(inFile >> name >> price >> count)) {
        cerr << "Error reading seed data from file." << endl;
        return nullptr; // Handle read failure
    }


    Seed* seed = new Seed(name, price); // Create a new seed object
    seed->setItemCount(count); // Set item count using the setter
    return seed;
}

