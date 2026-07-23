#include <iostream>

class Geometeric
{
protected:
    float dim1;
    float dim2;

public:
    Geometeric()
    {
        dim1 = 0;
        dim2 = 0;
        std::cout << "geometeric constructor\n";
    }
    Geometeric(float dim1, float dim2)
    {
        this->dim1 = dim1;
        this->dim2 = dim2;
        std::cout << "geometeric parametrized constructor\n";
    }

    virtual float getArea()
    {
        std::cout << "gemoetric area\n";
        return 0.0;
    }
    ~Geometeric()
    {
        std::cout << "geometeric destructor\n";
    }
};

class Triangle : public Geometeric
{
public:
    Triangle()
    {

        std::cout << "constructor of triangle\n";
    }
    Triangle(float dim1, float dim2) : Geometeric(dim1, dim2)
    {
        std::cout << "parametrized constructor of triangle\n";
    }

    virtual float getArea()
    {
        std::cout << "Triangle area: " << 0.5 * dim1 * dim2 << "\n";
        return dim1 * dim2 * 0.5;
    }
    ~Triangle()
    {
        std::cout << "destructor of triangle\n";
    }
};

class Rectangle : public Geometeric
{
public:
    Rectangle()
    {

        std::cout << "constructor of rectangle\n";
    }
    Rectangle(float dim1, float dim2) : Geometeric(dim1, dim2)
    {
        std::cout << "parametrized constructor of rectangle\n";
    }

    virtual float getArea()
    {
        std::cout << "Rectangle area: " << (dim1 * dim2) << "\n";
        return dim1 * dim2;
    }
    ~Rectangle()
    {
        std::cout << "destructor of Rectangle\n";
    }
};

class Square : public Rectangle
{
public:
    Square()
        : Rectangle()
    {
        std::cout << "constructor of square\n";
    }

    Square(int dim)
        : Rectangle(dim, dim)
    {
        std::cout << "paramterized constructor of square\n";
    }

    virtual float getArea()
    {
        std::cout << "Square area: " << dim1 * dim2 << "\n";
        return dim1 * dim2;
    }

    ~Square()
    {
        std::cout << "destructor of square\n";
    }
};

int main()
{
    Geometeric *shapes[3];

    shapes[0] = new Triangle(10, 5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Square(7);

    for (int i = 0; i < 3; i++)
    {
        std::cout << shapes[i]->getArea() << "\n";
    }

    for (int i = 0; i < 3; i++)
    {
        delete shapes[i];
    }
}
