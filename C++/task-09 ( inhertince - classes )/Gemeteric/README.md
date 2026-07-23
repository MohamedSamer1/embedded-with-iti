# 🔺 C++ Inheritance & Runtime Polymorphism

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Intermediate-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A hands-on C++ project that demonstrates the fundamentals of **Inheritance** and **Runtime Polymorphism** using geometric shapes. The project defines a common base class and multiple derived classes, allowing different objects to be accessed through a single base-class pointer while executing their own implementations of `getArea()`.

This project was built as a practice exercise to strengthen Object-Oriented Programming concepts such as inheritance, virtual functions, constructor chaining, dynamic binding, and polymorphism.

---

## ✨ Features

* Create a common base class for geometric shapes
* Implement multiple derived classes
* Calculate the area of different shapes
* Demonstrate constructor chaining
* Demonstrate runtime polymorphism
* Store different derived objects in a single base-class pointer array
* Invoke overridden functions through virtual dispatch
* Demonstrate dynamic memory allocation using `new`
* Release allocated memory using `delete`

---

## 🖥️ Program Flow

The program performs the following operations:

```text
1. Create an array of Geometeric pointers
2. Dynamically create:
      • Triangle
      • Rectangle
      • Square
3. Store all objects inside the same array
4. Call getArea() using the base-class pointer
5. Observe runtime polymorphism
6. Delete all allocated objects
7. Observe constructor and destructor execution order
```

---

## 🛠️ Technologies Used

* C++
* Standard Library

  * `<iostream>`

---

## 📚 Concepts Practiced

This project demonstrates the use of:

* Object-Oriented Programming (OOP)
* Classes and Objects
* Inheritance
* Single Inheritance
* Multi-Level Inheritance
* Function Overriding
* Virtual Functions
* Runtime Polymorphism
* Dynamic Binding
* Base-Class Pointers
* Dynamic Memory Allocation
* Constructor Chaining
* Destructor Execution Order
* Encapsulation
* Protected Members
* The `this` Pointer
* Console Output

---

## 📦 Class Hierarchy

| Class | Inherits From | Purpose |
|--------|---------------|---------|
| `Geometeric` | — | Base class for all geometric shapes |
| `Triangle` | `Geometeric` | Calculates triangle area |
| `Rectangle` | `Geometeric` | Calculates rectangle area |
| `Square` | `Rectangle` | Special case of a rectangle |

---

## 📦 Constructors

| Constructor | Description |
|------------|-------------|
| `Geometeric()` | Default constructor |
| `Geometeric(float,float)` | Initializes dimensions |
| `Triangle()` | Default constructor |
| `Triangle(float,float)` | Initializes triangle dimensions |
| `Rectangle()` | Default constructor |
| `Rectangle(float,float)` | Initializes rectangle dimensions |
| `Square()` | Default constructor |
| `Square(int)` | Creates a square with equal sides |

---

## 📦 Virtual Functions

| Function | Description |
|----------|-------------|
| `virtual float getArea()` | Base virtual function |
| `Triangle::getArea()` | Returns triangle area |
| `Rectangle::getArea()` | Returns rectangle area |
| `Square::getArea()` | Returns square area |

---

## 🧬 Inheritance Structure

```text
             Geometeric
            /          \
      Triangle      Rectangle
                         |
                      Square
```

---

## 🚀 Future Improvements

Some planned improvements include:

* Make `Geometeric` an abstract class using a pure virtual function
* Make the base destructor `virtual`
* Mark overridden functions using the `override` keyword
* Make `getArea()` a `const` member function
* Add additional shapes such as:
  * Circle
  * Ellipse
  * Trapezoid
* Store shapes using STL containers (`std::vector`)
* Implement copy constructor and assignment operator
* Add input validation
* Overload stream operators (`<<` and `>>`)
* Explore modern C++ smart pointers (`std::unique_ptr`)

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o Polymorphism
```

Run:

```bash
./Polymorphism
```

---

## 📷 Example Output

```text
geometeric parametrized constructor
parametrized constructor of triangle

geometeric parametrized constructor
parametrized constructor of rectangle

geometeric parametrized constructor
parametrized constructor of rectangle
paramterized constructor of square

Triangle area: 25
25

Rectangle area: 24
24

Square area: 49
49

destructor of triangle
geometeric destructor

destructor of Rectangle
geometeric destructor

destructor of square
destructor of Rectangle
geometeric destructor
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several important Object-Oriented Programming concepts, including:

* Understanding inheritance
* Designing reusable base classes
* Implementing function overriding
* Using virtual functions for runtime polymorphism
* Working with base-class pointers
* Understanding constructor and destructor chaining
* Managing dynamically allocated objects
* Applying dynamic binding in C++

This project serves as a strong foundation for learning abstract classes, pure virtual functions, interfaces, multiple inheritance, virtual destructors, smart pointers, and advanced Modern C++ design patterns.

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #9 |
| **Project** | C++ Inheritance & Runtime Polymorphism |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Ninth(1) project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, Robotics, Qt/QML, Linux, and Modern C++