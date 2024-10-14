#ifndef GAME_H
#define GAME_H

#include "Inventory.h"
#include "Shop.h"
#include "DayManager.h"
#include "Weather.h"

// Class representing the game itself
class Game {
private:
  int gold;                     // Player's gold
  DayManager dayManager;        // Instance for managing days
  Inventory inventory;          // Player's inventory
  Shop shop;                    // Instance for the shop
  Weather weather;              // Instance for the weather

public:
  // Constructor
  Game();                       // Initializes the game

  // Game Control Functions
  void initializeGame();        // Initializes a new game
  void displayMenu();           // Displays the game menu
  void buyItem();               // Handles item purchasing
  void tendToItems();           // Tends to items in inventory
  void sellItems();             // Handles selling items
  void displayInventory();      // Displays the player's inventory
  void sleep();                 // Resets actions by sleeping
  void play();                  // Main function to play the game
  void saveGame();              // Saves the current game state
  void loadGame();              // Loads a saved game state
};

#endif // GAME_H