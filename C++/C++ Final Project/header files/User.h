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
    bool isAdmin;

public:
    const std::vector<std::unique_ptr<Account>> &getAccounts() const;

    User(const std::string &userID, const std::string &username, const std::string &password, bool isAdmin = false);

    void addAccount(std::unique_ptr<Account> account);

    Account *findAccount(const std::string &accountID);

    void displayAccounts() const;

    std::string getUserID() const;

    std::string getUsername() const;

    std::string getPassword() const;

    bool getIsAdmin() const;

    void setUsername(const std::string &username);

    void setPassword(const std::string &password);

    bool deleteAccount(const std::string &accountID);
};

#endif