#include "Seed.h"
// include plant file here

#include <iostream>

using namespace std;

// constructor to initialize a seed object to item class
Seed::Seed(const string& name, int price) : Item(name, price) {}

// display the seed's name and price (override method from parent class)
void Seed::display() const {
  cout << "Seed: " << name << ", Price: " << price << " gold\n";
}

// grow the seed into a plant
Plant* Seed::grow() const {
  // turn seed into plant and return plant pointer
  if (name == "Potato(Seeds)") {
    // return potato plant
  } else if (name == "Corn(Seeds)") {
    // return corn plant
  } else if (name == "Tomato(Seeds)") {
    // return tomato plant
  }

  // return nullptr if no matching seed is found
  return nullptr;
}