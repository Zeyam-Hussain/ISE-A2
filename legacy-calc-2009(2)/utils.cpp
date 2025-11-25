#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readConfig(long double &loan, long double &rate, long double &years) {
    ifstream config("config.txt");
    string line;
    int count = 0;

    if (config.is_open()) {
        while (getline(config, line) && count < 3) {
            try {
                if (!line.empty()) {
                    long double value = stold(line);
                    if (count == 0 && value > 0) loan = value;
                    else if (count == 1 && value >= 0) rate = value;
                    else if (count == 2 && value > 0) years = value;
                }
            } catch (...) {
                // Keep original values if conversion fails
            }
            count++;
        }
        config.close();
    }
}

long double readValueWithDefault(const string& prompt, long double default_value) {
    cout << prompt << " (default: " << default_value << "): ";

    string input;
    getline(cin, input);

    if (input.empty()) {
        cout << "Using default value: " << default_value << endl;
        return default_value;
    }

    try {
        return stold(input);
    } catch (...) {
        cout << "Invalid input. Using default value: " << default_value << endl;
        return default_value;
    }
}