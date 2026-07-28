#include <iostream>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "Bank.h"
#include "Account.h"
#include "SaveAcc.h"
#include "CheckAcc.h"
#include "SaveManger.h"

const std::vector<std::unique_ptr<User>> &Bank::getUsers() const
{
    return users;
}

void Bank::setUserCounter(int counter)
{
    userCounter = counter;
}

void Bank::setSavingAccountCounter(int counter)
{
    savingAccountCounter = counter;
}

void Bank::setCheckingAccountCounter(int counter)
{
    checkingAccountCounter = counter;
}

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

void Bank::transfer(const std::string &fromAccountID, const std::string &toAccountID, double amount)
{

    if (fromAccountID == toAccountID)
    {
        throw std::invalid_argument("Cannot transfer to same acc");
    }
    if (amount <= 0)
    {
        throw std::invalid_argument("Transfer must be biiger than 0");
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
        SaveManger::saveUsers(*this);
    }
}

void Bank::displayUsers() const
{
    if (users.empty())
    {
        std::cout << "No users found\n";
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

    if (username.empty())
    {
        throw std::invalid_argument("Username cannot be empty");
    }
    else if (password.length() < 4)
    {
        throw std::invalid_argument("Password must be at least 4 characters");
    }
    else
    {
        std::string userID = generateUserID();
        users.push_back(std::make_unique<User>(userID, username, password, false));

        std::cout << "User registered successfully\n";
        std::cout << "User ID: " << userID << '\n';
        SaveManger::log("User Registered: " + username + " " + userID);
        SaveManger::saveUsers(*this);
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
        SaveManger::log("User Logged In: " + user->getUsername());
        return user;
    }

    return nullptr;
}

void Bank::createSavingAccount(User *user, double balance)
{
    if (balance < 0)
    {
        throw std::invalid_argument("Initial balance cannot be negative");
    }
    else
    {
        std::string accountID = generateSavingAccountID();

        user->addAccount(std::make_unique<SavingAccount>(accountID, balance));

        std::cout << "Saving account created\n";
        std::cout << "Account ID: " << accountID << '\n';
        SaveManger::log("Saving Account Created: " + accountID);
        SaveManger::saveUsers(*this);
    }
}

void Bank::createCheckingAccount(User *user, double balance)
{
    if (balance < 0)
    {
        throw std::invalid_argument("Initial balance cannot be negative.");
    }
    else
    {
        std::string accountID = generateCheckingAccountID();

        user->addAccount(std::make_unique<CheckingAccount>(accountID, balance));

        std::cout << "Checking account created\n";
        std::cout << "Account ID: " << accountID << '\n';
        SaveManger::log("Checking Account Created: " + accountID);
        SaveManger::saveUsers(*this);
    }
}

std::string Bank::generateSavingAccountID()
{
    std::ostringstream stream;

    stream << "SAV" << std::setw(4) << std::setfill('0') << savingAccountCounter++;

    return stream.str();
}

void Bank::deleteUser(const std::string &userID)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if ((*it)->getUserID() == userID)
        {
            SaveManger::log("User Deleted: " + (*it)->getUsername() + " " + userID);

            users.erase(it);
            SaveManger::saveUsers(*this);
            return;
        }
    }

    throw std::runtime_error("User not found");
}

void Bank::changePassword(const std::string &userID, const std::string &newPassword)
{
    if (newPassword.length() < 4)
    {
        throw std::invalid_argument("Password must be at least 4 characters");
    }

    User *user = findUser(userID);

    if (!user)
    {
        throw std::runtime_error("User not found");
    }

    user->setPassword(newPassword);

    SaveManger::log("Password Changed: " + userID);
    SaveManger::saveUsers(*this);
}

void Bank::changeUsername(const std::string &userID, const std::string &newUsername)
{
    if (newUsername.empty())
    {
        throw std::invalid_argument("Username cannot be empty");
    }

    User *user = findUser(userID);

    if (user == nullptr)
    {
        throw std::runtime_error("User not found");
    }

    std::string oldUsername = user->getUsername();

    user->setUsername(newUsername);

    SaveManger::log("Username Changed | " + userID + " | " + oldUsername + " -> " + newUsername);
    SaveManger::saveUsers(*this);
}

void Bank::deleteAccount(const std::string &accountID)
{
    for (auto &user : users)
    {
        if (user->deleteAccount(accountID))
        {
            SaveManger::log("Account Deleted: " + accountID);
            SaveManger::saveUsers(*this);
            return;
        }
    }

    throw std::runtime_error("Account not found");
}

void Bank::changeAccountBalance(const std::string &accountID, double newBalance)
{
    Account *account = findAccount(accountID);

    if (!account)
    {
        throw std::runtime_error("Account not found");
    }

    account->setAccountBalance(newBalance);

    SaveManger::log("Balance Changed: " + accountID);
    SaveManger::saveUsers(*this);
}

std::string Bank::generateCheckingAccountID()
{
    std::ostringstream stream;

    stream << "CHK" << std::setw(4) << std::setfill('0') << checkingAccountCounter++;

    return stream.str();
}

void Bank::displayAllAccounts() const
{
    if (users.empty())
    {
        std::cout << "No users found\n";
        return;
    }

    for (const auto &user : users)
    {
        const auto &accounts = user->getAccounts();

        for (const auto &account : accounts)
        {
            std::cout << "Owner      : " << user->getUsername() << '\n';
            std::cout << "User ID    : " << user->getUserID() << '\n';
            std::cout << "Account ID : " << account->getAccountId() << '\n';
            std::cout << "Type       : " << account->getAccountType() << '\n';
            std::cout << "Balance    : " << account->getAccountBalance() << "\n\n";
        }
    }
}

std::string Bank::generateUserID()
{
    std::ostringstream stream;

    stream << "USR" << std::setw(4) << std::setfill('0') << userCounter++;

    return stream.str();
}