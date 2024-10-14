#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"

// MainMenu class is responsible for the function of the inital game menu, which
// allows the player to either start a new game, load a previous saved game, or
// quit the game

// Class representing the main menu for the game
class MainMenu {
 private:
  Game* game;  // Pointer to the Game instance

 public:
  // Constructor
  MainMenu(Game* gameInstance);      // Constructor

  // Methods
  void displayMenu();                // Displays the main menu
  void handleSelection(int choice);  // Handles menu selection
};

#endif  // MAINMENU_H