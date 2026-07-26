#include <iostream>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include "Bank.h"
#include "Account.h"
#include "SaveAcc.h"
#include "CheckAcc.h"
#include "SaveManger.h"
// void Bank::addUser(std::unique_ptr<User> user)
// {
//     users.push_back(std::move(user));
// }

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

void Bank::transfer(const std::string &fromAccountID, const std::string &toAccountID, double amount)
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

    else if (receiver == nullptr)
    {
        throw std::runtime_error("Receiver account not found.");
    }
    else
    {

        sender->withdraw(amount);
        receiver->deposit(amount);

        std::cout << "Transfer completed successfully.\n";
        SaveManger::saveTransaction("Transfer | " + fromAccountID + " -> " + toAccountID + " | " + std::to_string(amount));
        SaveManger::log("Transfer : " + fromAccountID + " -> " + toAccountID);
    }
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

void Bank::registerUser(const std::string &username, const std::string &password)
{
    {
        std::string userID = generateUserID();
        if (username.empty())
        {
            throw std::invalid_argument("Username cannot be empty.");
        }
        else if (password.length() < 4)
        {
            throw std::invalid_argument("Password must be at least 4 characters.");
        }
        else
        {
            users.push_back(std::make_unique<User>(userID, username, password));

            std::cout << "User registered successfully.\n";
            std::cout << "User ID: " << userID << '\n';
            SaveManger::log("User Registered: " + username);
        }
    }
}

User *Bank::login(const std::string &userID, const std::string &password)
{
    User *user = findUser(userID);
    if (userID.empty() || password.empty())
    {
        return nullptr;
    }
    if (user == nullptr)
    {
        return nullptr;
    }

    if (user->getPassword() == password)
    {
        return user;
        SaveManger::log("User Logged In: " + user->getUsername());
    }

    return nullptr;
}

void Bank::createSavingAccount(User *user, double balance)
{
    std::string accountID = generateSavingAccountID();
    if (balance < 0)
    {
        throw std::invalid_argument("Initial balance cannot be negative.");
    }
    else
    {
        user->addAccount(std::make_unique<SavingAccount>(accountID, balance));

        std::cout << "Saving account created\n";
        std::cout << "Account ID: " << accountID << '\n';
        SaveManger::log("Saving Account Created: " + accountID);
    }
}

void Bank::createCheckingAccount(User *user, double balance)
{
    std::string accountID = generateCheckingAccountID();
    if (balance < 0)
    {
        throw std::invalid_argument("Initial balance cannot be negative.");
    }
    else
    {
        user->addAccount(std::make_unique<CheckingAccount>(accountID, balance));

        std::cout << "Checking account created\n";
        std::cout << "Account ID: " << accountID << '\n';
        SaveManger::log("Checking Account Created: " + accountID);
    }
}

std::string Bank::generateSavingAccountID()
{
    std::ostringstream stream;

    stream << "SAV" << std::setw(4) << std::setfill('0') << savingAccountCounter++;

    return stream.str();
}

std::string Bank::generateCheckingAccountID()
{
    std::ostringstream stream;

    stream << "CHK" << std::setw(4) << std::setfill('0') << checkingAccountCounter++;

    return stream.str();
}

std::string Bank::generateUserID()
{
    std::ostringstream stream;

    stream << "USR" << std::setw(4) << std::setfill('0') << userCounter++;

    return stream.str();
}