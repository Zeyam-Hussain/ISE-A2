/**
 * @file main.cpp
 * @brief Main loan calculator application
 */
#include <iostream>
#include <iomanip>
#include "loan.h"
#include "utils.h"
using namespace std;

/// @brief Main function - entry point of application
int main() {
    long double default_loan = 10000.0L;
    long double default_rate = 5.0L;
    long double default_years = 5.0L;

    readConfig(default_loan, default_rate, default_years);

    long double loan_amount = readValueWithDefault("Enter loan amount", default_loan);
    while (loan_amount <= 0) {
        cout << "Invalid. Enter positive value: ";
        cin >> loan_amount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            loan_amount = 0;
        }
    }

    long double interest_rate = readValueWithDefault("Enter interest rate", default_rate);
    while (interest_rate < 0) {
        cout << "Invalid. Enter non-negative rate: ";
        cin >> interest_rate;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            interest_rate = -1;
        }
    }

    long double years = readValueWithDefault("Enter number of years", default_years);
    while (years <= 0) {
        cout << "Invalid. Enter positive years: ";
        cin >> years;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            years = 0;
        }
    }

    Loan loan(loan_amount, interest_rate, years);

    cout << fixed << setprecision(2);

    cout << "\n================ Loan Summary ================\n";
    cout << left << setw(30) << "Loan Amount:" << "$" << loan_amount << endl;
    cout << left << setw(30) << "Interest Rate (%):" << interest_rate << "%" << endl;
    cout << left << setw(30) << "Number of Years:" << years << endl;
    cout << "----------------------------------------------\n";
    cout << left << setw(30) << "Total Amount to Pay:" << "$" << loan.getTotalAmount() << endl;
    cout << left << setw(30) << "Total Interest:" << "$" << loan.getTotalInterest() << endl;
    cout << left << setw(30) << "Monthly Payment:" << "$" << loan.getMonthlyPayment() << endl;
    cout << "==============================================\n";

    return 0;
}