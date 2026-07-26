#include <iostream>
#include <string>
#include <stdexcept>
#include "CheckAcc.h"
#include "SaveManger.h"
CheckingAccount::CheckingAccount(std::string accountID, double accountBalance) : Account(accountID, accountBalance) {}

void CheckingAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        throw std::invalid_argument("amount must be bigger than 0\n");
    }

    else if (amount > accountBalance)
    {
        throw std::runtime_error("not enough money\n");
    }
    else
    {

        accountBalance -= amount;
        SaveManger::saveTransaction("Withdraw | " + accountID + " | -" + std::to_string(amount));
        SaveManger::log("Withdraw : " + accountID);
    }
}

std::string CheckingAccount::getAccountType() const
{
    return "Checking";
}