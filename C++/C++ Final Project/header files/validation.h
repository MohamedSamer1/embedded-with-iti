#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>

class Validation
{
public:
    static int getInt(const std::string& message);

    static double getDouble(const std::string& message);

    static std::string getString(const std::string& message);

    static double getPositiveDouble(const std::string& message);
};

#endif