// main file for testing all other test files
// include all test files here
#include "TestDayManager.h"
#include"TestValidNumberCheck.h"

int main() {
//   TestDayManager testDayManger;
//   testDayManger.runTests();

  TestValidNumberCheck testValidNumberCheck;
  testValidNumberCheck.runTests();

  return 0;
}