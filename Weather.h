#ifndef WEATHER_H
#define WEATHER_H

#include <cstdlib>  // For rand() function
#include <string>

#include "DayManager.h"

// Weather class represents the weather system in the game,
// wherein each day has a 75% chance of being sunny, 20% chance of rain,
// or 5% chance of an earthquake occurring.

class Weather {
 public:
  enum Type { SUNNY, RAIN, EARTHQUAKE };  // Sets each type of weather to 0, 1 and 2 respectively

 private:
  Type currentWeather;  // Stores the current weather type

 public:
  // Constructor
  Weather();            // Initializes the weather

  // Getters
  Type getWeather() const;                // Returns the current weather type
  std::string getWeatherString() const;   // Returns a formatted string representing the current weather

  // Setter
  void setWeather(Type weather);          // Sets the current weather type

  // Methods
  void generateWeather();                 // Determines weather at the start of each day

  // Effect on Gameplay
  void applyWeatherEffects(DayManager& dayManager); // Applies the effects of the current weather on the player's actions
};

#endif  // WEATHER_H