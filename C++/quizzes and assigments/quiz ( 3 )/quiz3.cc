#include <iostream>

class Complex
{
private:
    float img;
    float real;

public:
    Complex()
    {
        img = 0;
        real = 0;
        std::cout << "defult constractor\n";
    }
    Complex(float real)
    {
        img = 0;
        this->real = real;
        std::cout << "1 parameter constractor\n";
    }
    Complex(float real, float img)
    {
        this->img = img;
        this->real = real;
        std::cout << "2 parameter constractor\n";
    }
    ~Complex()
    {
        std::cout << "Destructor\n";
    }
    Complex add(Complex other)
    {
        return Complex(real + other.real, img + other.img);
    }
    void printClass()
    {
        if (real == 0 && img == 0)
        {
            std::cout << 0;
        }
        else
        {
            if (real != 0)
                std::cout << real;

            if (img > 0)
            {
                if (real != 0)
                    std::cout << " + ";

                if (img == 1)
                    std::cout << "i";
                else
                    std::cout << img << "i";
            }
            else if (img < 0)
            {
                if (real != 0)
                    std::cout << " - ";

                if (img == -1)
                    std::cout << "i";
                else
                    std::cout << -img << "i";
            }
        }

        std::cout << '\n';
    }
};
int main()
{
    Complex obj1(5, 3);
    Complex obj2(-3, 5);
    obj2.printClass();
    Complex result = obj1.add(obj2);
    result.printClass();
}