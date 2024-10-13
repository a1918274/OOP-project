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
    enum Type { SUNNY, RAIN, EARTHQUAKE };

private:
    Type currentWeather;

public:
    // Constructor to initialize the weather
    Weather();


    // Function to determine weather at the start of each day
    void generateWeather();


    // Get the current weather type
    Type getWeather() const;


    // Set the current weather type
    void setWeather(Type weather);


    // Get a formatted string for the current weather
    std::string getWeatherString() const;


    // Apply the effects of the weather on the player's actions
    void applyWeatherEffects(DayManager&dayManager);
};

#endif //WEATHER_H