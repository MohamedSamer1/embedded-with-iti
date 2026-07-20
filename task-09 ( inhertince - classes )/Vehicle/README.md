# 🚗 C++ Multi-Level Inheritance & Runtime Polymorphism

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Intermediate-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A hands-on C++ project that demonstrates **Multi-Level Inheritance**, **Hierarchical Inheritance**, **Function Overriding**, and **Runtime Polymorphism** using a realistic vehicle hierarchy.

The project builds a complete inheritance tree beginning with a generic `Vehicle` class and extending into multiple categories such as cars, trucks, airplanes, motorcycles, and bicycles. Specialized brands inherit from these categories and provide their own implementation of the `startEngine()` function.

This project was built as a practice exercise to strengthen Object-Oriented Programming concepts including inheritance, constructor chaining, virtual functions, overriding, base-class pointers, and dynamic dispatch.

---

## ✨ Features

* Create a common base `Vehicle` class
* Demonstrate hierarchical inheritance
* Demonstrate multi-level inheritance
* Override virtual member functions
* Implement runtime polymorphism
* Access derived objects using base-class pointers
* Demonstrate constructor chaining
* Demonstrate destructor execution order
* Simulate different vehicle engine behaviors

---

## 🖥️ Program Flow

The program performs the following operations:

```text
1. Create different vehicle objects:
      • BMW
      • Audi
      • Boeing
      • Airbus
      • Volvo
      • Isuzu
      • Honda
      • Yamaha
      • BMX

2. Call startEngine() directly

3. Create a Vehicle pointer

4. Point the Vehicle pointer to each derived object

5. Call startEngine() through the base pointer

6. Observe runtime polymorphism
```

---

## 🛠️ Technologies Used

* C++
* Standard Library

  * `<iostream>`
  * `<string>`

---

## 📚 Concepts Practiced

This project demonstrates the use of:

* Object-Oriented Programming (OOP)
* Classes and Objects
* Encapsulation
* Inheritance
* Hierarchical Inheritance
* Multi-Level Inheritance
* Constructor Chaining
* Function Overriding
* Virtual Functions
* Runtime Polymorphism
* Dynamic Binding
* Base-Class Pointers
* Protected Members
* Destructor Chaining
* The `this` Pointer
* Console Output

---

## 🚘 Inheritance Hierarchy

```text
                           Vehicle
     ┌────────────┬────────────┬────────────┬────────────┬────────────┐
     │            │            │            │            │
    Car         Truck        Plane        Motor      Bicycle
   ┌───┴───┐    ┌──┴──┐     ┌──┴──┐      ┌──┴──┐         │
 BMW     Audi  Volvo Isuzu Boeing Airbus Honda Yamaha   BMX
```

---

## 📦 Classes

| Class | Inherits From | Purpose |
|--------|---------------|---------|
| `Vehicle` | — | Base class for all vehicles |
| `Car` | `Vehicle` | Generic car |
| `Truck` | `Vehicle` | Generic truck |
| `Plane` | `Vehicle` | Generic airplane |
| `Motor` | `Vehicle` | Generic motorcycle |
| `Bicycle` | `Vehicle` | Generic bicycle |
| `BMW` | `Car` | BMW car |
| `Audi` | `Car` | Audi car |
| `Volvo` | `Truck` | Volvo truck |
| `Isuzu` | `Truck` | Isuzu truck |
| `Boeing` | `Plane` | Boeing aircraft |
| `Airbus` | `Plane` | Airbus aircraft |
| `Honda` | `Motor` | Honda motorcycle |
| `Yamaha` | `Motor` | Yamaha motorcycle |
| `BMX` | `Bicycle` | BMX bicycle |

---

## 📦 Constructors

Each class provides:

| Constructor | Description |
|------------|-------------|
| Default Constructor | Creates an object with default values |
| Parameterized Constructor | Initializes brand and manufacturing year |

---

## 📦 Virtual Functions

| Function | Description |
|----------|-------------|
| `Vehicle::startEngine()` | Base virtual function |
| `Car::startEngine()` | Car implementation |
| `Truck::startEngine()` | Truck implementation |
| `Plane::startEngine()` | Plane implementation |
| `Motor::startEngine()` | Motorcycle implementation |
| `Bicycle::startEngine()` | Bicycle implementation |
| Brand classes | Override their category implementation |

---

## 🚀 Future Improvements

Some planned improvements include:

* Make the base destructor `virtual`
* Replace raw pointers with `std::unique_ptr`
* Store vehicles inside `std::vector`
* Add getters and setters
* Add speed and fuel attributes
* Implement abstract base class using pure virtual functions
* Add electric vehicles
* Add boats and helicopters
* Overload stream insertion (`<<`)
* Implement copy constructor and assignment operator
* Apply the Rule of Five
* Add namespaces and separate header/source files

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o VehicleSystem
```

Run:

```bash
./VehicleSystem
```

---

## 📷 Example Output

```text
===================================

BMW engine started: BMW
Audi engine started: Audi
Boeing engines started: Boeing
Airbus engines started: Airbus
Volvo truck engine started: Volvo
Isuzu truck engine started: Isuzu
Honda motorcycle engine started: Honda
Yamaha motorcycle engine started: Yamaha
BMX has no engine: BMX

===================================

BMW engine started: BMW
Audi engine started: Audi
Boeing engines started: Boeing
Airbus engines started: Airbus
Volvo truck engine started: Volvo
Isuzu truck engine started: Isuzu
Honda motorcycle engine started: Honda
Yamaha motorcycle engine started: Yamaha
BMX has no engine: BMX
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several intermediate C++ concepts, including:

* Designing large inheritance hierarchies
* Understanding hierarchical and multi-level inheritance
* Implementing function overriding
* Using virtual functions
* Understanding runtime polymorphism
* Working with base-class pointers
* Understanding constructor and destructor chaining
* Applying dynamic binding
* Organizing classes using inheritance instead of duplication

This project serves as a strong foundation for learning abstract classes, interfaces, multiple inheritance, virtual inheritance, smart pointers, templates, and Modern C++ design patterns.

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #9 |
| **Project** | C++ Multi-Level Inheritance & Runtime Polymorphism |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Ninth(2) project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, Robotics, Qt/QML, Linux, and Modern C++