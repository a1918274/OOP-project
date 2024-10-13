// testing for DayManager
#include <iostream>

#include "DayManager.h"

using namespace std;

class UnitTest {
 public:
  void runTests() {
    testGetActions();
    testSetActions();
    testGetDay();
    testSetDay();
  }

 private:
  void testGetActions() {
    cout << "Testing for getAction:" << endl;
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

  void testSetActions() {
    cout << "Testing for setAction:" << endl;
    {
      DayManager dayManager(1);
      if (dayManager.getActions() != 1) {
        cout << "Test 1 constructor failed!" << endl;
      }
      dayManager.setActions(0);
      if (dayManager.getActions() != 0) {
        cout << "Test 1 failed!" << endl;
      }
    }

    {
      DayManager dayManager(1);
      if (dayManager.getActions() != 1) {
        cout << "Test 2 constructor failed!" << endl;
      }
      dayManager.setActions(3);
      if (dayManager.getActions() != 3) {
        cout << "Test 2 failed!" << endl;
      }
    }

    {
      DayManager dayManager(10);
      if (dayManager.getActions() != 10) {
        cout << "Test 3 constructor failed!" << endl;
      }
      dayManager.setActions(-3);
      if (dayManager.getActions() != 0) {
        cout << "Test 3 failed!" << endl;
      }
    }

    cout << "All tests passed!" << endl;
  }

  void testGetDay() {
    cout << "Testing for getDay:" << endl;

    {
      DayManager dayManager(1);
      if (dayManager.getDay() != 0) {
        cout << "Test 1 failed!" << endl;
      }
    }

    {
      DayManager dayManager(3);
      if (dayManager.getDay() != 0) {
        cout << "Test 2 failed!" << endl;
      }
    }

    {
      DayManager dayManager(-3);
      if (dayManager.getDay() != 0) {
        cout << "Test 3 failed!" << endl;
      }
    }

    cout << "All tests passed!" << endl;
  }

  void testSetDay() {
    cout << "Testing for setDay:" << endl;

    {
      DayManager dayManager(1);
      if (dayManager.getDay() != 0) {
        cout << "Test 1 constructor failed!" << endl;
      }
      dayManager.setDay(3);
      if (dayManager.getDay() != 3) {
        cout << "Test 1 failed!" << endl;
      }
    }

    {
      DayManager dayManager(3);
      if (dayManager.getDay() != 0) {
        cout << "Test 2 constructor failed!" << endl;
      }
      dayManager.setDay(0);
      if (dayManager.getDay() != 0) {
        cout << "Test 2 failed!" << endl;
      }
    }

    {
      DayManager dayManager(-1);
      if (dayManager.getDay() != 0) {
        cout << "Test 3 constructor failed!" << endl;
      }
      dayManager.setDay(-1);
      if (dayManager.getDay() != 0) {
        cout << "Test 3 failed!" << endl;
      }
    }

    cout << "All tests passed!" << endl;
  }
};

int main() {
  UnitTest unitTest;
  unitTest.runTests();

  return 0;
}