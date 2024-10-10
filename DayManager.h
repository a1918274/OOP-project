#ifndef DAYMANAGER_H
#define DAYMANAGER_H

// regulates the day cycle
class DayManager {
 private:
  int currentActions;  // Actions available to the player
  int currentDay;      // Current day in the game

 public:
  // Constructor to initialize actions and day
  DayManager(int initialActions);

  // Get the current number of actions
  int getActions() const;
};

#endif