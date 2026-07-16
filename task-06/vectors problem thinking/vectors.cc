#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{

    // reverse in play
    std::vector<int> v1 = {1000, 1, 1, 1, 1, 2, 3, 4, 5, 4, 3, 1, 1, 2, 3, 4, 6, 7, 8, 3, 2, 1, 11, 99, 122};
    int right = v1.size() - 1;
    int left = 0;

    for (int x : v1)
    {
        if (left < right)
        {
            std::swap(v1[left], v1[right]);
            left++;
            right--;
        }
    }
    for (int x : v1)
    {
        std::cout << x << " ";
    }

    // reverse in place (my method)
    for (int i = 0; i < v1.size(); i++)
    {
        int last = v1.at(v1.size() - 1);
        v1.pop_back();
        v1.insert(v1.begin(), last);
    }

    std::cout << "\nvector after reversing again: ";
    for (int y : v1)
    {
        std::cout << y << " ";
    }

    // count number of occurance
    std::map<int, int> occ;
    for (int x : v1)
    {
        occ[x]++;
    }
    std::cout << "Key" << " : " << "Value\n";

    for (int x : v1)
    {
        std::cout << x << " : " << occ[x] << std::endl;
    }
    // or
    std::cout << "\n";

    std::cout << "Key" << " : " << "Value\n";
    for (const auto &pair : occ)
    {
        std::cout << pair.first << " : " << pair.second << '\n';
    }

    // get second greatest number
    std::sort(v1.begin(), v1.end());
    std::cout << "sorted: ";
    for (int y : v1)
    {
        std::cout << y << " ";
    }
    std::cout << "\n";
    std::cout << "second greatest element: " << v1.at(v1.size() - 2);

    // remove duplicates in vector

    /*
    we can order the array and then
    check what before and after each element if they are equal we delete them.
    */

    for (int i = 0; i < v1.size() - 1; i++)
    {
        if (v1[i] == v1[i + 1])
        {
            v1.erase(v1.begin() + i);
            i--;
        }
    }

    std::cout << "\nout: ";
    for (int y : v1)
    {
        std::cout << y << " ";
    }
}