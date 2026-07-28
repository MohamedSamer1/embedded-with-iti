#ifndef BANK_H
#define BANK_H

#include <memory>
#include <vector>
#include <string>
#include "User.h"
#include "SaveAcc.h"
#include "CheckAcc.h"

class Bank
{
private:
    int userCounter = 1;
    int savingAccountCounter = 1;
    int checkingAccountCounter = 1;
    std::vector<std::unique_ptr<User>> users;

public:
    void changeUsername(const std::string &userID, const std::string &newUsername);

    void displayAllAccounts() const;

    const std::vector<std::unique_ptr<User>> &getUsers() const;

    void changePassword(const std::string &userID, const std::string &newPassword);

    void setUserCounter(int counter);

    void setSavingAccountCounter(int counter);

    void setCheckingAccountCounter(int counter);

    void createSavingAccount(User *user, double balance);

    void createCheckingAccount(User *user, double balance);

    std::string generateUserID();

    std::string generateSavingAccountID();

    std::string generateCheckingAccountID();

    void addUser(std::unique_ptr<User> user);

    User *findUser(const std::string &userID);

    Account *findAccount(const std::string &accountID);

    void transfer(const std::string &fromAccountID, const std::string &toAccountID, double amount);

    void displayUsers() const;

    void registerUser(const std::string &username, const std::string &password);

    User *login(const std::string &userID, const std::string &password);

    void deleteUser(const std::string &userID);

    void deleteAccount(const std::string &accountID);

    void changeAccountBalance(const std::string &accountID, double newBalance);
};

#endif