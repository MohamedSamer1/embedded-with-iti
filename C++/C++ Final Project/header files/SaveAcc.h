#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"

class SavingAccount : public Account
{
    SavingAccount(std::string accountID, std::string accountName, double accountBalance);

    virtual void withdraw(double amount) override;

    virtual std::string getAccountType() override;
};

#endif