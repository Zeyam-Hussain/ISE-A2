#ifndef LOAN_H
#define LOAN_H

/**
 * @brief Represents a loan with amount, interest rate, and years
 */
class Loan {
private:
    long double loan_amount;    ///< Loan principal amount
    long double interest_rate;  ///< Annual interest rate (%)
    long double years;          ///< Loan tenure in years

public:
    /**
     * @brief Constructor for Loan class
     * @param amount Loan amount (positive)
     * @param rate Interest rate (non-negative)
     * @param yrs Number of years (positive)
     */
    Loan(long double amount, long double rate, long double yrs);

    /// @brief Calculate total repayment amount
    long double getTotalAmount() const;
    
    /// @brief Calculate total interest paid
    long double getTotalInterest() const;
    
    /// @brief Calculate monthly payment
    long double getMonthlyPayment() const;
};

#endif