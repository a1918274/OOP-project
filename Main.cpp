#include "MainMenu.h"
#include "Game.h"

// Main function to start the game
int main() {
    Game game;              // Create a Game object
    MainMenu menu(&game);   // Pass the Game instance to MainMenu
    menu.displayMenu();     // Display the main menu
    return 0;               // Return success
}
