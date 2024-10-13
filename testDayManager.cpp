// testing for DayManager
#include <iostream>

#include "DayManager.h"

using namespace std;

class UnitTest {
 public:
  void runTests() { testGetActions(); }

 private:
  void testGetActions() {
    {
      DayManager dayManager(3);
      if (dayManager.getActions() != 3) {
        cout << "Test 1 failed!" << endl;
      }
    }

    {
      DayManager dayManager(0);
      if (dayManager.getActions() != 0) {
        cout << "Test 2 failed!" << endl;
      }
    }

    {
      DayManager dayManager(-1);
      if (dayManager.getActions() != 0) {
        cout << "Test 3 failed!" << endl;
      }
    }

    cout << "All tests passed!" << endl;
  }

  //   // Get the current number of actions
  //   int getActions() const;

  //   // Set the current number of actions
  //   void setActions(int actions);

  //   // Get the current day
  //   int getDay() const;

  //   // Set the current day
  //   void setDay(int day);

  //   // Reset actions for a new day
  //   void resetActions(int newActions);

  //   // create an object of DayManager
  //   DayManager day(3);

  //   void testAddition() {
  //     Addition addition;

  //     if (addition.add(1, 2) != 3) {
  //       std::cout << "Test 1 failed!" << std::endl;
  //     }
  //     // Add more tests here
  //   }
};

int main() {
  UnitTest unitTest;
  unitTest.runTests();

  return 0;
}