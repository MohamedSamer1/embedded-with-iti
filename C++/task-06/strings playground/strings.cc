#include <iostream>
#include <string>

int main()
{
    std::string str1 = "hello, world";
    std::string str2 = "C++";

    std::cout << "string lenght: " << str1.length() << std::endl;
    std::cout << "string size: " << str1.size() << std::endl;
    std::cout << "string capacity: " << str1.capacity() << std::endl;
    std::cout << "string empty: " << str1.empty() << std::endl;

    std::cout << "string insert (!): " << str1.insert(12, "!") << std::endl;
    std::cout << "string erase (!): " << str1.erase(12) << std::endl;

    str1.push_back('D');
    std::cout << "string after push_back(): " << str1 << std::endl;

    str1.pop_back();
    std::cout << "string after pop_back(): " << str1 << std::endl;

    std::cout << "string append ( C++): " << str1.append(" C++") << std::endl;
    std::cout << "string += ( Programming): " << (str1 += " Programming") << std::endl;
    std::cout << "string replace (hello -> Hi): " << str1.replace(0, 5, "Hi") << std::endl;

    std::cout << "string find (C++): " << str1.find("C++") << std::endl;
    std::cout << "string rfind (g): " << str1.rfind("g") << std::endl;
    std::cout << "string substr: " << str1.substr(3, 5) << std::endl;

    std::cout << "string front: " << str1.front() << std::endl;
    std::cout << "string back: " << str1.back() << std::endl;

    std::cout << "string at(2): " << str1.at(2) << std::endl;
    std::cout << "string operator[]: " << str1[2] << std::endl;

    std::cout << "string compare: " << str1.compare(str2) << std::endl;

    str1.swap(str2);
    std::cout << "string after swap (str1): " << str1 << std::endl;
    std::cout << "string after swap (str2): " << str2 << std::endl;

    str1.resize(10);
    std::cout << "string after resize(): " << str1 << std::endl;

    str1.reserve(50);
    std::cout << "string reserve(): " << str1.capacity() << std::endl;

    str1.shrink_to_fit();
    std::cout << "string shrink_to_fit(): " << str1.capacity() << std::endl;

    std::cout << "string c_str(): " << str1.c_str() << std::endl;

    str1.clear();
    std::cout << "string after clear(): " << str1 << std::endl;
}