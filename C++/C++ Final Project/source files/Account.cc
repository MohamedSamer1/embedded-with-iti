#include <iostream>
#include <string>
#include <stdexcept>
#include "Account.h"
#include "SaveManger.h"

Account::Account(std::string accountID, double accountBalance) : accountID(accountID), accountBalance(accountBalance)
{
    if (accountBalance < 0)
    {
        throw std::invalid_argument("cant intilize with negative bal\n");
        SaveManger::log("Invaild account intialzation | " + accountID + " | +" + std::to_string(accountBalance) + " | Reason: amount cAant be negative");
    }
    else
    {
        SaveManger::log("intilized : " + accountID);
    }
}
void Account::setAccountBalance(double balance)
{
    if (balance < 0)
    {
        throw std::invalid_argument("Balance cannot be negative.");
    }

    accountBalance = balance;
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
        SaveManger::log("Invaild deposit | " + accountID + " | +" + std::to_string(amount) + " | Reason: amount cAant be negative");
    }
    else
    {
        accountBalance += amount;
        SaveManger::saveTransaction("Deposit | " + accountID + " | +" + std::to_string(amount));
        SaveManger::log("Deposit : " + accountID);
    }
}