#ifndef DAYMANAGER_H
#define DAYMANAGER_H

// This class regulates the day cycle (wherein the player has a certain number
// of actions to use in a day, and the day ends once all actions have been
// used).

class DayManager {
 private:
  int currentActions;  // Number of actions available to the player
  int currentDay;      // Current day in the game

 public:
  // Constructor to initialize the day with a set number of actions
  DayManager(int initialActions);

  // Getters

  // Returns the current number of actions
  int getActions() const;
  // Returns the current day
  int getDay() const;

  // Setters

  // Set the number of actions
  void setActions(int actions);
  // Set the current day
  void setDay(int day);

  // Methods

  // Moves to the next day
  void nextDay();
  // Decreases the number of available actions by one
  void performAction();
  // Resets both day and actions to default values
  void reset();
};

#endif  // DAYMANAGER_H