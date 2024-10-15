// Main file for testing

#include "TestDayManager.h"
#include "TestDog.h"
#include "TestGame.h"
#include "TestGrownAnimal.h"
#include "TestInventory.h"
#include "TestMainMenu.h"
#include "TestPlant.h"
#include "TestSeed.h"
#include "TestShop.h"
#include "TestValidNumberCheck.h"
#include "TestWeather.h"
#include "TestYoungAnimal.h"

int main() {
  cout << "Start testing for all files:\n\n";

  // [ MENU TESTS ]

  TestGame testGame;
  testGame.runTests();

  // [ GAME LOGIC TESTS ]

  TestDayManager testDayManger;
  testDayManger.runTests();

  TestWeather testWeather;
  testWeather.runTests();

  TestValidNumberCheck testValidNumberCheck;
  testValidNumberCheck.runTests();

  TestShop testShop;
  testShop.runTests();

  TestInventory testInventory;
  testInventory.runTests();

  // [ ITEM TESTS ]

  TestDog testDog;
  testDog.runTests();

  TestSeed testSeed;
  testSeed.runTests();

  TestPlant testPlant;
  testPlant.runTests();

  TestYoungAnimal testYoungAnimal;
  testYoungAnimal.runTests();

  TestGrownAnimal testGrownAnimal;
  testGrownAnimal.runTests();

  cout << "Finished testing for all files!" << endl;

  return 0;
}