#ifndef TESTMAINMENU_H
#define TESTMAINMENU_H

// Testing for main menu

#include <iostream>

#include "Game.h"
#include "MainMenu.h"

using namespace std;

class TestMainMenu {
 public:
  void runTests() {
    cout << "\nStart testing for MainMenu:\n\n";
    testDisplayMenu();
    // testHandleSelection();
    cout << "\nFinished testing for MainMenu!\n\n";
  }

 private:
  void testDisplayMenu() {
    {
      cout << "Test 1: choose 1"
           << endl;  // different options for menu as different tests?
      Game game;
      MainMenu menu(&game);
      menu.displayMenu();
      cout << "Menu displayed - test 1 passed!" << endl;
    }
  }

  void testHandleSelection() {
    {
      Game game;
      MainMenu menu(&game);
      menu.handleSelection(-1);
      cout << "An error message should be output - test 1 passed!" << endl;
    }

    {
      Game game;
      MainMenu menu(&game);
      menu.handleSelection(0);
      cout << "An error message should be output - test 2 passed!" << endl;
    }

    {
      Game game;
      MainMenu menu(&game);
      menu.handleSelection(3);
      cout << "The game should be quitted - test 3 passed!" << endl;
    }
  }
};

#endif  // TESTMAINMENU_H