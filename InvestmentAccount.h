/*
Developer Keith Pottratz
CS 210
June 7, 2024
Banking App

*/

#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H

class InvestmentAccount {
private:
    // Member variables to store input values
    double initial_investment;
    double monthly_deposit;
    double annual_interest_rate;
    int years;
    double monthly_interest_rate;

public:
    // Constructor
    InvestmentAccount();

    // Method to display initial screen and prompt for user input
    void display_initial_screen();

    // Method to calculate and display year-end balances without monthly deposits
    void calculate_no_deposit();

    // Method to calculate and display year-end balances with monthly deposits
    void calculate_with_deposit();

    // Method to print a separator line with specified character and length
    void print_separator_line(char separator, int length);

    // Method to print a separator line with specified character (default length)
    void print_separator_line(char separator);
};

#endif // INVESTMENTACCOUNT_H
