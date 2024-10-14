#ifndef ITEM_H
#define ITEM_H

#include <fstream>
#include <string>

// Abstract class that contains the information about each ‘item’, specifically
// name and price (i.e. the name and price of either a crop or animal).
// Item class is the parent class for seed, plant, animal, dog

// Abstract class representing an item in the game
class Item {
protected:
  std::string name; // Name of the item
  int price;        // Price of the item
  int itemCount;    // Count of the item

public:
  // Constructor
  Item(const std::string &n, int p, int count); // Initializes an item

  // Destructor
  virtual ~Item(); // Virtual destructor

  // Methods
  virtual void display() const = 0; // Displays item details
  void incrementCount();            // Increments the item count
  void resetItemCount();            // Resets the item count to one

  // Getters
  std::string getName() const;      // Returns the item's name
  int getPrice() const;             // Returns the item's price
  int getItemCount() const;         // Returns the item's count

  // Setters
  void setItemCount(int count);     // Sets the item's count

  // Serialization
  virtual void serialize(std::ofstream &outFile) const = 0; // Serializes item to a file
  static Item *deserialize(std::ifstream &inFile);          // Static method for deserialization
};

#endif // ITEM_H