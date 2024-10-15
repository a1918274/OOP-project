#ifndef TESTWEATHER_H
#define TESTWEATHER_H

// Testing for Weather

#include <cassert>
#include <iostream>

#include "DayManager.h"
#include "Weather.h"

using namespace std;

class TestWeather {
 public:
  void runTests() {
    cout << "\nStart testing for Weather:\n\n";
    testGenerateWeather();
    testGetSetWeather();
    testGetWeatherString();
    testApplyWeatherEffects();
    cout << "\nFinished testing for Weather!\n\n";
  }

 private:
  void testGenerateWeather() {
    cout << "Testing for generate weather:\n";
    {
      Weather weather;
      weather.generateWeather();
      assert(weather.getWeather() == Weather::SUNNY ||
             weather.getWeather() == Weather::EARTHQUAKE ||
             weather.getWeather() == Weather::RAIN);
    }

    {
      Weather weather;
      weather.generateWeather();
      assert(weather.getWeather() == Weather::SUNNY ||
             weather.getWeather() == Weather::EARTHQUAKE ||
             weather.getWeather() == Weather::RAIN);
    }

    {
      Weather weather;
      weather.generateWeather();
      assert(weather.getWeather() == Weather::SUNNY ||
             weather.getWeather() == Weather::EARTHQUAKE ||
             weather.getWeather() == Weather::RAIN);
    }

    cout << "All test for generate weather passed!" << endl;
  }

  void testGetSetWeather() {
    cout << "Testing for getWeather and setWeather:\n";
    {
      Weather weather;
      weather.setWeather(Weather::SUNNY);
      assert(weather.getWeather() == Weather::SUNNY);
    }

    {
      Weather weather;
      weather.setWeather(Weather::RAIN);
      assert(weather.getWeather() == Weather::RAIN);
    }

    {
      Weather weather;
      weather.setWeather(Weather::EARTHQUAKE);
      assert(weather.getWeather() == Weather::EARTHQUAKE);
    }

    cout << "All test for getWeather() and setWeather() passed!" << endl;
  }

  void testGetWeatherString() {
    cout << "Testing for getWeatherString:\n";

    {
      Weather weather;
      weather.setWeather(Weather::SUNNY);
      assert(weather.getWeatherString() == "Sunny");
    }

    {
      Weather weather;
      weather.setWeather(Weather::RAIN);
      assert(weather.getWeatherString() == "Rain");
    }

    {
      Weather weather;
      weather.setWeather(Weather::EARTHQUAKE);
      assert(weather.getWeatherString() == "Earthquake");
    }

    cout << "All test for getWeatherString passed!" << endl;
  }

  void testApplyWeatherEffects() {
    cout << "Testing for applyWeatherEffects:\n";

    {
      DayManager dayManager(10);
      Weather weather;
      weather.setWeather(Weather::SUNNY);
      weather.applyWeatherEffects(dayManager);
      assert(dayManager.getActions() == 10);
    }

    {
      DayManager dayManager(0);
      Weather weather;
      weather.setWeather(Weather::RAIN);
      weather.applyWeatherEffects(dayManager);
      assert(dayManager.getActions() == 0);
    }

    {
      DayManager dayManager(3);
      Weather weather;
      weather.setWeather(Weather::EARTHQUAKE);
      weather.applyWeatherEffects(dayManager);
      assert(dayManager.getActions() == 0);
    }

    {
      DayManager dayManager(3);
      Weather weather;
      weather.setWeather(Weather::RAIN);
      weather.applyWeatherEffects(dayManager);
      assert(dayManager.getActions() == 2);
    }

    cout << "All test for applyWeatherEffects passed!" << endl;
  }
};

#endif  // TESTWEATHER_H