#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string str1 = "Hello ITI   my name is mohamed";
    int count = 1;

    for (char x : str1)
    {
        if (x == ' ')
        {
            count++;
        }
    }
    std::cout << "Number of words: " << count << std::endl;
    count = 1;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1.at(i) == ' ' && str1[i + 1] != ' ')
        {
            count++;
        }
    }
    std::cout << "Number of words: " << count << std::endl;

    std::vector<int> v1 = {3, 7, 4, 9, 12, 6, 1, 11, 2};

    std::sort(v1.begin(), v1.end());

    for (int i = 0; i < v1.size() - 1; i++)
    {
        if (v1[i + 1] - v1[i] > 1)
        {
            for (int j = v1.at(i) + 1; j < v1[i + 1]; j++)
            {
                std::cout << j << " ";
            }
        }
        std::cout << "\n";

        std::vector<int> v = {3, 7, 4, 9, 12, 6, 1, 11, 2};

        int small = v.at(0);
        int big = v.at(0);
        for (int i = 0; i < v.size(); i++)
        {
            if (small > v.at(i))
            {
                small = v.at(i);
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (big < v.at(i))
            {
                big = v.at(i);
            }
        }
        for (int i = small; i <= big; i++)
        {
            count = 0;

            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == i)
                {
                    count++;
                }
            }

            if (count == 0)
            {
                std::cout << i << " ";
            }
        }
    }
}