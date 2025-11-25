#include "loan.h"

Loan::Loan(long double amount, long double rate, long double yrs) 
    : loan_amount(amount), interest_rate(rate), years(yrs) {
}

long double Loan::getTotalAmount() const {
    long double annual_rate = interest_rate / 100.0L;
    long double total_interest_factor = years * annual_rate;
    return loan_amount + (loan_amount * total_interest_factor);
}

long double Loan::getTotalInterest() const {
    return getTotalAmount() - loan_amount;
}

long double Loan::getMonthlyPayment() const {
    return getTotalAmount() / (years * 12.0L);
}