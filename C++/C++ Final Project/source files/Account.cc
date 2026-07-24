#include <iostream>
#include <string>
#include <stdexcept>
#include "Account.h"

Account::Account(std::string accountID, double accountBalance) : accountID(accountID), accountBalance(accountBalance)
{
    if (accountBalance < 0)
    {
        throw std::invalid_argument("cant intilize with negative bal\n");
    }
}

double Account::getAccountBalance()
{
    return accountBalance;
}

std::string Account::getAccountId()
{
    return accountID;
}

void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        throw std::invalid_argument("need bigger than zero number\n");
    }

    accountBalance += amount;
}