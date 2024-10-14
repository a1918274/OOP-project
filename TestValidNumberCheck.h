#ifndef TESTVALIDNUMBERCHECK_H
#define TESTVALIDNUMBERCHECK_H

// Testing for ValidNumberCheck
#include <iostream>

#include "ValidNumberCheck.h"
using namespace std;

class TestValidNumberCheck {
 public:
  void runTests() {
    cout << "\nStart testing for ValidNumberCheck:\n\n";
    testIsValidNumber();
    cout << "\nFinished testing for ValidNumberCheck!\n\n";
  }

 private:
  void testIsValidNumber() {
    {
      string input = "0";
      if (ValidNumberCheck::isValidNumber(input) != 1) {
        cout << "Test 1 failed!" << endl;
      }
    }

    {
      string input = "b";
      if (ValidNumberCheck::isValidNumber(input) != 0) {
        cout << "Test 2 failed!" << endl;
      }
    }

    {
      string input = "10";
      if (ValidNumberCheck::isValidNumber(input) != 1) {
        cout << "Test 3 failed!" << endl;
      }
    }

    {
      string input = " ";
      if (ValidNumberCheck::isValidNumber(input) != 0) {
        cout << "Test 4 failed!" << endl;
      }
    }

    cout << "All tests passed!" << endl;
  }
};

#endif  // TESTVALIDNUMBERCHECK_H