#include <iostream>
#include <utility>
#include <stdexcept>
#include "Bank.h"
#include "Account.h"
#include "SaveAcc.h"
#include "CheckAcc.h"

void Bank::addUser(std::unique_ptr<User> user)
{
    users.push_back(std::move(user));
}

User *Bank::findUser(const std::string &userID)
{
    for (auto &user : users)
    {
        if (user->getUserID() == userID)
        {
            return user.get();
        }
    }

    return nullptr;
}

Account *Bank::findAccount(const std::string &accountID)
{
    for (auto &user : users)
    {
        Account *account = user->findAccount(accountID);

        if (account != nullptr)
        {
            return account;
        }
    }

    return nullptr;
}

void Bank::transfer(const std::string &fromAccountID,
                    const std::string &toAccountID,
                    double amount)
{

    if (fromAccountID == toAccountID)
    {
        throw std::invalid_argument(
            "Cannot transfer to same acc");
    }
    if (amount <= 0)
    {
        throw std::invalid_argument(
            "Transfer must be biiger than 0");
    }
    Account *sender = findAccount(fromAccountID);
    Account *receiver = findAccount(toAccountID);

    if (sender == nullptr)
    {
        throw std::runtime_error("Sender account not found.");
    }

    if (receiver == nullptr)
    {
        throw std::runtime_error("Receiver account not found.");
    }

    sender->withdraw(amount);
    receiver->deposit(amount);

    std::cout << "Transfer completed successfully.\n";
}

void Bank::displayUsers() const
{
    if (users.empty())
    {
        std::cout << "No users found.\n";
        return;
    }

    std::cout << "\n===== Users =====\n";

    for (const auto &user : users)
    {
        std::cout << "User ID   : " << user->getUserID() << '\n';
        std::cout << "Username  : " << user->getUsername() << '\n';
        std::cout << "-------------------------\n";
    }
}

void Bank::registerUser(const std::string &userID, const std::string &username, const std::string &password)
{
    if (findUser(userID) != nullptr)
    {
        throw std::runtime_error("User ID already exists.");
    }

    users.push_back(
        std::make_unique<User>(userID, username, password));

    std::cout << "User registered successfully.\n";
}

User *Bank::login(const std::string &userID, const std::string &password)
{
    User *user = findUser(userID);

    if (user == nullptr)
    {
        return nullptr;
    }

    if (user->getPassword() == password)
    {
        return user;
    }

    return nullptr;
}

void Bank::createSavingAccount(User *user, const std::string &accountID, double balance)
{
    if (user == nullptr)
    {
        throw std::runtime_error("Invalid user");
    }

    if (findAccount(accountID) != nullptr)
    {
        throw std::runtime_error("Account ID already exists");
    }

    user->addAccount(std::make_unique<SavingAccount>(accountID, balance));
}

void Bank::createCheckingAccount(User *user, const std::string &accountID, double balance)
{
    if (user == nullptr)
    {
        throw std::runtime_error("Invalid user");
    }

    if (findAccount(accountID) != nullptr)
    {
        throw std::runtime_error("Account ID already exists");
    }

    user->addAccount(std::make_unique<CheckingAccount>(accountID, balance));
}