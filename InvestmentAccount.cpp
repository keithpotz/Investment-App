/*
Developer Keith Pottratz
CS 210
June 7, 2024
Banking App

*/

#include <iostream>
#include <iomanip>
#include <limits>
#include "InvestmentAccount.h"

        using namespace std;

    InvestmentAccount::InvestmentAccount()
        : initial_investment(0), monthly_deposit(0), annual_interest_rate(0), years(0), monthly_interest_rate(0) {}

    void InvestmentAccount::display_initial_screen() {
        // Prompt user for input values
        cout << "**********************************" << endl;
        cout << "*********  DATA INPUT  ***********" << endl;
        cout << "**********************************" << endl;

        // Take user input for Iniital Invenstment Amount
        cout << "Enter Initial Investment Amount: ";
        while (!(cin >> initial_investment) || initial_investment < 0) {
            cout << "Please enter a valid positive number: "; //Check for positive number only
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this is used to clear the input buffer. I did this for each loop below to ensure that it's clear after each input and no left over number is present
        }
        //Take use input for MOnthly Deposit
        cout << "Enter Monthly Deposit: ";
        while (!(cin >> monthly_deposit) || monthly_deposit < 0) {
            cout << "Please enter a valid positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        //Take user input for Interest Rate
        cout << "Enter Annual Interest Rate (as %): ";
        while (!(cin >> annual_interest_rate) || annual_interest_rate < 0) {
            cout << "Please enter a valid positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
         // User enter number of years
        cout << "Enter Number of Years: ";
        while (!(cin >> years) || years < 0) {
            cout << "Please enter a valid positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Calculate monthly interest rate
        monthly_interest_rate = (annual_interest_rate / 100) / 12;

        // Clear the input buffer before waiting for a key press
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "**********************************" << endl;
        cout << "Press any key to continue . . ." << endl;
        cin.get();  // Wait for any key press to continue
    }

    void InvestmentAccount::calculate_no_deposit() {
        // Calculate year-end balances without monthly deposits
        double balance = initial_investment;

        print_separator_line('*'); // Print separator line
        cout << "Balance and Interest Without Monthly Deposits" << endl;
        cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
        print_separator_line('=');

        // Calculate interest for each year
        for (int i = 0; i < years; ++i) {
            double yearly_interest = balance * monthly_interest_rate * 12; // Calculate interest for the year
            balance += yearly_interest; // Update balance with earned interest
            // Print year-end balance and interest
            cout << setw(4) << (i + 1)
                << "\t" << setw(18) << fixed << setprecision(2) << right << balance   //Stuff to make it pretty
                << "\t" << setw(24) << right << yearly_interest << endl;
        }

        print_separator_line('*'); // Print separator line

    }

void InvestmentAccount::calculate_with_deposit() {
    //Calculate  year-end balance with monthly deposits
    double balance = initial_investment;
    
    print_separator_line('*'); // Print the separator line
    cout << "Balance and Interest With Monthly Deposits" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    print_separator_line('=');

    //Calcluate Balance for each year

    for (int i = 0; i < years; ++i) {  //Declaring I and J in the loop is easier for me verses cluttering up each function
        double yearly_interest = 0;
        //Calcuclate interest and update balance for each month in the year
        for (int j = 0; j < 12; ++j) {
            double monthly_interest = balance * monthly_interest_rate; // Calculate inteeest for the month
            balance += monthly_deposit + monthly_interest; // add monthly deposit and interest to balance
            yearly_interest += monthly_interest;
        }
        //Print end ofyear balance and total interest earned
        cout << setw(4) << (i + 1)
            << "\t" << setw(18) << fixed << setprecision(2) << right << balance
            << "\t" << setw(24) << right << yearly_interest << endl;
    }
    print_separator_line('*'); // Print separator line

}


void InvestmentAccount::print_separator_line(char separator, int length) {
    // Print a line of specified length with the specified separator
    for (int i = 0; i < length; ++i) {
        cout << separator;
    }
    cout << endl;
}

void InvestmentAccount::print_separator_line(char separator) {
    const int line_length = 45; // Default line length
    print_separator_line(separator, line_length); // Print separator line with default length
}
