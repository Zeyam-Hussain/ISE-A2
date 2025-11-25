#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @brief Read configuration from config.txt file
 * @param loan Default loan amount (output)
 * @param rate Default interest rate (output)
 * @param years Default years (output)
 */
void readConfig(long double &loan, long double &rate, long double &years);

/**
 * @brief Get user input with default value
 * @param prompt Message to show user
 * @param default_value Default if user presses Enter
 * @return User input or default value
 */
long double readValueWithDefault(const std::string& prompt, long double default_value);

#endif