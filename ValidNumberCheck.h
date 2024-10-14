#ifndef VALIDNUMBERCHECK_H
#define VALIDNUMBERCHECK_H

#include <string>

// ValidNumberCheck class provides utility functions for number validation
// check if the player's input is valid (is a positive integer between 0 and 9
// inclusive)

class ValidNumberCheck {
 public:
  // Static method to check if a string represents a valid positive integer
  static bool isValidNumber(const std::string& input);
};

#endif  // VALIDNUMBERCHECK_H