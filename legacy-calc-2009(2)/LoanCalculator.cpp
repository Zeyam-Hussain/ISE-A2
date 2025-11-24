#include<iostream>
#include<cmath>
#include<fstream>
#include<string>

using namespace std;

int main(){
    long double loan_amount,interest_rate,number_of_years,total_amount,monthly_amount;
    
    ifstream config_file("config.txt");
    long double default_loan = 10000.0L;
    long double default_interest = 5.0L;
    long double default_years = 5.0L;
    
    if(config_file.is_open()){
        string line;
        int line_count = 0;
        
        while(getline(config_file, line) && line_count < 3){
            if(!line.empty()){
                try{
                    if(line_count == 0){
                        default_loan = stold(line);
                        if(default_loan <= 0) default_loan = 10000.0L;
                    }
                    else if(line_count == 1){
                        default_interest = stold(line);
                        if(default_interest < 0) default_interest = 5.0L;
                    }
                    else if(line_count == 2){
                        default_years = stold(line);
                        if(default_years <= 0) default_years = 5.0L;
                    }
                }
                catch(const exception& e){
                    // Keep default values if conversion fails
                }
            }
            line_count++;
        }
        config_file.close();
    }

    cout<<"Enter the loan amount (default: "<<default_loan<<"): ";
    string input;
    getline(cin, input);
    
    if(input.empty()){
        loan_amount = default_loan;
        cout<<"Using default loan amount: "<<loan_amount<<endl;
    }
    else{
        try{
            loan_amount = stold(input);
        }
        catch(const exception& e){
            loan_amount = default_loan;
            cout<<"Invalid input. Using default loan amount: "<<loan_amount<<endl;
        }
    }
    
    while(loan_amount <= 0){
        cout<<"Invalid loan amount. Please enter a positive value: ";
        cin>>loan_amount;
        cin.ignore(10000, '\n');
    }
    cout<<endl;
    
    cout<<"Enter the interest rate (default: "<<default_interest<<"): ";
    getline(cin, input);
    
    if(input.empty()){
        interest_rate = default_interest;
        cout<<"Using default interest rate: "<<interest_rate<<endl;
    }
    else{
        try{
            interest_rate = stold(input);
        }
        catch(const exception& e){
            interest_rate = default_interest;
            cout<<"Invalid input. Using default interest rate: "<<interest_rate<<endl;
        }
    }
    
    while(interest_rate < 0){
        cout<<"Invalid interest rate. Please enter a non-negative value: ";
        cin>>interest_rate;
        cin.ignore(10000, '\n');
    }
    cout<<endl;
    
    cout<<"Enter the number of years (default: "<<default_years<<"): ";
    getline(cin, input);
    
    if(input.empty()){
        number_of_years = default_years;
        cout<<"Using default number of years: "<<number_of_years<<endl;
    }
    else{
        try{
            number_of_years = stold(input);
        }
        catch(const exception& e){
            number_of_years = default_years;
            cout<<"Invalid input. Using default number of years: "<<number_of_years<<endl;
        }
    }
    
    while(number_of_years <= 0){
        cout<<"Invalid number of years. Please enter a positive value: ";
        cin>>number_of_years;
        cin.ignore(10000, '\n');
    }
    cout<<endl;

    long double annual_interest_rate = interest_rate / 100.0L;
    long double total_interest_factor = number_of_years * annual_interest_rate;
    
    total_amount = loan_amount + (loan_amount * total_interest_factor);
    monthly_amount = total_amount / (number_of_years * 12.0L);

    cout<<"Total amount to be paid: "<<total_amount<<endl;
    cout<<"Total interest: "<<total_amount - loan_amount<<endl;
    cout<<"Monthly amount to be paid: "<<monthly_amount<<endl;

    return 0;
}