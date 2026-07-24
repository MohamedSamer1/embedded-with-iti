#include <iostream>
#include <string>
#include <stdexcept>
#include "CheckAcc.h"

CheckingAccount::CheckingAccount(std::string accountID, std::string accountName, double accountBalance) : Account(accountID, accountName, accountBalance) {}

void CheckingAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        throw std::invalid_argument("amount must be bigger than 0\n");
    }

    if (amount > accountBalance + 150)
    {
        throw std::runtime_error("not enough money\n");
    }

    accountBalance -= amount;
}

std::string CheckingAccount::getAccountType() const
{
    return "Checking\n";
}