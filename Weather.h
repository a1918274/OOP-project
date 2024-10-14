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
  // Sets each type of weather to 0, 1 and 2 respectively
  enum Type { SUNNY, RAIN, EARTHQUAKE };

 private:
  // Stores the current weather type
  Type currentWeather;

 public:
  // Constructor to initialize the weather
  Weather();

  // Getters
  // Returns the current weather type
  Type getWeather() const;
  // Returns a formatted string representing the current weather
  std::string getWeatherString() const;

  // Setter
  // Sets the current weather type
  void setWeather(Type weather);

  // Methods
  // Determines weather at the start of each day
  void generateWeather();

  // Effect on Gameplay
  // Applies the effects of the current weather on the player's actions
  void applyWeatherEffects(DayManager& dayManager);
};

#endif  // WEATHER_H