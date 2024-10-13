#ifndef DAYMANAGER_H
#define DAYMANAGER_H

// This class regulates the day cycle (wherein the player has a certain number
// of actions to use in a day, and the day ends once all actions have been
// used).

class DayManager {
 private:
  int currentActions;  // Actions available to the player
  int currentDay;      // Current day in the game

 public:
  // Constructor to initialize actions and day
  DayManager(int initialActions);

  // Get the current number of actions
  int getActions() const;

  // Set the current number of actions
  void setActions(int actions);

  // Get the current day
  int getDay() const;

  // Set the current day
  void setDay(int day);
};

#endif