#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> v1 = {0, 2, 3, 4};
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int x : v1)
        {
            if (x == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            std::cout << "number: " << i << "\n";
        }
    }

    std::string str1 = "aabbfqtcddee";
    int count = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        count = 0;

        for (int j = 0; j < str1.size(); j++)
        {
            if (str1.at(i) == str1.at(j))
            {
                count++;
            }
        }
        if (count <= 1)
        {
            std::cout << str1.at(i) << "\n";
        }
    }

    return 0;
}