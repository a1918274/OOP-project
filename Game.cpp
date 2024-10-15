#include "Game.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "GrownAnimal.h"
#include "Plant.h"
#include "Seed.h"
#include "ValidNumberCheck.h"
#include "YoungAnimal.h"

using namespace std;

// Constructor to initialize game state
Game::Game() : gold(20), dayManager(3), shop(), weather() {
  weather.setWeather(Weather::SUNNY);  // Initialize the weather
}

// Getters

// Return current gold
int Game::getGold() { return gold; }

// Return current day
int Game::getDay() { return dayManager.getDay(); }

// Return current number of actions
int Game::getActions() { return dayManager.getActions(); }

// Return inventory vector
Inventory& Game::getInventory() { return inventory; }

// Initializes a new game
void Game::initializeGame() {
  gold = 20;                           // Reset gold
  dayManager.reset();                  // Reset day manager
  inventory.clear();                   // Clear inventory
  weather.setWeather(Weather::SUNNY);  // Sunny on Day 1
}

// Displays the menu with available actions
void Game::displayMenu() {
  string weatherString =
      weather.getWeatherString();  // Fetch formatted weather string

  cout << "\n_____________________________________\n\n";
  cout << "[ Day: " << dayManager.getDay();
  cout << ", Actions remaining: " << dayManager.getActions() << " ]\n";
  cout << "[ Weather: " << weatherString << " ]\n";
  cout << "[ Gold: " << gold << " ]\n\n";
  cout << "( Choose a number to act on: )\n";
  cout << "1. Buy Seeds/Animals\n";
  cout << "2. Tend to Farm\n";
  cout << "3. Sell all Produce\n";
  cout << "4. Check Inventory\n";
  cout << "5. Sleep\n\n";
  cout << "9. Save Game\n";
  cout << "0. Return to Main Menu\n\n";
}

// Interacts with the shop and buys items into the player's inventory
void Game::buyItem() {
  shop.displayItems();  // Display items from the shop

  string input;
  cin >> input;

  // Validate input using the ValidNumberCheck class
  if (!ValidNumberCheck::isValidNumber(input)) {
    cout << "\nThe shop keeper looks at you puzzled and advises that they "
            "don't have that.\n";
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
    exit(0);  // Exit the game immediately
  }

  cout << "You return to your farm!\n";  // General message after interacting
                                         // with the shop
  dayManager.performAction();            // Perform action at the end of buy
}

