#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

float getHoursWorked()
{
    float hours;

    while (true)
    {
        std::cout << "Enter the number of hours worked: ";

        if (std::cin >> hours && hours >= 0)
            return hours;

        std::cout << "Invalid input! Please enter a positive number.\n";

        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

std::string getEmployeeName()
{
    std::string name;

    while (true)
    {
        std::cout << "Enter employee name: ";
        std::getline(std::cin, name);

        if (!name.empty())
            return name;

        std::cout << "Name cannot be empty.\n";
    }
}

float getOvertimeHours()
{
    float overtime;

    while (true)
    {
        std::cout << "Enter overtime hours: ";

        if (std::cin >> overtime && overtime >= 0)
            return overtime;

        std::cout << "Invalid input! Please enter a positive number.\n";

        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

char getPosition()
{
    char position;

    while (true)
    {
        std::cout << "Employee or Manager? (e/m): ";
        std::cin >> position;

        position = std::tolower(position);

        if (position == 'e' || position == 'm')
            return position;

        std::cout << "Invalid input! Enter 'e' for Employee or 'm' for Manager.\n";
    }
}

int getEmployeeID()
{
    int id;

    while (true)
    {
        std::cout << "Enter Employee ID: ";

        if (std::cin >> id && id > 0)
            return id;

        std::cout << "Invalid ID! Please enter a positive integer.\n";

        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

float calculateSalary(float hours, float rate)
{
    return hours * rate;
}

float calculateOvertime(float overtimeHours, float overtimeRate)
{
    return overtimeHours * overtimeRate;
}

float calculateTax(float salary, float overtimePay, float taxRate = 0.15f)
{
    return (salary + overtimePay) * taxRate;
}

float calculateBonus(float salary, float overtimePay, float bonusRate)
{
    return (salary + overtimePay) * bonusRate;
}

float calculateTotalSalary(float salary, float overtime, float bonus, float tax)
{
    return salary + overtime + bonus - tax;
}

void employeeDetails(std::string name,
                     float salary,
                     float overtime,
                     float bonus,
                     float totalSalary,
                     float tax,
                     int id)
{
    std::cout << "\n=========== Employee Payroll ===========\n";
    std::cout << "Employee Name : " << name << '\n';
    std::cout << "Employee ID   : " << id << '\n';
    std::cout << "Base Salary   : $" << std::fixed << std::setprecision(2) << salary << '\n';
    std::cout << "Overtime Pay  : $" << overtime << '\n';
    std::cout << "Bonus         : $" << bonus << '\n';
    std::cout << "Tax           : $" << tax << '\n';
    std::cout << "----------------------------------------\n";
    std::cout << "Total Salary  : $" << totalSalary << '\n';
}

int main()
{
    std::cout << "========== Payroll Calculator ==========\n\n";
    std::string name = getEmployeeName();
    float hoursWorked = getHoursWorked();
    float overtimeHours = getOvertimeHours();
    char position = getPosition();
    int id = getEmployeeID();

    float bonusRate;

    if (position == 'm')
        bonusRate = 0.15;
    else
        bonusRate = 0.10;

    float baseSalary = calculateSalary(hoursWorked, 20.0);
    float overtimePay = calculateOvertime(overtimeHours, 30.0);
    float bonus = calculateBonus(baseSalary,overtimePay, bonusRate);
    float tax = calculateTax(baseSalary, overtimePay);
    float totalSalary = calculateTotalSalary(baseSalary, overtimePay, bonus, tax);

    employeeDetails(name, baseSalary, overtimePay, bonus, totalSalary, tax, id);

    return 0;
}