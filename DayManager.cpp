#include "DayManager.h"

#include <iostream>

using namespace std;

// Constructor to initialize actions and day
DayManager::DayManager(int initialActions) {
  if (initialActions < 0) {
    cout << "Invalid action. Action must be a positive number.\n";
    setActions(0);
  } else {
    setActions(initialActions);
  }
  setDay(0);
}

// Get the current number of actions
int DayManager::getActions() const { return currentActions; }

// Get the current day
int DayManager::getDay() const { return currentDay; }

// Set the current number of actions
void DayManager::setActions(int actions) {
  if (actions < 0) {
    cout << "Invalid action. Action must be a positive number.\n";
  } else {
    currentActions = actions;
  }
}

// Set the current day
void DayManager::setDay(int day) {
  if (day < 0) {
    cout << "Invalid day. Day must be a positive number.\n";
  } else {
    currentDay = day;
  }
}

// Move to the next day
void DayManager::nextDay() { currentDay++; }

// Consume an action
void DayManager::performAction() {
  if (currentActions > 0) {
    currentActions--;  // decrement action by 1 if action is more than 1
  }
}

// Reset both day and actions to default values
void DayManager::reset() {
  setDay(1);
  setActions(3);
}