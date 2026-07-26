#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> v1 = {-9, -4, -2, 5, 11};
    int close = v1.at(0);
    int one = 0;
    int two = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1.size(); j++)
        {
            int sum = v1[i] + v1[j];

            if (std::abs(sum) < std::abs(close))
            {
                close = sum;
                one = v1[i];
                two = v1[j];
            }
        }
    }
    std::cout << "Numbers: " << one << " " << two << '\n';
    std::cout << "Closest sum = " << close << std::endl;

    std::vector<int> v4 = {1, 2, 3, 3, 2, 1};
    std::vector<int> v3 = v4;

    std::reverse(v3.begin(), v3.end());

    if (v3 == v4)
    {
        std::cout << "panlindome\n";
    }
    else
    {
        std::cout << " not panlindome\n";

        return 0;
    }

    std::vector<int> numbers = {1, 2, 5, 6, 8, 9, 12};
    int k = 2;

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            if (numbers.at(i) - numbers.at(j) == k)
            {
                std::cout << "numbers are: " << numbers.at(i) << " " << numbers.at(j) << std::endl;
            }
        }
    }
}
