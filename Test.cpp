// main file for testing all other test files
// include all test files here
#include "TestMainMenu.h"
#include "TestDayManager.h"
#include "TestValidNumberCheck.h"
#include "TestWeather.h"
#include "TestDog.h"
#include "TestPlant.h"
#include "YoungAnimal.h"
#include "GrownAnimal.h"

int main() {
  
  // [ MENU TESTS ]

  // TestMainMenu testMainMenu;
  // testMainMenu.runTests();

  TestWeather testWeather;
  testWeather.runTests();

  // TestDog testDog;
  // testDog.runTests();

  // TestPlant testPlant;
  // testPlant.runTests();

  // TestYoungAnimal testYoungAnimal;
  // testYoungAnimal.runTests();

  return 0;
}