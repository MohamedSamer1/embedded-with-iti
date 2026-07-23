#include <iostream>

class Vehicle
{
protected:
    std::string brand;
    int year;

public:
    Vehicle()
    {
        brand = "unknown";
        year = 0;
        std::cout << "default constructor for vehicle class\n";
    }
    Vehicle(std::string brand, int year)
    {
        this->brand = brand;
        this->year = year;
        std::cout << "parametrized constructor for vehicle class\n";
    }
    virtual void startEngine()
    {
        std::cout << "Vehicle engine started: " << brand << "\n";
    }
    ~Vehicle()
    {
        std::cout << "parametrized destructor for vehicle class\n";
    }
};

class Car : public Vehicle
{
public:
    Car()
    {
        brand = "unknown";
        year = 0;
        std::cout << "default constructor for car class\n";
    }
    Car(std::string brand, int year) : Vehicle(brand, year)
    {
        std::cout << "parametrized constructor of Car\n";
    }
    virtual void startEngine() override
    {
        std::cout << "Car engine started: " << brand << "\n";
    }
    ~Car()
    {
        std::cout << "parametrized destructor for car class\n";
    }
};

class Truck : public Vehicle
{
public:
    Truck()
    {
        brand = "unknown";
        year = 0;
        std::cout << "default constructor for truck class\n";
    }
    Truck(std::string brand, int year) : Vehicle(brand, year)
    {
        std::cout << "parametrized constructor of truck\n";
    }
    virtual void startEngine() override
    {
        std::cout << "Truck engine started: " << brand << "\n";
    }
    ~Truck()
    {
        std::cout << "parametrized destructor for truck class\n";
    }
};

class Plane : public Vehicle
{
public:
    Plane()
    {
        brand = "unknown";
        year = 0;
        std::cout << "default constructor for Plane class\n";
    }
    Plane(std::string brand, int year) : Vehicle(brand, year)
    {
        std::cout << "parametrized constructor of Plane\n";
    }
    virtual void startEngine() override
    {
        std::cout << "Plane engine started: " << brand << "\n";
    }
    ~Plane()
    {
        std::cout << "parametrized destructor for Plane class\n";
    }
};

class Motor : public Vehicle
{
public:
    Motor()
    {
        brand = "unknown";
        year = 0;
        std::cout << "default constructor for Motor class\n";
    }
    Motor(std::string brand, int year) : Vehicle(brand, year)
    {
        std::cout << "parametrized constructor of Motor\n";
    }
    virtual void startEngine() override
    {
        std::cout << "Motorcycle engine started: " << brand << "\n";
    }
    ~Motor()
    {
        std::cout << "parametrized destructor for Motor class\n";
    }
};

class Bicycle : public Vehicle
{
public:
    Bicycle()
    {
        brand = "unknown";
        year = 0;
        std::cout << "default constructor for Bicycle class\n";
    }
    Bicycle(std::string brand, int year) : Vehicle(brand, year)
    {
        std::cout << "parametrized constructor of Bicycle\n";
    }
    virtual void startEngine() override
    {
        std::cout << "Bicycle has no engine: " << brand << "\n";
    }
    ~Bicycle()
    {
        std::cout << "parametrized destructor for Bicycle class\n";
    }
};

class BMW : public Car
{
public:
    BMW()
        : Car()
    {
        std::cout << "default constructor for BMW class\n";
    }

    BMW(std::string brand, int year)
        : Car(brand, year)
    {
        std::cout << "paramterized constructor of BMW class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "BMW engine started: " << brand << "\n";
    }

    ~BMW()
    {
        std::cout << "destructor of BMW class\n";
    }
};

class Audi : public Car
{
public:
    Audi()
        : Car()
    {
        std::cout << "default constructor for Audi class\n";
    }

    Audi(std::string brand, int year)
        : Car(brand, year)
    {
        std::cout << "paramterized constructor of Audi class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "Audi engine started: " << brand << "\n";
    }

    ~Audi()
    {
        std::cout << "destructor of Audi class\n";
    }
};

class Boeing : public Plane
{
public:
    Boeing()
        : Plane()
    {
        std::cout << "default constructor for Plane class\n";
    }

