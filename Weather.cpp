#include "Weather.h"
#include "DayManager.h"
#include <iostream>
#include <ctime>

using namespace std;

// Constructor to initialize random seed
Weather::Weather() {
    // Seed for random generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Generate initial weather
    generateWeather();
}

// Generate weather for the day based on probabilities
void Weather::generateWeather() {
    // Generate a random number between 0 and 99
    int chance = std::rand() % 100; 

    if (chance < 75) {
        currentWeather = SUNNY; // 75% chance
    } else if (chance < 95) {
        currentWeather = RAIN; // 20% chance
    } else {
        currentWeather = EARTHQUAKE; // 5% chance
    }
}


// Return the current weather type
Weather::Type Weather::getWeather() const {
    return currentWeather;
}

// Set the current weather type
void Weather::setWeather(Type weather) {
    currentWeather = weather;
}

// Get a string representation of the current weather
std::string Weather::getWeatherString() const {
    switch (currentWeather) {
        case SUNNY: return "Sunny";
        case RAIN: return "Rain";
        case EARTHQUAKE: return "Earthquake";
        default: return "Unknown";
    }
}

// Apply the effects of the weather on the player's actions
void Weather::applyWeatherEffects(DayManager &dayManager) {
    int actions = dayManager.getActions(); // Get the current actions

    switch (currentWeather) {
        case SUNNY:
            // No effect on actions
            break;
        case RAIN:
            actions -= 1; // Use up 1 action
            break;
        case EARTHQUAKE:
            actions = 0; // Set actions to 0, but don't call nextDay() here
            cout << "\n\n[ B R E A K I N G   N E W S ]\n";
            cout << "An earthquake has hit the town, the mayor has requested for everyone to please stay indoors and stay safe.\n";
            cout << "You decide to stay home for the day.";
            break;
    }

    // Ensure actions do not go below zero
    if (actions < 0) {
        actions = 0;
    }

    dayManager.setActions(actions); // Update the action count back to DayManager
}
