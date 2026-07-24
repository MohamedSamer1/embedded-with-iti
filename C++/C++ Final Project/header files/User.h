#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Account.h"

class User
{
private:
    std::string userID;
    std::string userName;
    std::string password;
    std::vector<std::unique_ptr<Account>> accounts;

public:
    User(const std::string &userID, const std::string &username, const std::string &password);

    void addAccount(std::unique_ptr<Account> account);

    Account *findAccount(const std::string &accountID);

    void displayAccounts() const;

    std::string getUserID() const;

    std::string getUsername() const;
};

#endif