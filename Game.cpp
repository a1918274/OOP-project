#include "Game.h"
#include "ValidNumberCheck.h"
#include "Seed.h"
#include "YoungAnimal.h"
#include "Plant.h"
#include "GrownAnimal.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor to initialize game state
Game::Game() : gold(20), dayManager(3), shop(), {
    weather.generateWeather();      // Initialize the weather
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
    string weatherString = weather.getWeatherString(); // Fetch formatted weather string

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
    shop.displayItems(); // Display items from the shop

    string input;
    cin >> input;

    // Validate input using the ValidNumberCheck class
    if (!ValidNumberCheck::isValidNumber(input)) {
        cout << "The shop keeper looks at you puzzled and advises that they don't have that.\n";
        return;
    }

    int choice = stoi(input);
    bool boughtDog = shop.buyItem(choice, gold, inventory);

    if (boughtDog) {
        cout << "\nPetting the doggo, you think to yourself...\n"
             << "After working hard, you have finally found happiness.\n\n"
             << "░▄▀▄▀▀▀▀▄▀▄░░░░░░░░░\n"
             << "░█░░░░░░░░▀▄░░░░░░▄░\n"
             << "█░░▀░░▀░░░░░▀▄▄░░█░█\n"
             << "█░▄░█▀░▄░░░░░░░▀▀░░█   Woof! The doggo barks!\n"
             << "█░░▀▀▀▀░░░░░░░░░░░░█\n"
             << "█░░░░░░░░░░░░░░░░░░█\n"
             << "█░░░░░░░░░░░░░░░░░░█\n"
             << "░█░░▄▄░░▄▄▄▄░░▄▄░░█░\n"
             << "░█░▄▀█░▄▀░░█░▄▀█░▄▀░\n"
             << "░░▀░░░▀░░░░░▀░░░▀░░░\n\n"
             << "_Thank You for Playing_\n";
        exit(0); // Exit the game immediately
    }

    cout << "You return to your farm!\n"; // General message after interacting with the shop
    dayManager.performAction(); // Perform action at the end of buy
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

        // Check if the item is a Seed
        if (Seed* seed = dynamic_cast<Seed*>(item)) {
            itemsToRemove.push_back(item); // Mark seed for removal
            Plant* newPlant = seed->grow(); // Grow the seed into a plant
            if (newPlant) {
                inventory.addItem(newPlant); // Add the new plant to inventory
                cout << seed->getName() << " has grown into " << newPlant->getName() << "!\n";
            }
        }
        // Check if the item is a YoungAnimal
        else if (YoungAnimal* youngAnimal = dynamic_cast<YoungAnimal*>(item)) {
            GrownAnimal* grownAnimal = youngAnimal->grow(); // Grow the young animal
            if (grownAnimal) {
                itemsToRemove.push_back(item); // Mark for removal
                inventory.addItem(grownAnimal); // Add the grown animal
                cout << youngAnimal->getName() << " has grown into " << grownAnimal->getName() << "!\n";
            }
        }
    }

    // Remove all marked items from the inventory
    for (auto item : itemsToRemove) {
        inventory.removeItem(item);
    }

    // Consume an action at the end of tending
    dayManager.performAction();
}

void Game::sellItems() {
    int totalSale = 0;
    for (auto it = inventory.getItems().begin(); it != inventory.getItems().end();) {
        Item* item = *it;

        if (Plant* plant = dynamic_cast<Plant*>(item)) {
            totalSale += plant->getSellPrice();
            inventory.removeItem(item);
            cout << plant->getName() << " sold for " << plant->getSellPrice() << " gold.\n";
            delete plant; // Free memory
            it = inventory.getItems().begin(); // Restart loop due to removal
        } else if (GrownAnimal* animal = dynamic_cast<GrownAnimal*>(item)) {
            int produceValue = animal->getProduceValue();
            int produceCount = animal->getProduceCount();

            if (produceCount > 0) {
                totalSale += produceValue * produceCount; // Calculate sale based on produce value
                animal->clearProduce(); // Clear produce count after selling
                cout << animal->getName() << "'s produce sold for " << (produceValue * produceCount) << " gold.\n";
            } else {
                cout << animal->getName() << " has no produce to sell.\n"; // Inform if no produce available
            }
            it++; // Move to the next item without removing the animal
        } else {
            ++it; // Move to the next item
        }
    }

    gold += totalSale; // Update player's gold
    cout << "Total sale: " << totalSale << " gold.\n";
    dayManager.performAction();
}

// Displays the player's inventory
void Game::displayInventory() {
    inventory.display();
}

// Resets actions for a new day and advances the day counter
void Game::sleep() {
    cout << "You have chosen to sleep a bit earlier. Good choice\n";
    cout << "Day  <<  <<  comes to an end.\n";

    // Generate produce for all GrownAnimals
    for (auto item : inventory.getItems()) {
        if (auto animal = dynamic_cast<GrownAnimal*>(item)) {
            animal->produceItem(); // Call the produce method for animals
        }
    }

    dayManager.resetActions(3);                 // Reset actions for the new day
    dayManager.nextDay();                       // Advance to the next day
    weather.generateWeather();                  // Generate new weather for the new day
    weather.applyWeatherEffects(dayManager);    // Apply weather effects for the new day
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
    while (true) {
        // Check if actions are exhausted
        if (dayManager.getActions() <= 0) {
            cout << "You've worked hard and decided to call it a night!\n";
            dayManager.nextDay();
            dayManager.resetActions(3);
            weather.generateWeather(); // Generate new weather for the new day
            weather.applyWeatherEffects(dayManager); // Apply weather effects at the start of the new day
            continue; // Restart the loop for the new day
        }

        // Display the menu to the player
        displayMenu();

        string choice;
        cin >> choice;

        // Validate if the input is a valid number
        if (!ValidNumberCheck::isValidNumber(choice)) {
            cout << "Your brain looks at you puzzled and advises you to read the options again.\n";
            continue; // Restart the loop for valid input
        }

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
            return; // Return to main menu
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}