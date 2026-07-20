#include <iostream>
#include <string>

int main()
{
    std::string str1 = "hello world";
    std::string temp;
    std::string result;

    for (char z : str1)
    {
        if (z == ' ')
        {
            if (result.empty())
            {
                result = temp;
            }
            else
            {
                result = temp + " " + result;
            }

            temp.clear();
        }
        else
        {
            temp = temp + z;
        }
    }
    result = temp + " " + result;
    std::cout << result<<std::endl;



    time_t firstTime = time(NULL);
    while (true)
    {
        time_t now = time(NULL);

        if (now - firstTime >= 1)
        {
            std::cout << "1\n";
            break;
        }
    }
}