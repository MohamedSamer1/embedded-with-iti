#include <iostream>
#include <string>
#include <vector>
#include <array>

int main()
{
    // 1 initialization
    std::vector<int> v1;

    // 2 initialization
    std::vector<int> v2(5);     // 5 elements zero value
    std::vector<int> v3(5, 10); // 5 elemets valuse = 10 {10,10,10,10,10}

    // 3 initialization
    std::vector<int> v4{1, 2};    // 2 elements value = {1,2}
    std::vector<int> v5 = {1, 2}; // 2 elements value = {1,2}

    // 4 initialization
    int arr[] = {1, 2, 3}; // array of 3
    std::vector<int> v6(arr, arr + sizeof(arr) / sizeof(arr[0])); // copy from array 
    //OR
    std::vector<int> v10(std::begin(arr), std::end(arr)); // copy from array
    return 0;
}