void Game::tendToItems() {
  if (inventory.getItems().empty()) {
    cout << "\nYou have nothing to tend to.\n";
    return;
  }

  cout << "\nYou tend to your farm:\n";
  vector<Item*> itemsToRemove;  // Track items to remove
  vector<Item*> itemsToAdd;     // Track items to add
  bool seedsGrown = false;      // Flag to track if any seeds were grown
  bool animalsGrown = false;    // Flag to track if any animals were grown

  // First loop: Collect seeds/plants/animals to process without modifying the
  // inventory yet
  for (auto it = inventory.getItems().begin(); it != inventory.getItems().end();
       ++it) {
    Item* item = *it;

    // Check if the item is a Seed
    if (Seed* seed = dynamic_cast<Seed*>(item)) {
      string plantType =
          seed->getPlantType();  // Get the type of plant the seed grows into

      if (!plantType.empty()) {
        // Check if the plant already exists in the inventory
        auto plantIt = std::find_if(
            inventory.getItems().begin(), inventory.getItems().end(),
            [&plantType](Item* i) { return i->getName() == plantType; });

        if (plantIt != inventory.getItems().end()) {
          // If found, increment the plant's item count based on the seed count
          (*plantIt)->setItemCount((*plantIt)->getItemCount() +
                                   seed->getItemCount());
        } else {
          // Check if the plant already exists in the itemsToAdd vector
          auto newPlantIt = std::find_if(
              itemsToAdd.begin(), itemsToAdd.end(),
              [&plantType](Item* i) { return i->getName() == plantType; });

          if (newPlantIt != itemsToAdd.end()) {
            // If the plant exists in itemsToAdd, increment its count
            (*newPlantIt)
                ->setItemCount((*newPlantIt)->getItemCount() +
                               seed->getItemCount());
          } else {
            // If the plant doesn't exist in either, grow the seed into a plant
            // and add it
            Plant* newPlantInstance =
                seed->grow();  // Grow the seed into a new plant
            if (newPlantInstance) {
              newPlantInstance->setItemCount(
                  seed->getItemCount());  // Set the correct count
              itemsToAdd.push_back(
                  newPlantInstance);  // Queue plant to be added
            }
          }
        }
        seedsGrown = true;  // Mark that at least one seed has grown
      }
      seed->resetItemCount();         // Reset seed item count to zero
      itemsToRemove.push_back(item);  // Mark the seed for removal
    }

    // Check if the item is a YoungAnimal (similar logic can be applied here)
    else if (YoungAnimal* youngAnimal = dynamic_cast<YoungAnimal*>(item)) {
      string animalType =
          youngAnimal
              ->getGrownAnimalType();  // Get the type of animal being grown

      // Check if the animal already exists in the inventory
      auto animalIt = std::find_if(
          inventory.getItems().begin(), inventory.getItems().end(),
          [&animalType](Item* i) { return i->getName() == animalType; });

      if (animalIt != inventory.getItems().end()) {
        (*animalIt)->setItemCount((*animalIt)->getItemCount() +
                                  youngAnimal->getItemCount());
      } else {
        // Check if the grown animal already exists in itemsToAdd vector
        auto newAnimalIt = std::find_if(
            itemsToAdd.begin(), itemsToAdd.end(),
            [&animalType](Item* i) { return i->getName() == animalType; });

        if (newAnimalIt != itemsToAdd.end()) {
          (*newAnimalIt)
              ->setItemCount((*newAnimalIt)->getItemCount() +
                             youngAnimal->getItemCount());
        } else {
          // If the grown animal doesn't exist, grow the young animal into a
          // grown one
          GrownAnimal* grownAnimal =
              youngAnimal->grow();  // Grow the young animal
          if (grownAnimal) {
            grownAnimal->setItemCount(
                youngAnimal->getItemCount());  // Set the correct count
            itemsToAdd.push_back(
                grownAnimal);  // Queue grown animal to be added
          }
        }
      }
      animalsGrown = true;            // Mark that at least one animal has grown
      youngAnimal->resetItemCount();  // Reset young animal item count to zero
      itemsToRemove.push_back(item);  // Mark the young animal for removal
    }
  }

  // Second loop: Remove all marked items from the inventory
  for (auto item : itemsToRemove) {
    inventory.removeItem(item);
  }

  // Add all new plants or grown animals to the inventory
  for (auto item : itemsToAdd) {
    inventory.addItem(item);
  }

  // Print the general message if any seeds were grown
  if (seedsGrown) {
    cout << "Your seeds grew into plants and are ready to be harvested and "
            "sold.\n";
  }

  // Print the general message if any young animals were grown
  if (animalsGrown) {
    cout << "Your young animals have grown into adult animals.\n";
    cout << "Grown animals will stay in your farm and produce sellable items "
            "at the end of each day.\n";
  }

  // Consume an action at the end of tending
  dayManager.performAction();
}

// Sells all items for gold and returns gold to player
void Game::sellItems() {
  cout << "\nYou harvest and sell all the produce that is ready:\n";
  int totalSale = 0;            // Initialize total sale amount
  vector<Item*> itemsToRemove;  // Track plants to remove
  vector<Item*> itemsToUpdate;  // Track animals to update (for produce)

  // First loop: Collect items to process without modifying the inventory yet
  for (auto it = inventory.getItems().begin(); it != inventory.getItems().end();
       ++it) {
    Item* item = *it;

    // Check if the item is a Plant
    if (Plant* plant = dynamic_cast<Plant*>(item)) {
      int plantCount = plant->getItemCount();
      int sellPrice = plant->getSellPrice();

      // Calculate total sale for this plant type
      totalSale += sellPrice * plantCount;
      cout << plant->getName() << " sold for " << (sellPrice * plantCount)
           << " gold.\n";

      itemsToRemove.push_back(
          item);  // Mark the plant for removal after selling

      // Check if the item is a GrownAnimal
    } else if (GrownAnimal* animal = dynamic_cast<GrownAnimal*>(item)) {
      int produceValue = animal->getProduceValue();
      int produceCount = animal->getProduceCount();
      int animalCount = animal->getItemCount();

      // If the animal has produce to sell
      if (produceCount > 0) {
        // Calculate total sale based on produce value and animal count
        totalSale += produceValue * produceCount * animalCount;

        cout << animal->getName() << "'s produce sold for "
             << (produceValue * produceCount * animalCount) << " gold.\n";

        animal->clearProduce();           // Clear produce count after selling
        itemsToUpdate.push_back(animal);  // Mark the animal for update
      } else {
        cout << animal->getName()
             << " has no produce to sell.\n";  // Inform if no produce available
      }
    }
  }

  // Second loop: Remove all marked plants from the inventory
  for (auto item : itemsToRemove) {
    inventory.removeItem(
        item);  // This handles deletion and removal from inventory
  }

  gold += totalSale;  // Update player's gold
  cout << "\nTotal sale: " << totalSale << " gold.\n";

  // Consume an action at the end of selling
  dayManager.performAction();
}

