#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"

class CheckingAccount : public Account
{
public:
    CheckingAccount(std::string accountID, std::string accountName, double accountBalance);

    virtual void withdraw(double amount) override;

    virtual std::string getAccountType() const override;
};

#endif