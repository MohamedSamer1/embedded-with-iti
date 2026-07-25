#ifndef BANK_H
#define BANK_H

#include <memory>
#include <vector>
#include <string>
#include "User.h"

class Bank
{
    std::vector<std::unique_ptr<User>> users;

public:
    void addUser(std::unique_ptr<User> user);

    User *findUser(const std::string &userID);

    Account *findAccount(const std::string &accountID);

    void transfer(const std::string &fromAccountID, const std::string &toAccountID, double amount);

    void displayUsers() const;

    void registerUser(const std::string &userID, const std::string &username, const std::string &password);

    User *login(const std::string &userID, const std::string &password);

    void createSavingAccount(User *user, const std::string &accountID, double balance);

    void createCheckingAccount(User *user, const std::string &accountID, double balance);
};

#endif