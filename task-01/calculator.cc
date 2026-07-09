#include <iostream>

int main()
{
    char op;
    float num1, num2;
    int num11, num22;

    std::cout << "Enter an operator (+, -, *, /, %): ";
    std::cin >> op;
    while (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
    {
        std::cout << "Invalid operator. Choose again: ";
        std::cin >> op;
    }

    if (op == '%')
    {
        std::cout << "modulus operator opreator works only with integers" << std::endl;
        std::cout << "Enter first number: " << std::endl;
        std::cin >> num11;
        std::cout << "Enter second number: " << std::endl;
        std::cin >> num22;
    }
    else
    {
        std::cout << op << " opreator can work with either integers or floats" << std::endl;
        std::cout << "Enter first number: " << std::endl;
        std::cin >> num1;
        std::cout << "Enter second number: " << std::endl;
        std::cin >> num2;
    }

    if (op == '%')
    {
        switch (op)
        {
        case '+':
            std::cout << "Result: " << num11 + num22 << std::endl;
            break;
        case '%':
            std::cout << "Result: " << num11 % num22 << std::endl;
            break;

        case '-':
            std::cout << "Result: " << num11 - num22 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num11 * num22 << std::endl;
            break;
        case '/':
            if (num2 != 0)
            {
                std::cout << "Result: " << num11 / num22 << std::endl;
            }
            else
            {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
        }
    }

    else
    {
        switch (op)
        {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;

        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0)
            {
                std::cout << "Result: " << num1 / num2 << std::endl;
            }
            else
            {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
        }
    }
    

    return 0;
}
