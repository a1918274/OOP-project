#ifndef WEATHER_H
#define WEATHER_H

#include "DayManager.h"
#include <string>
#include <cstdlib> //Library is used for rand() function

// This class is responsible for managing the random weather system, 
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

    // Returns the current weather type
    Type getWeather() const;      
    // Returns a formatted string representing the current weather          
    std::string getWeatherString() const;

    // Sets the current weather type
    void setWeather(Type weather);

    // Determines weather at the start of each day
    void generateWeather();

    // Applies the effects of the current weather on the player's actions
    void applyWeatherEffects(DayManager& dayManager);  
};


#endif // WEATHER_H