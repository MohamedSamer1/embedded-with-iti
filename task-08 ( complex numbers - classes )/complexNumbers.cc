#include <iostream>

class Numbers
{
private:
    float img;
    float real;

public:
    Numbers()
    {
        img = 0;
        real = 0;
        std::cout << "defult constractor\n";
    }

    Numbers(float real)
    {
        img = 0;
        this->real = real;
        std::cout << "1 parameter constractor\n";
    }

    Numbers(float real, float img)
    {
        this->img = img;
        this->real = real;
        std::cout << "2 parameter constractor\n";
    }

    Numbers(const Numbers &other)
    {
        real = other.real;
        img = other.img;

        std::cout << "Copy Constructor\n";
    }

    ~Numbers()
    {
        std::cout << "Destructor\n";
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
            {
                std::cout << real;
            }

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
                else
                    std::cout << "-";

                if (img == -1)
                    std::cout << "i";
                else
                    std::cout << -img << "i";
            }
        }

        std::cout << '\n';
    }

    Numbers operator+(const Numbers &other)
    {
        return Numbers(real + other.real, img + other.img);
    }

    Numbers operator-(const Numbers &other)
    {
        return Numbers(real - other.real, img - other.img);
    }

    Numbers operator/(const Numbers &other)
    {
        return Numbers(real / other.real, img / other.img);
    }

    Numbers operator*(const Numbers &other)
    {
        return Numbers(real * other.real, img * other.img);
    }

    Numbers &operator++()
    {
        ++real;
        ++img;

        return *this;
    }

    Numbers &operator--()
    {
        --real;
        --img;

        return *this;
    }

    bool operator==(const Numbers &other)
    {
        return real == other.real && img == other.img;
    }

    bool operator!=(const Numbers &other)
    {
        return real != other.real || img != other.img;
    }

    bool operator<=(const Numbers &other)
    {
        return real <= other.real;
    }

    bool operator>=(const Numbers &other)
    {

        return real >= other.real;
    }

    bool operator<(const Numbers &other)
    {
        return real < other.real;
    }

    bool operator>(const Numbers &other)
    {
        return real > other.real;
    }

    Numbers &operator+=(const Numbers &other)
    {
        real += other.real;
        img += other.img;

        return *this;
    }

    Numbers &operator-=(const Numbers &other)
    {
        real -= other.real;
        img -= other.img;

        return *this;
    }

    Numbers &operator*=(const Numbers &other)
    {
        real *= other.real;
        img *= other.img;

        return *this;
    }

    Numbers &operator/=(const Numbers &other)
    {
        real /= other.real;
        img /= other.img;

        return *this;
    }

    Numbers operator++(int)
    {
        Numbers temp = *this;
        ++(*this);
        return temp;
    }

    Numbers operator--(int)
    {
        Numbers temp = *this;
        --(*this);
        return temp;
    }

    operator float()
    {
        return real;
    }

    operator int()
    {
        return static_cast<int>(real);
    }

    operator bool()
    {
        return real != 0 || img != 0;
    }

    operator double()
    {
        return static_cast<double>(real);
    }

    operator long()
    {
        return static_cast<long>(real);
    }
    operator short()
    {
        return static_cast<short>(real);
    }

    void operator()()
    {
        printClass();
    }

    void operator()(float real, float img)
    {
        this->img = img;
        this->real = real;
        std::cout << "Used function call constructor\n";
    }
};
int main()
{

    Numbers n1(9, -3);
    Numbers n2(4, 5);

    std::cout << "n1 = ";
    n1.printClass();

    std::cout << "n2 = ";
    n2.printClass();

    std::cout << "\n========== + ==========\n";
    Numbers sum = n1 + n2;
    sum.printClass();

    std::cout << "\n========== - ==========\n";
    Numbers sub = n1 - n2;
    sub.printClass();

    std::cout << "\n========== * ==========\n";
    Numbers mul = n1 * n2;
    mul.printClass();

    std::cout << "\n========== / ==========\n";
    Numbers div = n1 / n2;
    div.printClass();

    std::cout << "\n========== Prefix ++ ==========\n";
    ++n1;
    n1.printClass();

    std::cout << "\n========== Prefix -- ==========\n";
    --n1;
    n1.printClass();

    std::cout << "\n========== Postfix ++ ==========\n";
    (n1++).printClass();
    std::cout << "n1: ";
    n1.printClass();

    std::cout << "\n========== Postfix -- ==========\n";
    (n1--).printClass();
    std::cout << "n1: ";
    n1.printClass();

    std::cout << "\n========== += ==========\n";
    n1 += n2;
    n1.printClass();

    std::cout << "\n========== -= ==========\n";
    n1 -= n2;
    n1.printClass();

    std::cout << "\n========== *= ==========\n";
    n1 *= n2;
    n1.printClass();

    std::cout << "\n========== /= ==========\n";
    n1 /= n2;
    n1.printClass();

    std::cout << "\n========== == ==========\n";
    if (n1 == n2)
    {
        std::cout << "Equal\n";
    }
    else
    {
        std::cout << "Not Equal\n";
    }

    std::cout << "\n========== != ==========\n";
    if (n1 != n2)
    {
        std::cout << "Not eequal\n";
    }
    else
    {
        std::cout << "EQual\n";
    }

    std::cout << "\n========== < ==========\n";
    if (n1 < n2)
    {
        std::cout << "n1 < n2\n";
    }
    else
    {
        std::cout << "n1 >= n2\n";
    }

    std::cout << "\n========== > ==========\n";
    if (n1 > n2)
    {
        std::cout << "n1 > n2\n";
    }
    else
    {
        std::cout << "n1 <= n2\n";
    }

    std::cout << "\n========== <= ==========\n";
    if (n1 <= n2)
    {
        std::cout << "n1 <= n2\n";
    }
    else
    {
        std::cout << "n1 > n2\n";
    }

    std::cout << "\n========== >= ==========\n";
    if (n1 >= n2)
    {
        std::cout << "n1 >= n2\n";
    }
    else
    {
        std::cout << "n1 < n2\n";
    }

    std::cout << "\n========== cast ==========\n";

    std::cout << "float  : " << static_cast<float>(n1) << '\n';
    std::cout << "int    : " << static_cast<int>(n1) << '\n';
    std::cout << "bool   : " << static_cast<bool>(n1) << '\n';
    std::cout << "double : " << static_cast<double>(n1) << '\n';
    std::cout << "long   : " << static_cast<long>(n1) << '\n';
    std::cout << "short  : " << static_cast<short>(n1) << '\n';

    std::cout << "\n========== Bool ==========\n";

    Numbers zero;

    if (zero)
    {
        std::cout << "zero true\n";
    }
    else
    {
        std::cout << "zero false\n";
    }

    if (n1)
    {
        std::cout << "n1 true\n";
    }
    else
    {
        std::cout << "n1 false\n";
    }
    std::cout << "\n========== Copy Constructor ==========\n";

    Numbers copy = n1;
    copy.printClass();

    std::cout << "\n========== Call Operator  ==========\n";

    std::cout << "n1 = ";
    n1();

    std::cout << "n2 = ";
    n2();

    n1(10, 20);
    n1();

    return 0;
}