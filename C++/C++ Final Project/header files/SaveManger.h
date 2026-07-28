#ifndef SAVEMANGER_H
#define SAVEMANGER_H

#include <iostream>
#include <string>
#include "Bank.h"

class SaveManger
{
public:
    static void loadUsers(Bank &bank);

    static void saveUsers(const Bank &bank);

    static void initialize();

    static std::string getCurrentTime();

    static void log(const std::string &message);

    static void saveTransaction(const std::string &message);

    static void loadTransactions();
};

#endif