#include "DayManager.h"

// Constructor to initialize actions and day
DayManager::DayManager(int initialActions)
    : currentActions(initialActions), currentDay(1) {}

// Get the current number of actions
int DayManager::getActions() const { return currentActions; }

// Set the current number of actions
void DayManager::setActions(int actions) { currentActions = actions; }

// Get the current day
int DayManager::getDay() const { return currentDay; }

// Set the current day
void DayManager::setDay(int day) { currentDay = day; }

// Reset actions for a new day
void DayManager::resetActions(int newActions) { currentActions = newActions; }