// Displays the player's inventory
void Game::displayInventory() {
  inventory.display();  // Call the display method of the inventory
}

// Resets actions for a new day and advances the day counter
void Game::sleep() {
  cout << "\nYou have chosen to sleep a bit earlier. Good choice\n";
  cout << "Day " << dayManager.getDay() << " comes to an end.\n";

  // Generate produce for all GrownAnimals
  for (auto item : inventory.getItems()) {
    if (auto animal = dynamic_cast<GrownAnimal*>(item)) {
      animal->produceItem();  // Call the produce method for animals
    }
  }

  // Reset actions and advance to the next day
  dayManager.setActions(3);
  dayManager.nextDay();
  weather.generateWeather();  // Generate new weather for the new day
  weather.applyWeatherEffects(
      dayManager);  // Apply weather effects for the new day
}

// Save the game state
void Game::saveGame() {
  std::ofstream outFile("savegame.txt");
  if (!outFile) {
    cout << "Error saving game.\n";
    return;  // Early exit if file can't be opened
  }

  // Save game state to the file
  outFile << gold << "\n";
  outFile << dayManager.getDay() << "\n";
  outFile << dayManager.getActions() << "\n";
  outFile << static_cast<int>(weather.getWeather())
          << "\n";  // Save weather as an integer

  // Save inventory items
  outFile << inventory.getItems().size() << "\n";  // Number of items
  for (auto item : inventory.getItems()) {
    item->serialize(outFile);  // Serialize each item
  }

  outFile.close();                  // Close the file
  cout << "\nGame state saved.\n";  // Inform user of success
}

// Load the game state
void Game::loadGame() {
  std::ifstream inFile("savegame.txt");
  if (!inFile) {
    cout << "Error loading game. No saved file found.\n";
    return;  // Early exit if file can't be opened
  }

  // Load game state from the file
  inFile >> gold;  // Load gold amount
  int day, actions;
  inFile >> day >> actions;  // Load day and actions

  dayManager.setDay(day);          // Set the loaded day
  dayManager.setActions(actions);  // Set the loaded actions

  // Load weather from the file and cast it to the enum type
  int weatherType;
  inFile >> weatherType;
  weather.setWeather(
      static_cast<Weather::Type>(weatherType));  // Cast back to enum

  // Clear existing inventory to prevent duplicates
  inventory.clear();

  // Load inventory items
  size_t itemCount;
  inFile >> itemCount;  // Get the number of items
  for (size_t i = 0; i < itemCount; ++i) {
    Item* item = Item::deserialize(inFile);  // Deserialize item based on type
    if (item) {
      inventory.addItem(item);  // Add item to inventory
    }
  }

  inFile.close();                    // Close the file
  cout << "\nGame state loaded.\n";  // Inform user of success
}

// Main game loop
void Game::play() {
  while (true) {
    // Check if actions are exhausted
    if (dayManager.getActions() <= 0) {
      cout << "\nYou've worked hard and decided to call it a night!\n";
      dayManager.nextDay();                     // Advance to the next day
      dayManager.setActions(3);                 // Reset actions for the new day
      weather.generateWeather();                // Generate new weather
      weather.applyWeatherEffects(dayManager);  // Apply weather effects

      // Generate produce for all GrownAnimals
      for (auto item : inventory.getItems()) {
        if (auto animal = dynamic_cast<GrownAnimal*>(item)) {
          animal->produceItem();  // Call the produce method for animals
        }
      }

      continue;  // Restart the loop for the new day
    }

    // Display the menu to the player
    displayMenu();

    string choice;
    cin >> choice;

    // Validate if the input is a valid number
    if (!ValidNumberCheck::isValidNumber(choice)) {
      cout << "\nYour brain looks at you puzzled and advises for you check the "
              "options again.\n";
      continue;  // Restart the loop for valid input
    }

    // Handle player choices
    if (choice == "1") {
      buyItem();  // Buy an item
    } else if (choice == "2") {
      tendToItems();  // Tend to items in inventory
    } else if (choice == "3") {
      sellItems();  // Sell items in inventory
    } else if (choice == "4") {
      displayInventory();  // Show player's inventory
    } else if (choice == "5") {
      sleep();  // End the day
    } else if (choice == "9") {
      saveGame();  // Save game
    } else if (choice == "0") {
      return;  // Return to main menu
    } else {
      cout
          << "\nOk seriously... Please stop trying to break the game.\n";  // Handle
                                                                           // invalid
                                                                           // choices
    }
  }
}