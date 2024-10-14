#ifndef DAYMANAGER_H
#define DAYMANAGER_H

// This class regulates the day cycle (wherein the player has a certain number
// of actions to use in a day, and the day ends once all actions have been
// used).

class DayManager {
 private:
  int currentActions;               // Number of actions available to the player
  int currentDay;                   // Current day in the game

 public:
  // Constructor
  DayManager(int initialActions);   // Initializes the day manager with a set number of actions

  // Getters
  int getActions() const;           // Returns the current number of actions
  int getDay() const;               // Returns the current day

  // Setters
  void setActions(int actions);     // Set the number of actions
  void setDay(int day);             // Set the current day

  // Methods
  void nextDay();                   // Moves to the next day
  void performAction();             // Decreases the number of available actions by one
  void reset();                     // Resets both day and actions to default values
};

#endif  // DAYMANAGER_H