#include <gtest/gtest.h>
#include <cmath>
#include "loan.h"
#include "utils.h"

TEST(LoanTest, NormalCalculation) {
    Loan loan(100000, 5.0, 20);
    
    EXPECT_NEAR(loan.getTotalAmount(), 200000, 1.0);
    EXPECT_NEAR(loan.getTotalInterest(), 100000, 1.0);
    EXPECT_NEAR(loan.getMonthlyPayment(), 833.33, 0.1);
}

TEST(LoanTest, ZeroInterest) {
    Loan loan(50000, 0.0, 10);
    
    EXPECT_NEAR(loan.getTotalAmount(), 50000, 0.1);
    EXPECT_NEAR(loan.getTotalInterest(), 0.0, 0.1);
    EXPECT_NEAR(loan.getMonthlyPayment(), 416.67, 0.1);
}

TEST(LoanTest, LargeTenureNoOverflow) {
    Loan loan(1000000, 3.5, 100);
    
    EXPECT_TRUE(std::isfinite(loan.getTotalAmount()));
    EXPECT_TRUE(std::isfinite(loan.getTotalInterest()));
    EXPECT_TRUE(std::isfinite(loan.getMonthlyPayment()));
    
    EXPECT_GT(loan.getTotalAmount(), 1000000);
    EXPECT_GT(loan.getTotalInterest(), 0);
    EXPECT_GT(loan.getMonthlyPayment(), 0);
}

TEST(LoanTest, SmallLoanAmount) {
    Loan loan(100, 10.0, 1);
    
    EXPECT_NEAR(loan.getTotalAmount(), 110, 0.1);
    EXPECT_NEAR(loan.getTotalInterest(), 10, 0.1);
    EXPECT_NEAR(loan.getMonthlyPayment(), 9.17, 0.1);
}

TEST(UtilsTest, ReadConfigTest) {
    long double loan = 0, rate = 0, years = 0;
    
    readConfig(loan, rate, years);
    
    EXPECT_GE(loan, 0);
    EXPECT_GE(rate, 0);
    EXPECT_GE(years, 0);
}


TEST(LoanTest, EdgeCaseCalculations) {
    Loan loan1(1000, 12.0, 1.0/12.0); 
    EXPECT_TRUE(std::isfinite(loan1.getMonthlyPayment()));
    
    Loan loan2(1000, 50.0, 5);
    EXPECT_GT(loan2.getTotalAmount(), 1000);
}