#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

// Constructor to initialize game state
Game::Game() : gold(20), dayManager(3), shop(), {
}

// Initializes a new game
void Game::initializeGame() {
    gold = 20;                      // Reset gold
    dayManager.reset();             // Reset day manager
    inventory.clear();              // Clear inventory
    weather.generateWeather();      // Generate initial weather
}

// Displays the menu with available actions
void Game::displayMenu() {

    cout << "_____________________________________\n\n\n";
    cout << "[ Day: " << dayManager.getDay();
    cout << ", Actions remaining: " << dayManager.getActions() << " ]\n";
    cout << "[ Weather: << << ]\n";
    cout << "[ Gold: " << gold << " ]\n\n";
    cout << "( Choose a number to act on: )\n";
    cout << "1. Buy\n";
    cout << "2. Tend to items\n";
    cout << "3. Sell items\n";
    cout << "4. Check Inventory\n";
    cout << "5. Sleep\n\n";
    cout << "9. Save Game\n";
    cout << "0. Return to Main Menu\n";
}

void Game::buyItem() {
    shop.displayItems();                    // Display items from the shop

    string input;
    cin >> input;

    cout << "You return to your farm!\n";   // General message after interacting with the shop
    dayManager.performAction();             // Perform action at the end of buy
}

void Game::tendToItems() {
    if (inventory.getItems().empty()) {
        cout << "You have nothing to tend to.\n";
        return;
    }

    cout << "\nYou tend to your farm:\n";
    vector<Item*> itemsToRemove; // Track items to remove

    size_t count = inventory.getItems().size();
    for (size_t i = 0; i < count; i++) {
        Item* item = inventory.getItems()[i];

        // Check if the item is a Seed, add a plant, then remove

        // Check if the item is a YoungAnimal, add a GrownAnimal, then remove


    // Remove all marked items from the inventory
    for (auto item : itemsToRemove) {
        inventory.removeItem(item);
    }
}

void Game::sellItems() {
    int totalSale = 0;
    for (auto it = inventory.getItems().begin(); it != inventory.getItems().end();) {
        Item* item = *it;

    // Potential code for selling plants
        if () {
            totalSale += plant->getSellPrice();
            inventory.removeItem(item);
            cout << plant->getName() << " sold for " << plant->getSellPrice() << " gold.\n";
            delete plant; // Free memory
            it = inventory.getItems().begin(); // Restart loop due to removal

        } else if () {
            // Code for Grown animal without selling the animal

        } else {
            ++it; // Move to the next item
        }
    }

    gold += totalSale; // Update player's gold
    cout << "Total sale: " << totalSale << " gold.\n";
}

// Displays the player's inventory
void Game::displayInventory() {
    inventory.display();
}

// Resets actions for a new day and advances the day counter
void Game::sleep() {
    cout << "You have chosen to sleep a bit earlier. Good choice\n";
    cout << "Day  <<  <<  comes to an end.\n";

    // Generate produce for all GrownAnimals?

}

// Save the game state
void Game::saveGame() {
    cout << "You have saved the game";
}

// Load the game state
void Game::loadGame() {
    cout << "You have loaded the game";
}

// Main game loop
void Game::play() {
        // Display the menu to the player
        displayMenu(); 

        string choice;
        cin >> choice;

        if (choice == "1") {
            buyItem();                  // Buy an item
        } else if (choice == "2") {
            tendToItems();              // Tend to items in inventory
        } else if (choice == "3") {
            sellItems();                // Sell items in inventory
        } else if (choice == "4") {
            displayInventory();         // Show player's inventory
        } else if (choice == "5") {
            sleep();                    // End the day
        } else if (choice == "9") {
            saveGame();                 // Save game
        } else if (choice == "0") {
            cout << "MainMenu";                     // Return to main menu
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
