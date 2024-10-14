#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h" // Include the Game class

// Class representing the main menu for the game
class MainMenu {
private:
    Game* game; // Pointer to the Game instance

public:
    MainMenu(Game* gameInstance);       // Constructor

    void displayMenu();                 // Displays the main menu
    void handleSelection(int choice);   // Handles menu selection
};

#endif // MAINMENU_H