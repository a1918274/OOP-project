#ifndef VALIDNUMBERCHECK_H
#define VALIDNUMBERCHECK_H

#include <string>

// This class provides utility functions for number validation
class ValidNumberCheck {
public:
    // Function to check if a string represents a valid positive integer
    static bool isValidNumber(const std::string& input);
};

#endif // VALIDNUMBERCHECK_H