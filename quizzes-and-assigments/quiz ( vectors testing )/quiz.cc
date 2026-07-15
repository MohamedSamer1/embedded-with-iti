#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int numberVector1 = 0;
    int numberVector2 = 0;

    std::vector<int> v1;
    std::vector<int> v2;
    std::cout << "Enter vector 1 elements\n"
              << "how many element: \n";
    std::cin >> numberVector1;
    for (int i = 0; i < numberVector1; i++)
    {
        int num = 0;
        std::cout << "Enter the values of vector\n";
        std::cout << "value " << i << ": " << std::endl;
        std::cin >> num;
        v1.push_back(num);
    }

    std::cout << "Enter vector 2 elements\n"
              << "how many element: \n";
    std::cin >> numberVector2;
    for (int i = 0; i < numberVector2; i++)
    {
        int num = 0;
        std::cout << "Enter the values of vector\n";
        std::cout << "value " << i << ": " << std::endl;
        std::cin >> num;
        v2.push_back(num);
    }

    if (v1 == v2)
    {
        std::cout << "Vectors are equal" << std::endl;
    }
    else
    {
        std::cout << "Vectors are not equal" << std::endl;
    }

    int maxValue1 = *std::max_element(v1.begin(), v1.end());
    int minValue1 = *std::min_element(v1.begin(), v1.end());

    int maxValue2 = *std::max_element(v2.begin(), v2.end());
    int minValue2 = *std::min_element(v2.begin(), v2.end());

    std::cout << "\nmax vaule of vector 1: " << maxValue1 << "\nmin value of vector 1: " << minValue1;
    std::cout << "\nmax vaule of vector 2: " << maxValue2 << "\nmin value of vector 2: " << minValue2;
    std::cout << "\n";

    int minVecNum = 0;
    if (numberVector1 > numberVector2)
    {
        minVecNum = numberVector2;
    }
    else if (numberVector2 > numberVector1)
    {
        minVecNum = numberVector1;
    }
    else
    {
        std::cout << "oh equal\n";
        minVecNum = numberVector2;
    }

    for (int i = 0; i < minVecNum; i++)
    {
        if (v1.at(i) == v2.at(i))
        {
            std::cout << "element " << i << " in both vectors are equals\n";
        }
        else if (v1.at(i) != v2.at(i))
        {
            std::cout << "element " << i << " in both vectors are not equals\n";
        }
        else
        {
            std::cout << "error\n";
        }
    }
    std::cout << "\n";
    std::cout << "vector before reversing: ";
    for (int y : v1)
    {
        std::cout << y << " ";
    }
    std::cout << "\n";
    std::reverse(v1.begin(), v1.end());
    std::cout << "vector after reversing: ";
    for (int y : v1)
    {
        std::cout << y << " ";
    }
    std::cout << "\n";

    std::vector<int> reverseV1(v1.rbegin(), v1.rend());
    std::cout << "vector after reversing again: ";
    for (int y : reverseV1)
    {
        std::cout << y << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < numberVector1; i++)
    {
        int last = v1.at(numberVector1 - 1);
        v1.pop_back();
        v1.insert(v1.begin(), last);
    }

    std::cout << "vector after reversing again and again: ";
    for (int y : v1)
    {
        std::cout << y << " ";
    }
    std::cout << "\n";
}