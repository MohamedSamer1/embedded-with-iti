#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "User.h"
#include "json.hpp"

User::User(const std::string &userID, const std::string &username, const std::string &password, bool isAdmin) : userID(userID), userName(username), password(password), isAdmin(isAdmin) {}

const std::vector<std::unique_ptr<Account>> &User::getAccounts() const
{
    return accounts;
}

void User::setUsername(const std::string &username)
{
    userName = username;
}

void User::setPassword(const std::string &password)
{
    this->password = password;
}
bool User::deleteAccount(const std::string &accountID)
{
    for (auto it = accounts.begin(); it != accounts.end(); ++it)
    {
        if ((*it)->getAccountId() == accountID)
        {
            accounts.erase(it);
            return true;
        }
    }

    return false;
}
void User::addAccount(std::unique_ptr<Account> account)
{
    accounts.push_back(std::move(account));
}

Account *User::findAccount(const std::string &accountID)
{
    for (auto &account : accounts)
    {
        if (account->getAccountId() == accountID)
        {
            return account.get();
        }
    }

    return nullptr;
}

void User::displayAccounts() const
{
    if (accounts.empty())
    {
        std::cout << "No accounts found\n";
        return;
    }

    std::cout << "\nAccounts for " << userName << '\n';
    std::cout << "---------------------------\n";

    for (const auto &account : accounts)
    {
        std::cout << "Account ID   : " << account->getAccountId() << '\n';
        std::cout << "Account Type : " << account->getAccountType() << '\n';
        std::cout << "Balance      : " << account->getAccountBalance() << '\n';
        std::cout << "---------------------------\n";
    }
}

std::string User::getUserID() const
{
    return userID;
}

std::string User::getUsername() const
{
    return userName;
}

std::string User::getPassword() const
{
    return password;
}

bool User::getIsAdmin() const
{
    return isAdmin;
}