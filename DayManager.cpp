#include "DayManager.h"

#include <iostream>

using namespace std;

// Constructor to initialize actions and day
DayManager::DayManager(int initialActions) {
  setActions(initialActions);
  setDay(0);
}

// Get the current number of actions
int DayManager::getActions() const { return currentActions; }

// Set the current number of actions
void DayManager::setActions(int actions) {
  if (actions < 0) {
    cout << "Invalid action. Action must be a positive number. Action set to "
            "zero.\n";
    currentActions = 0;
  } else {
    currentActions = actions;
  }
}

// Get the current day
int DayManager::getDay() const { return currentDay; }

// Set the current day
void DayManager::setDay(int day) {
  if (day < 0) {
    cout << "Invalid day. Day must be a positive number. Day set to zero.\n";
    currentDay = 0;
  } else {
    currentDay = day;
  }
}