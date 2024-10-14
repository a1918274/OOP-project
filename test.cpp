// main file for testing all other test files
// include all test files here
#include "TestDayManager.h"
#include "TestMainMenu.h"
#include "TestValidNumberCheck.h"

int main() {
  //   TestDayManager testDayManger;
  //   testDayManger.runTests();

  //   TestValidNumberCheck testValidNumberCheck;
  //   testValidNumberCheck.runTests();

  TestMainMenu testMainMenu;
  testMainMenu.runTests();

  return 0;
}