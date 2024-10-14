#ifndef TESTWEATHER_H
#define TESTWEATHER_H

// Testing for Weather

#include <iostream>

#include "DayManager.h"
#include "Weather.h"

using namespace std;

class TestWeather {
 public:
  void runTests() {
    cout << "\nStart testing for Weather:\n\n";
    testGenerateWeather();
    testGetWeather();
    testSetWeather();
    testGetWeatherString();
    testApplyWeatherEffects();
    cout << "\nFinished testing for Weather!\n\n";
  }

 private:
  void testGenerateWeather() {}
  void testGetWeather() {}
  void testSetWeather() {}
  void testGetWeatherString() {}
  void testApplyWeatherEffects() {}
};

#endif  // TESTWEATHER_H