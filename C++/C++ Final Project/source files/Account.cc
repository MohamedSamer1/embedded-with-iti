#include <iostream>
#include <string>
#include <stdexcept>
#include "Account.h"

Account::Account(std::string accountID, std::string accountName, double accountBalance) : accountID(accountID), accountName(accountName), accountBalance(accountBalance)
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

std::string Account::getAccountName()
{
    return accountName;
}

void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        throw std::invalid_argument("need bigger than zero number\n");
    }

    accountBalance += amount;
}