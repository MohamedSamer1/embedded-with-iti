#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 5, 6, 8, 9, 12};
    std::vector<int> v2 = {1, 0, 2, 0, 5, 0, 9};
    std::string str1 = "madam";

    int k = 3;

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            if (numbers.at(i) + numbers.at(j) == k)
            {
                std::cout << "numbers are: " << numbers.at(i) << " " << numbers.at(j) << std::endl;
            }
        }
    }

    for (int i = v2.size() - 1; i >= 0; i--)
    {
        if (v2.at(i) == 0)
        {
            v2.erase(v2.begin() + i);
            v2.push_back(0);
        }
    }
    std::cout << "vector after sending zero to the end: ";
    for (int x : v2)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::string str2 = str1;
    for (int i = 0; i < str2.size(); i++)
    {
        char last = str2.at(str2.size() - 1);
        str2.pop_back();
        str2.insert(str2.begin(), last);
    }

    if (str1 == str2)
    {
        std::cout << "panlindome\n";
    }
    else
    {
        std::cout << " not panlindome\n";
    }
}