    Boeing(std::string brand, int year)
        : Plane(brand, year)
    {
        std::cout << "paramterized constructor of Boeing class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "Boeing engines started: " << brand << "\n";
    }

    ~Boeing()
    {
        std::cout << "destructor of Boeing class\n";
    }
};

class Airbus : public Plane
{
public:
    Airbus()
        : Plane()
    {
        std::cout << "default constructor for Airbus class\n";
    }

    Airbus(std::string brand, int year)
        : Plane(brand, year)
    {
        std::cout << "paramterized constructor of Airbus class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "Airbus engines started: " << brand << "\n";
    }

    ~Airbus()
    {
        std::cout << "destructor of Airbus class\n";
    }
};

class Volvo : public Truck
{
public:
    Volvo()
        : Truck()
    {
        std::cout << "default constructor for Volvo class\n";
    }

    Volvo(std::string brand, int year)
        : Truck(brand, year)
    {
        std::cout << "paramterized constructor of Volvo class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "Volvo truck engine started: " << brand << "\n";
    }

    ~Volvo()
    {
        std::cout << "destructor of Volvo class\n";
    }
};

class Isuzu : public Truck
{
public:
    Isuzu()
        : Truck()
    {
        std::cout << "default constructor for Isuzu class\n";
    }

    Isuzu(std::string brand, int year)
        : Truck(brand, year)
    {
        std::cout << "paramterized constructor of Isuzu class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "Isuzu truck engine started: " << brand << "\n";
    }

    ~Isuzu()
    {
        std::cout << "destructor of Isuzu class\n";
    }
};

class Honda : public Motor
{
public:
    Honda()
        : Motor()
    {
        std::cout << "default constructor for Honda class\n";
    }

    Honda(std::string brand, int year)
        : Motor(brand, year)
    {
        std::cout << "paramterized constructor of Honda class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "Honda motorcycle engine started: " << brand << "\n";
    }

    ~Honda()
    {
        std::cout << "destructor of Honda class\n";
    }
};

class Yamaha : public Motor
{
public:
    Yamaha()
        : Motor()
    {
        std::cout << "default constructor for Yamaha class\n";
    }

    Yamaha(std::string brand, int year)
        : Motor(brand, year)
    {
        std::cout << "paramterized constructor of Yamaha class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "Yamaha motorcycle engine started: " << brand << "\n";
    }

    ~Yamaha()
    {
        std::cout << "destructor of Yamaha class\n";
    }
};

class BMX : public Bicycle
{
public:
    BMX()
        : Bicycle()
    {
        std::cout << "default constructor for BMX  class\n";
    }

    BMX(std::string brand, int year)
        : Bicycle(brand, year)
    {
        std::cout << "paramterized constructor of BMX  class\n";
    }

    virtual void startEngine() override
    {
        std::cout << "BMX has no engine: " << brand << "\n";
    }

    ~BMX()
    {
        std::cout << "destructor of BMX  class\n";
    }
};

int main()
{

    Vehicle *ptr;

    BMW bmw("BMW", 2024);
    Audi audi("Audi", 2023);
    Boeing boeing("Boeing", 2020);
    Airbus airbus("Airbus", 2022);
    Volvo volvo("Volvo", 2021);
    Isuzu isuzu("Isuzu", 2019);
    Honda honda("Honda", 2025);
    Yamaha yamaha("Yamaha", 2024);
    BMX bmx("BMX", 2023);

    std::cout << "\n===================================\n\n";

    bmw.startEngine();
    audi.startEngine();
    boeing.startEngine();
    airbus.startEngine();
    volvo.startEngine();
    isuzu.startEngine();
    honda.startEngine();
    yamaha.startEngine();
    bmx.startEngine();

    std::cout << "\n===================================\n\n";

    ptr = &bmw;
    ptr->startEngine();

    ptr = &audi;
    ptr->startEngine();

    ptr = &boeing;
    ptr->startEngine();

    ptr = &airbus;
    ptr->startEngine();

    ptr = &volvo;
    ptr->startEngine();

    ptr = &isuzu;
    ptr->startEngine();

    ptr = &honda;
    ptr->startEngine();

    ptr = &yamaha;
    ptr->startEngine();

    ptr = &bmx;
    ptr->startEngine();

    std::cout << "\n===================================\n\n";

    return 0;
}