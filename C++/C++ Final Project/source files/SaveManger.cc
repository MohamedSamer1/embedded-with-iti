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