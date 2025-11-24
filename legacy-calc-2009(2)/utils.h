#ifndef UTILS_H
#define UTILS_H

#include <string>

long double readValueWithDefault(const std::string& prompt, long double default_value);
void readConfig(long double &loan, long double &rate, long double &years);

#endif
