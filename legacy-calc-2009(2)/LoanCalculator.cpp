#include<iostream>

using namespace std;

int main(){
    double loan_amount,interest_rate,number_of_years,total_amount,monthly_amount;

    cout<<"Enter the loan amount: ";
    cin>>loan_amount;
    while(loan_amount <= 0){
        cout<<"Invalid loan amount. Please enter a positive value: ";
        cin>>loan_amount;
    }
    cout<<endl;
    
    cout<<"Enter the interest rate: ";
    cin>>interest_rate;
    while(interest_rate < 0){
        cout<<"Invalid interest rate. Please enter a non-negative value: ";
        cin>>interest_rate;
    }
    cout<<endl;
    
    cout<<"The number of years: ";
    cin>>number_of_years;
    while(number_of_years <= 0){
        cout<<"Invalid number of years. Please enter a positive value: ";
        cin>>number_of_years;
    }
    cout<<endl;

    total_amount=(number_of_years*loan_amount)+(number_of_years*loan_amount*(interest_rate/100.00));
    monthly_amount=total_amount/(number_of_years*12);

    cout<<"Total amount to be paid: "<<total_amount<<endl;
    cout<<"Total interest: "<<total_amount-(number_of_years*loan_amount)<<endl;
    cout<<"Monthly amount to be paid: "<<monthly_amount<<endl;

    return 0;
}