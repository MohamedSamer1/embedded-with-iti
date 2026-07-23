#include <iostream>

class Employee
{
protected:
    std::string name;

public:
    Employee(std::string name)
    {
        this->name = name;
    }

    void work() const
    {
        std::cout << name << " is working\n";
    }
};

class Developer : public Employee
{
public:
    Developer(std::string name) : Employee(name)
    {
    }

    void work() const
    {
        std::cout << name << " is coding\n";
    }
};

class Tester : public Employee
{
public:
    Tester(std::string name) : Employee(name)
    {
    }

    void work() const
    {
        std::cout << name << " is testing\n";
    }
};

int main()
{
    Employee emp("kareem");
    Developer developer("Mohamed");
    Tester tester("Ahmed");

    emp.work();
    developer.work();
    tester.work();

    return 0;
}