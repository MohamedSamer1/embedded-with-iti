#include <iostream>

void increment(int *num)
{
    (*num)++;
    std::cout << "The number became: " << *num << std::endl;
}

void decrement(int *num)
{
    (*num)--;
    std::cout << "The number became: " << *num << std::endl;
}
void reset(int *num)
{
    (*num) = 0;
    std::cout << "The number became: " << *num << std::endl;
}
void printNumber(int *num)
{
    std::cout << "Current number is: " << *num << std::endl;
    std::cout << "The address of current number is: " << num << std::endl;
    std::cout << "The address of the copy of the pointer is:" << &num << std::endl;
}

int main()
{
    int x = 5;
    std::cout << "choose a whole number: ";
    std::cin >> x;
    int *num = &x;
    int op = 0;
    while (true)
    {
        std::cout << "=============== Number Manager ===============\n";
        std::cout << "1. Increment" << std::endl;
        std::cout << "2. Decrement" << std::endl;
        std::cout << "3. Reset to 0" << std::endl;
        std::cout << "4. Show Num" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Please choose an opreation (1-5): ";
        std::cin >> op;
        while (op > 5 || op < 1)
        {
            std::cout << "Please enter a vaild number from 1 to 5" << std::endl;
            std::cout << "Please choose an opreation (1-5): ";
            std::cin >> op;
        }

        switch (op)
        {
        case 1:
            increment(num);
            break;
        case 2:
            decrement(num);
            break;
        case 3:
            reset(num);
            break;
        case 4:
            printNumber(num);
            break;
        case 5:

            break;
        default:
            std::cout << "something wrong happend exiting application" << std::endl;

            break;
        }
        if (op == 5)
        {
            break;
        }
    }
    return 0;
}