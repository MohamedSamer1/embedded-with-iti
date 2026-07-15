#include <iostream>
#include <string>
#include <vector>
#include <array>

int main()
{
    // 1 initialization
    std::vector<int> v1;
    std::cout << "vector 1: ";
    for (int x : v1)
    {
        std::cout << x << " "; // vector 1: no output (empty)
    }
    std::cout << "\n===============\n";

    // 2 initialization
    std::vector<int>
        v2(5);                  // 5 elements zero value
    std::vector<int> v3(5, 10); // 5 elemets valuse = 10 {10,10,10,10,10}
    std::cout << "vector 2: ";
    for (int x : v2)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "vector 3: ";
    for (int x : v3)
    {
        std::cout << x << " ";
    }
    std::cout << "\n===============\n";

    // 3 initialization
    std::vector<int> v4{1, 2};    // 2 elements value = {1,2}
    std::vector<int> v5 = {1, 2}; // 2 elements value = {1,2}
    std::cout << "vector 4: ";
    for (int x : v4)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "vector 5: ";
    for (int x : v5)
    {
        std::cout << x << " ";
    }
    std::cout << "\n===============\n";

    // 4 initialization
    int arr[] = {1, 2, 3};                                        // array of 3
    std::vector<int> v6(arr, arr + sizeof(arr) / sizeof(arr[0])); // copy from array
    // OR
    std::vector<int> v7(std::begin(arr), std::end(arr)); // copy from array
    std::cout << "vector 6: ";
    for (int x : v6)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "vector 7: ";
    for (int x : v7)
    {
        std::cout << x << " ";
    }
    std::cout << "\n===============\n\n\n";

    std::vector<int> vectorTesting;
    std::cout << "Vector before push back function: \n";
    for (int x : vectorTesting)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    vectorTesting.push_back(10);
    std::cout << "Vector after adding 10 through push back function: \n";
    for (int x : vectorTesting)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "\n";
    vectorTesting.pop_back();
    std::cout << "Vector after popping function \n";
    for (int x : vectorTesting)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    vectorTesting.push_back(10);
    vectorTesting.push_back(10);
    vectorTesting.push_back(10);
    std::cout << "Vector after adding 10 through 3 push back function: \n";
    for (int x : vectorTesting)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    vectorTesting.insert(vectorTesting.begin() + 2, 99);
    std::cout << "Vector after inserting 99 at index 2: \n";
    for (int x : vectorTesting)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    vectorTesting.erase(vectorTesting.begin() + 2);
    std::cout << "Vector after removing 99 at index 2: \n";
    for (int x : vectorTesting)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    vectorTesting.erase(vectorTesting.begin(), vectorTesting.end());
    std::cout << "Vector after removing from begaining to end: \n";
    for (int x : vectorTesting)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    vectorTesting.push_back(1);
    vectorTesting.push_back(2);
    vectorTesting.push_back(3);

    vectorTesting.clear();
    std::cout << "Vector after removing everything using clear: \n";
    for (int x : vectorTesting)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    vectorTesting.push_back(1);
    vectorTesting.push_back(2);
    vectorTesting.push_back(3);

    std::cout << "Size: " << vectorTesting.size() << "\n";
    std::cout << "Is empty? " << std::boolalpha << vectorTesting.empty() << "\n\n";

    std::cout << "First element: " << vectorTesting.front() << "\n";
    std::cout << "Last element : " << vectorTesting.back() << "\n\n";

    std::cout << vectorTesting[1] << "\n";
    std::cout << vectorTesting.at(1) << "\n\n";

    std::cout
        << "===============\n";
    return 0;
}