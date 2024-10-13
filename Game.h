#ifndef GAME_H
#define GAME_H

#include "Inventory.h"
#include "Shop.h"


class Game {
private:
    int gold;                   // Player's gold
    DayManager dayManager;      // Instance of DayManager to handle actions and days
    Inventory inventory;        // Player's inventory
    Shop shop;                  // Instance of Shop to handle buying/selling
    Weather weather;            // Instance of Weather to manage current weather

public:
    // Constructor to initialize game state
    Game();

    // Initializes a new game
    void initializeGame();

    // Function to display the game menu
    void displayMenu();

    // Function to buy an item
    void buyItem();

    // Function to tend to items
    void tendToItems();

    // Function to sell items
    void sellItems();

    // Function to display inventory
    void displayInventory();

    // Function to sleep and reset actions
    void sleep();

    // Main function to handle playing the game
    void play();

    // Function to save the game
    void saveGame();

    // Function to load the game
    void loadGame();
};


#endif // GAME_H