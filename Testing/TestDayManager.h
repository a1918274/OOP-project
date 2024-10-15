#ifndef TESTDAYMANAGER_H
#define TESTDAYMANAGER_H

// Testing for DayManager

#include <iostream>

#include "DayManager.h"

using namespace std;

class TestDayManager {
 public:
  void runTests() {
    cout << "\nStart testing for DayManager:\n\n";
    testGetActions();
    testSetActions();
    testGetDay();
    testSetDay();
    testNextDay();
    testPerformAction();
    testReset();
    cout << "\nFinished testing for DayManager!\n\n";
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
      if (dayManager.getActions() != 10) {
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

  void testNextDay() {
    cout << "Testing for nextDay:" << endl;

    {
      DayManager dayManager(3);
      dayManager.nextDay();
      if (dayManager.getDay() != 1) {
        cout << "Test 1 failed!" << endl;
      }
    }

    {
      DayManager dayManager(3);
      dayManager.setDay(10);
      dayManager.nextDay();
      if (dayManager.getDay() != 11) {
        cout << "Test 2 failed!" << endl;
      }
    }

    {
      DayManager dayManager(0);
      dayManager.setDay(0);
      dayManager.nextDay();
      if (dayManager.getDay() != 1) {
        cout << "Test 3 failed!" << endl;
      }
    }

    cout << "All tests passed!" << endl;
  }

  void testPerformAction() {
    cout << "Testing for performAction:" << endl;

    {
      DayManager dayManager(3);
      dayManager.performAction();
      if (dayManager.getActions() != 2) {
        cout << "Test 1 failed!" << endl;
      }
    }

    {
      DayManager dayManager(0);
      dayManager.performAction();
      if (dayManager.getActions() != 0) {
        cout << "Test 2 failed!" << endl;
      }
    }

    {
      DayManager dayManager(100);
      dayManager.performAction();
      if (dayManager.getActions() != 99) {
        cout << "Test 3 failed!" << endl;
      }
    }

    cout << "All tests passed!" << endl;
  }

  void testReset() {
    cout << "Testing for reset:" << endl;

    {
      DayManager dayManager(3);
      dayManager.reset();
      if (dayManager.getActions() != 3 && dayManager.getDay() != 1) {
        cout << "Test 1 failed!" << endl;
      }
    }

    {
      DayManager dayManager(100);
      dayManager.reset();
      if (dayManager.getActions() != 3 && dayManager.getDay() != 1) {
        cout << "Test 2 failed!" << endl;
      }
    }

    {
      DayManager dayManager(-1);
      dayManager.reset();
      if (dayManager.getActions() != 3 && dayManager.getDay() != 1) {
        cout << "Test 3 failed!" << endl;
      }
    }

    cout << "All tests passed!" << endl;
  }
};

#endif  // TESTDAYMANAGER_H