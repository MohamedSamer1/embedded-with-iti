#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

std::vector<int> v1 = {1, 3, 5, 7};
std::vector<int> v2 = {2, 4, 6};
std::vector<int> mergedVector;
int maxSize;

int main()
{
    mergedVector.insert(mergedVector.end(), v1.begin(), v1.end());
    mergedVector.insert(mergedVector.end(), v2.begin(), v2.end());
    std::sort(mergedVector.begin(), mergedVector.end());
    std::cout << "Merged: ";
    for (int x : mergedVector)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    mergedVector.clear();

    std::vector<int> negativeV1 = {-1, -5, 3, 2, 1};
    int z = 0;
    for (int i = 0; i < negativeV1.size(); i++)
    {
        if (negativeV1.at(i) < 0)
        {
            negativeV1.erase(negativeV1.begin() + i);
            i--;
        }
        else
        {
            i++;
        }
    }
    std::cout << "\n";
    std::cout << "removed negative: ";
    for (int x : negativeV1)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    int sum1 = 0;
    int sum2 = 0;
    std::vector<int> sumV1 = {1, 2, 6, 1};
    std::vector<int> sumV2 = {9, 1, 8};

    for (int x : sumV1)
    {
        sum1 += x;
    }
    for (int x : sumV2)
    {
        sum2 += x;
    }
    std::cout << "sum 1: " << sum1;
    std::cout << "   sum 2: " << sum2 << std::endl;
    if (sum1 == sum2)
    {
        std::cout << "They are equal\n";
    }
    else if (sum1 > sum2)
    {
        std::cout << "sum of vector 1 is larger, they are not equal\n";
    }
    else if (sum1 < sum2)
    {
        std::cout << "sum of vector 2 is larger, they are not equal\n";
    }
    else
    {
        std::cout << "error\n";
    }

    int voulNum = 0;
    std::string str1 = "Mohamed";
    for (int x : str1)
    {
        if (x == 'o' || x == 'e' || x == 'i' || x == 'a' || x == 'u')
        {
            voulNum++;
        }
    }
    std::cout << "Number of vowels: " << voulNum << std::endl;
    std::string str2 = "";

    str2.insert(str2.end(), str1.rbegin(), str1.rend());
    std::cout << "String: " << str1;
    std::cout << "Reversed String: " << str2;
    
}