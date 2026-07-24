#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>

class Account
{
protected:
    std::string accountID;
    std::string accountName;
    double accountBalance;

public:
    Account(std::string accountID, std::string accountName, double accountBalance);

    virtual std::string getAccountId();

    virtual std::string getAccountName();

    virtual double getAccountBalance();

    virtual void withdraw(double amount) = 0;

    virtual void deposit(double amount);

    virtual std::string getAccountType() = 0;

    virtual ~Account() = default;
};

#endif