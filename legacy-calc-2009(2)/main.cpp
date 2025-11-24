#include <iostream>
#include "Loan.h"
#include "Utils.h"

using namespace std;

int main() {
    long double default_loan = 10000.0L;
    long double default_rate = 5.0L;
    long double default_years = 5.0L;

    // Read config.txt
    readConfig(default_loan, default_rate, default_years);

    // Read input using helper function
    long double loan_amount = readValueWithDefault("Enter loan amount", default_loan);
    while (loan_amount <= 0) {
        cout << "Invalid. Enter positive value: ";
        cin >> loan_amount;
        cin.ignore(10000, '\n');
    }

    long double interest_rate = readValueWithDefault("Enter interest rate", default_rate);
    while (interest_rate < 0) {
        cout << "Invalid. Enter non-negative rate: ";
        cin >> interest_rate;
        cin.ignore(10000, '\n');
    }

    long double years = readValueWithDefault("Enter number of years", default_years);
    while (years <= 0) {
        cout << "Invalid. Enter positive years: ";
        cin >> years;
        cin.ignore(10000, '\n');
    }

    // Create Loan object
    Loan loan(loan_amount, interest_rate, years);

    // Output results
    cout << "Total amount to be paid: " << loan.getTotalAmount() << endl;
    cout << "Total interest: " << loan.getTotalInterest() << endl;
    cout << "Monthly payment: " << loan.getMonthlyPayment() << endl;

    return 0;
}
