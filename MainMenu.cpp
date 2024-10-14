#include "MainMenu.h"

#include <iostream>

#include "ValidNumberCheck.h"

using namespace std;

// Constructor to initialize the MainMenu with a Game instance
MainMenu::MainMenu(Game* gameInstance) : game(gameInstance) {}

// Displays the main menu
void MainMenu::displayMenu() {
  string input;  // Change to string to handle input
  while (true) {
    cout << "_____________________________________\n";
    cout << "Welcome to Happy Life Farm :)\n\n";
    cout << "Select a number to begin\n";
    cout << "1. New Game\n";
    cout << "2. Load Game\n";
    cout << "3. Quit Game\n";
    cout << "Choose an option: ";
    cin >> input;  // Read input as a string

    // Validate the input
    if (ValidNumberCheck::isValidNumber(input)) {
      int choice = stoi(input);  // Convert to integer
      handleSelection(choice);   // Handle the user's selection
    } else {
      cout << "Please stop trying to break the game :(\n";  // Error message for invalid input
    }
  }
}

// Handles the user's menu selection
void MainMenu::handleSelection(int choice) {
  switch (choice) {
    case 1:
      game->initializeGame();  // Initialize a new game
      game->play();            // Start a new game
      break;
    case 2:
      game->loadGame();  // Load the last saved game
      game->play();      // Start the game with the loaded state
      break;
    case 3:
      exit(0);  // Quit the game
      break;
    default:
      cout << "Invalid choice. Please try again.\n";  // Error message for invalid choice
  }
}