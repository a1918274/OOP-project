#include "MainMenu.h"
#include <iostream>

using namespace std;

// Constructor
MainMenu::MainMenu(Game* gameInstance) : game(gameInstance) {}

// Displays the main menu
void MainMenu:: displayMenu() {
    string input; // Change to string to handle input
    while (true) {
        cout << "\nWelcome to Happy Life Farm :)\n\n";
        cout << "select a number to being\n";
        cout << "1. New Game\n";
        cout << "2. Load Game\n";
        cout << "3. Quit Game\n";
        cout << "Choose an option: ";
        cin >> input; // Read input as a string

        // Validate input here?

    }
}

// Handles menu selection
void MainMenu::handleSelection(int choice) {
    switch (choice) {
        case 1:
            game->initializeGame();     //Initialize a new game
            game->play();               //Start a new game
            break;
        case 2:
            game->loadGame();           //Load the last saved game
            game->play();               //Start the game with the loaded state
            break;
        case 3:
            exit(0);                    //Quit the game
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}