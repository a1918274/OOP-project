#include "ValidNumberCheck.h"

using namespace std;

// Function to check if a string is a valid positive integer
bool ValidNumberCheck::isValidNumber(const string& input) {
    if (input.empty() || input.length() > 1) {
        return false;  // Invalid if empty or more than 1 digit
    }

  for (char c : input) {
    if (c < '0' || c > '9') {
      return false;  // Check if the character is not a digit
    }
  }

  return true;  // All characters are digits
}