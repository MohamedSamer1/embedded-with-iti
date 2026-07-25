#include "validation.h"
#include <iostream>
#include <string>
#include <limits>

int Validation::getInt(const std::string &message)
{
    int value;

    while (true)
    {
        std::cout << message;

        if (std::cin >> value)
        {
            return value;
        }
        else
        {
            std::cout << "Invalid input it must be int\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

double Validation::getDouble(const std::string &message)
{
    double num;

    while (true)
    {
        std::cout << message;

        if (std::cin >> num)
        {
            return num;
        }
        else
        {
            std::cout << "Invalid input it must be number\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string Validation::getString(const std::string &message)
{
    std::string value;

    std::cout << message;
    std::cin >> value;

    return value;
}

double Validation::getPositiveDouble(const std::string &message)
{
    double value;

    while (true)
    {
        value = getDouble(message);

        if (value > 0)
        {
            return value;
        }
        else
        {
            std::cout << "Cant enter num smaller than 0\n";
        }
    }
}