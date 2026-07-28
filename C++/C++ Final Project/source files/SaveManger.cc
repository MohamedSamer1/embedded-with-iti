#include <iostream>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <ctime>
#include "Bank.h"
#include "Account.h"
#include "SaveAcc.h"
#include "CheckAcc.h"
#include "SaveManger.h"
#include "json.hpp"

void SaveManger::loadUsers(Bank &bank)
{
    int maxUser = 0;
    int maxSaving = 0;
    int maxChecking = 0;

    std::ifstream file("data/users.json");

    if (!file.is_open())
    {
        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        return;
    }

    nlohmann::json root;
    file >> root;

    file.close();

    for (const auto &userJson : root["users"])
    {
        std::string id = userJson["id"];
        std::string username = userJson["username"];
        std::string password = userJson["password"];
        bool isAdmin = userJson.value("isAdmin", false);

        int userNumber = std::stoi(id.substr(3));

        if (userNumber > maxUser)
        {
            maxUser = userNumber;
        }

        auto user = std::make_unique<User>(id, username, password, isAdmin);

        for (const auto &accountJson : userJson["accounts"])
        {
            std::string accountID = accountJson["id"];
            std::string type = accountJson["type"];
            double balance = accountJson["balance"];

            int accountNumber = std::stoi(accountID.substr(3));

            if (type == "Saving")
            {
                if (accountNumber > maxSaving)
                {
                    maxSaving = accountNumber;
                }

                user->addAccount(std::make_unique<SavingAccount>(accountID, balance));
            }
            else if (type == "Checking")
            {
                if (accountNumber > maxChecking)
                {
                    maxChecking = accountNumber;
                }

                user->addAccount(std::make_unique<CheckingAccount>(accountID, balance));
            }
        }

        bank.addUser(std::move(user));
    }

    bank.setUserCounter(maxUser + 1);
    bank.setSavingAccountCounter(maxSaving + 1);
    bank.setCheckingAccountCounter(maxChecking + 1);
}

void SaveManger::saveUsers(const Bank &bank)
{
    nlohmann::json root;

    root["users"] = nlohmann::json::array();

    for (const auto &user : bank.getUsers())
    {
        nlohmann::json userJson;

        userJson["id"] = user->getUserID();
        userJson["username"] = user->getUsername();
        userJson["password"] = user->getPassword();
        userJson["isAdmin"] = user->getIsAdmin();
        userJson["accounts"] = nlohmann::json::array();

        for (const auto &account : user->getAccounts())
        {
            nlohmann::json accountJson;

            accountJson["id"] = account->getAccountId();
            accountJson["type"] = account->getAccountType();
            accountJson["balance"] = account->getAccountBalance();

            userJson["accounts"].push_back(accountJson);
        }

        root["users"].push_back(userJson);
    }

    std::ofstream file("data/users.json");

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open users.json");
    }

    file << root.dump(4);

    file.close();
}

void SaveManger::initialize()
{
    std::filesystem::create_directory("data");

    std::ofstream("data/users.json", std::ios::app);
    std::ofstream("data/transactions.txt", std::ios::app);
    std::ofstream("data/logs.txt", std::ios::app);
}

std::string SaveManger::getCurrentTime()
{
    auto now = std::chrono::system_clock::now();

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm localTime = *std::localtime(&currentTime);

    std::ostringstream stream;

    stream << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

    return stream.str();
}

void SaveManger::log(const std::string &message)
{
    std::ofstream file("data/logs.txt", std::ios::app);

    if (!file)
    {
        return;
    }

    file << "[" << getCurrentTime() << "] " << message << '\n';
}

void SaveManger::saveTransaction(const std::string &message)
{
    std::ofstream file("data/transactions.txt", std::ios::app);

    if (!file)
    {
        return;
    }

    file << "[" << getCurrentTime() << "] " << message << '\n';
}