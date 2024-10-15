// main file for testing all other test files
// include all test files here
#include "TestDayManager.h"
#include "TestDog.h"
#include "TestMainMenu.h"
#include "TestValidNumberCheck.h"
#include "TestWeather.h"

int main() {
  //   TestDayManager testDayManger;
  //   testDayManger.runTests();

  //   TestValidNumberCheck testValidNumberCheck;
  //   testValidNumberCheck.runTests();

  // TestMainMenu testMainMenu;
  // testMainMenu.runTests();

  // TestWeather testWeather;
  // testWeather.runTests();

  TestDog testDog;
  testDog.runTests();

  return 0;
}