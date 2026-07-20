# ➕ C++ Operator Overloading

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Intermediate-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A hands-on C++ project that demonstrates the power of **Operator Overloading** in Object-Oriented Programming. The project implements a custom `Numbers` class that represents a complex number and overloads many of C++'s built-in operators to make user-defined objects behave like primitive data types.

This project was built as a practice exercise to understand how operators can be customized for classes while reinforcing concepts such as constructors, copy constructors, casting operators, function call operators, comparison operators, and arithmetic operator overloading.

---

## ✨ Features

* Create complex number objects
* Support arithmetic operator overloading
* Support compound assignment operators
* Support comparison operators
* Implement prefix and postfix increment/decrement
* Implement copy constructor
* Implement multiple casting operators
* Implement function call operator `()`
* Demonstrate constructor overloading
* Display complex numbers in mathematical form

---

## 🖥️ Program Flow

The program performs the following operations:

```text
1. Create two Numbers objects
2. Display both objects
3. Perform:
      • Addition
      • Subtraction
      • Multiplication
      • Division
4. Test:
      • Prefix ++ / --
      • Postfix ++ / --
5. Test:
      • +=
      • -=
      • *=
      • /=
6. Compare objects using:
      • ==
      • !=
      • <
      • >
      • <=
      • >=
7. Demonstrate casting operators
8. Demonstrate bool conversion
9. Demonstrate copy constructor
10. Demonstrate function call operator ()
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
* Constructor Overloading
* Copy Constructor
* Destructor
* Encapsulation
* Operator Overloading
* Arithmetic Operators
* Compound Assignment Operators
* Comparison Operators
* Prefix & Postfix Operators
* Casting Operators
* Function Call Operator
* Returning `*this`
* The `this` Pointer
* Static Casting
* Console Output

---

## 📦 Constructors

| Constructor | Description |
|------------|-------------|
| `Numbers()` | Default constructor |
| `Numbers(float)` | Initializes only the real part |
| `Numbers(float, float)` | Initializes both real and imaginary parts |
| `Numbers(const Numbers&)` | Copy constructor |

---

## 📦 Operator Overloads

### Arithmetic Operators

| Operator | Description |
|----------|-------------|
| `+` | Adds two Numbers objects |
| `-` | Subtracts two Numbers objects |
| `*` | Multiplies two Numbers objects |
| `/` | Divides two Numbers objects |

---

### Compound Assignment

| Operator | Description |
|----------|-------------|
| `+=` | Adds and assigns |
| `-=` | Subtracts and assigns |
| `*=` | Multiplies and assigns |
| `/=` | Divides and assigns |

---

### Increment & Decrement

| Operator | Description |
|----------|-------------|
| `++obj` | Prefix increment |
| `obj++` | Postfix increment |
| `--obj` | Prefix decrement |
| `obj--` | Postfix decrement |

---

### Comparison Operators

| Operator | Description |
|----------|-------------|
| `==` | Equality |
| `!=` | Inequality |
| `<` | Less than |
| `>` | Greater than |
| `<=` | Less than or equal |
| `>=` | Greater than or equal |

---

### Casting Operators

| Operator | Converts To |
|----------|-------------|
| `operator float()` | `float` |
| `operator int()` | `int` |
| `operator bool()` | `bool` |
| `operator double()` | `double` |
| `operator long()` | `long` |
| `operator short()` | `short` |

---

### Function Call Operators

| Operator | Description |
|----------|-------------|
| `operator()()` | Prints the object |
| `operator()(float,float)` | Updates the real and imaginary values |

---

## 🚀 Future Improvements

Some planned improvements include:

* Implement assignment operator (`operator=`)
* Overload stream insertion (`<<`)
* Overload stream extraction (`>>`)
* Implement unary operators (`+`, `-`, `!`)
* Add move constructor
* Add move assignment operator
* Implement mathematical operations for true complex number multiplication and division
* Add exception handling for division by zero
* Make member functions `const` where appropriate

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o OperatorOverloading
```

Run:

```bash
./OperatorOverloading
```

---

## 📷 Example Output

```text
n1 = 9 - 3i
n2 = 4 + 5i

========== + ==========
13 + 2i

========== Prefix ++ ==========
10 - 2i

========== == ==========
Not Equal

========== cast ==========
float  : 9
int    : 9
bool   : 1
double : 9
long   : 9
short  : 9

========== Call Operator ==========
n1 = 9 - 3i
n2 = 4 + 5i
Used function call constructor
10 + 20i
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several intermediate C++ concepts, including:

* Understanding operator overloading
* Designing classes that behave like built-in types
* Implementing arithmetic and comparison operators
* Differentiating between prefix and postfix operators
* Working with copy constructors
* Understanding casting operators
* Using the function call operator
* Returning references using `*this`
* Applying constructor overloading
* Strengthening Object-Oriented Programming skills

This project serves as a strong foundation for learning friend functions, stream operator overloading (`<<` and `>>`), templates, inheritance, polymorphism, and advanced Modern C++ concepts.

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #8 |
| **Project** | C++ Operator Overloading |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Eighth project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, Robotics, Qt/QML, Linux, and Modern C++