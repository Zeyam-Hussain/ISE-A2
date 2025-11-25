#ifndef LOAN_H
#define LOAN_H

class Loan {
private:
    long double loan_amount;
    long double interest_rate;
    long double years;

public:
    Loan(long double amount, long double rate, long double yrs);

    long double getTotalAmount() const;
    long double getTotalInterest() const;
    long double getMonthlyPayment() const;
};

#endif