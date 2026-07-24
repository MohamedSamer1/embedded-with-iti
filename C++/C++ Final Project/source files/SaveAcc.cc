#include <iostream>
#include <string>
#include <stdexcept>
#include "SaveAcc.h"

SavingAccount::SavingAccount(std::string accountID, double accountBalance) : Account(accountID, accountBalance) {}

void SavingAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        throw std::invalid_argument("amount must be bigger than 0\n");
    }

    if (amount > accountBalance)
    {
        throw std::runtime_error("not enough money\n");
    }

    accountBalance -= amount;
}

std::string SavingAccount::getAccountType() const
{
    return "Saving";
}