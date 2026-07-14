#include <iostream>
#include <string>

void inputMarks(int *math, int *physics, int *english)
{
    std::cout << "Please enter the mark for Math: ";
    std::cin >> *math;

    std::cout << "Please enter the mark for Physics: ";
    std::cin >> *physics;

    std::cout << "Please enter the mark for English: ";
    std::cin >> *english;

    while (*math > 100 || *math < 0 ||
           *physics > 100 || *physics < 0 ||
           *english > 100 || *english < 0)
    {
        std::cout << "Enter valid marks (0-100)\n";

        std::cout << "Please enter the mark for Math: ";
        std::cin >> *math;

        std::cout << "Please enter the mark for Physics: ";
        std::cin >> *physics;

        std::cout << "Please enter the mark for English: ";
        std::cin >> *english;
    }
}

double calculateAverage(int *math, int *physics, int *english)
{
    return ((*math) + (*physics) + (*english)) / 3.0;
}

char calculateGrade(double average)
{
    if (average >= 90)
    {
        return 'A';
    }
    else if (average >= 80)
    {
        return 'B';
    }
    else if (average >= 70)
    {
        return 'C';
    }
    else if (average >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

void printReport(std::string name, int *math, int *physics, int *english)
{
    double average = calculateAverage(math, physics, english);

    std::cout << "\n\n=================== Student Report ===================\n";
    std::cout << "Name : " << name << std::endl
              << std::endl;

    std::cout << "Math Mark : " << *math << std::endl;
    std::cout << "Physics Mark : " << *physics << std::endl;
    std::cout << "English Mark : " << *english << std::endl
              << std::endl;

    std::cout << "Average : " << average << "%" << std::endl;
    std::cout << "Grade : " << calculateGrade(average) << std::endl;

    std::cout << "\n======================================================\n";
}

int main()
{
    std::string name = "blah blah";

    int x = 0;
    int y = 0;
    int z = 0;

    int *math = &x;
    int *physics = &y;
    int *english = &z;

    int op = 0;
    bool advanced = false;
    char ad = 'j';

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    inputMarks(math, physics, english);
    printReport(name, math, physics, english);

    while (ad != 'y' && ad != 'n')
    {
        std::cout << "Advanced options (y/n): ";
        std::cin >> ad;
        ad = tolower(ad);
    }

    if (ad == 'y')
    {
        advanced = true;
    }
    else
    {
        advanced = false;
    }

    if (advanced)
    {
        while (true)
        {
            std::cout << "\n=================== Student Report ===================\n";
            std::cout << "1. Update marks" << std::endl;
            std::cout << "2. Recalculate the average" << std::endl;
            std::cout << "3. Print the report again" << std::endl;
            std::cout << "4. Exit" << std::endl;

            do
            {
                std::cout << "Please choose an operation (1-4): ";
                std::cin >> op;

                if (op < 1 || op > 4)
                {
                    std::cout << "Please enter a valid number from 1 to 4.\n";
                }

            } while (op < 1 || op > 4);

            switch (op)
            {
            case 1:
                inputMarks(math, physics, english);
                break;

            case 2:
                std::cout << "New average is: "
                          << calculateAverage(math, physics, english)
                          << std::endl;
                break;

            case 3:
                printReport(name, math, physics, english);
                break;

            case 4:
                break;

            default:
                std::cout << "Something went wrong. Exiting application."
                          << std::endl;
                break;
            }

            if (op == 4)
            {
                break;
            }
        }
    }

    return 0;
}