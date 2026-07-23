#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
    std::map<char, int> repeat;
    std::string str1 = "Mohamed";

    for (char x : str1)
    {
        x = tolower(x);
        repeat[x]++;
    }

    for (char x : str1)
    {
        x = tolower(x);
        std::cout << x << " : " << repeat[x] << '\n';
    }
    std::cout << " \n";

    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {9, 3, 4, 6};
    std::vector<int> intersection;
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            if (v1.at(i) == v2.at(j))
            {
                intersection.push_back(v1.at(i));
            }
        }
    }
    if (!intersection.empty())
    {
        for (int x : intersection)
        {

            std::cout << x << " ";
        }
    }
    else
    {
        std::cout << "no intersection";
    }
}