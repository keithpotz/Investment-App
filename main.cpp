/*
Developer Keith Pottratz
CS 210
June 7, 2024
Banking App

*/

#include "InvestmentAccount.h"

int main() {
    InvestmentAccount account;
    account.display_initial_screen(); // Display initial screen and prompt for user input
    account.calculate_no_deposit(); // Calculate and display year-end balances without monthly deposits
    account.calculate_with_deposit(); // Calculate and display year-end balances with monthly deposits
    return 0;
}
