#define MAINMENU_H

#include "Game.h" // Include the Game class

class MainMenu {
private:
    Game* game; // Pointer to the Game instance

public:
    // Constructor
    MainMenu(Game* gameInstance);

    // Display the main menu
    void displayMenu();

    // Handle menu selection
    void handleSelection(int choice);
};

#endif // MAINMENU_H