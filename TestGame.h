#ifndef TESTGAME_H
#define TESTGAME_H

// Testing for Game

#include <cassert>
#include <iostream>

#include "Game.h"
#include "Plant.h"
#include "Seed.h"

using namespace std;

class TestGame {
 public:
  void runTests() {
    cout << "\nStart testing for Game:\n\n";

    testInitializeGame();  // same as testing game constructor
    testDisplayMenu();
    testBuyItem();
    testTendToItems();
    testSellItems();
    testDisplayInventory();
    testSleep();
    testSaveAndLoadGame();

    cout << "\nFinished testing for Game!\n\n";
  }

 private:
  void testInitializeGame() {
    cout << "Testing for initializeGame:\n";

    {
      Game game;
      game.initializeGame();
      assert(game.getGold() == 20);
      assert(game.getDay() == 1);
      assert(game.getActions() == 3);
      assert(game.getInventory().getItems().empty());
    }

    cout << "Test initialize game passed!" << endl;
  }

  void testDisplayMenu() {
    cout << "Testing for displayMenu:\n";

    {
      Game game;
      game.displayMenu();
      cout << "Menu should be output with day = 0, 3 actions, weather = Sunny, "
              "20 gold\n";
    }

    cout << "Testing for displayMenu passed!" << endl;
  }

  void testBuyItem() {
    cout << "Testing for buyItem:\n";

    {
      Game game;
      game.initializeGame();

      cout << "Test 1: choose one item that is affordable to buy for testing\n";
      game.buyItem();  // needs to be simulated for input

      // assume buying item reduces gold and adds item to inventory
      assert(game.getGold() < 20);
      assert(!game.getInventory().getItems().empty());
    }

    cout << "Test for buyItem passed!" << endl;
  }

  void testTendToItems() {
    cout << "Testing for tendToItems:\n";

    {
      Game game;
      game.initializeGame();

      // adding seed to simulate the tending process
      Seed* potato = new Seed("Potato", 4);
      game.getInventory().addItem(potato);

      game.tendToItems();

      assert(game.getInventory().getItems().size() == 1);
      assert(game.getInventory().getItems()[0]->getName() == "Potato");
      assert(game.getInventory().getItems()[0]->getPrice() == 4);
    }

    cout << "Test for tendToItem passed!" << endl;
  }

  void testSellItems() {
    cout << "Testing for sellItems:\n";

    {
      Game game;
      game.initializeGame();

      // adding plant to simulate the selling process
      Plant* potato = new Plant("Potato", 4, 10);

      game.getInventory().addItem(potato);

      game.sellItems();

      assert(game.getGold() > 20);
      assert(game.getInventory().getItems().empty());
    }

    cout << "Test sellItem passed!" << endl;
  }

  void testDisplayInventory() {
    cout << "Testing displayInventory:\n";

    {
      Game game;
      game.initializeGame();

      // adding seed to inventory to display
      Seed* potato = new Seed("Potato", 4);

      game.getInventory().addItem(potato);

      cout << "Expected output: [ 1x ] Seed: Potato(Seeds), Price: 4 gold\n";
      cout << "Actual output: ";
      game.displayInventory();

      cout << "Inventory should be displayed correctly. Test displayInventory "
              "passed!"
           << endl;
    }
  }

  void testSleep() {
    cout << "Testing for sleep:\n";

    {
      Game game;
      game.initializeGame();

      game.sleep();

      assert(game.getDay() == 2);
      assert(game.getActions() == 3);
    }

    cout << "Test sleep passed!" << endl;
  }

  void testSaveAndLoadGame() {
    cout << "Testing for save and load game:\n";

    {
      Game game;
      game.initializeGame();

      // add seed to save
      Seed* potato = new Seed("Potato", 4);
      game.getInventory().addItem(potato);

      game.saveGame();

      Game loadedGame;
      loadedGame.loadGame();

      assert(loadedGame.getGold() == 20);
      assert(loadedGame.getDay() == 1);
      assert(loadedGame.getInventory().getItems().size() == 1);
      assert(loadedGame.getInventory().getItems()[0]->getName() == "Potato");
    }

    cout << "Test save and load game passed!" << endl;
  }
};

#endif  // TESTGAME_H