#include <iostream>
#include <string>

int add(int a, int b)
{
    for (int i = 0; i < b; i++)
    {
        a++;
    }
    return a;
}

int sub(int a, int b)
{
    for (int i = 0; i < b; i++)
    {
        a--;
    }
    return a;
}

int mult(int a, int b)
{
    int result = 0;

    for (int i = 0; i < b; i++)
    {
        result += a;
    }
    return result;
}

int divi(int a, int b)
{
    int result = 0;

    while (a >= b)
    {
        a = sub(a, b);
        result++;
    }

    return result;
}
int main()
{
    std::string str = "mohamed";

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < str.length() - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    std::cout << str << "\n";

    std::cout << add(5, 9) << "\n";
    std::cout << mult(2, 3) << "\n";
    std::cout << divi(6, 2) << "\n";

    int num1 = 5;
    int num2 = 15;
    std::cout << "num1:" << num1 << "\tnum2:" << num2 << "\n";

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    std::cout << "num1:" << num1 << "\tnum2:" << num2 << "\n";

    return 0;
}