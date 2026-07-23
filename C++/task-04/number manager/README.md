# 💡 Console Number Manager (C++)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A simple console-based **Number Manager** written in **C++** that demonstrates the fundamentals of pointers and functions. The program allows the user to modify a number through a pointer using a menu-driven interface.

This project was built as a practice exercise to strengthen core C++ concepts, including pointers, passing arguments by address, functions, loops, and menu-driven programming before moving on to dynamic memory allocation and object-oriented programming (OOP).

---


## ✨ Features

- Enter an integer value
- Increment the number
- Decrement the number
- Reset the number to zero
- Display the current number
- Display the memory address of the number
- Menu-driven interface
- Input validation for menu selection

---

## 🖥️ Program Flow

The program performs the following steps:

```text
1. Ask the user to enter a whole number.
2. Store the address of the number in a pointer.
3. Display the operation menu.
4. Perform the selected operation.
5. Repeat until the user chooses Exit.
```

### Menu

```text
=============== Number Manager ===============

1. Increment
2. Decrement
3. Reset to 0
4. Show Number
5. Exit
```

---

## 🛠️ Technologies Used

- C++
- Standard Library
  - `<iostream>`

---

## 📚 Concepts Practiced

This project demonstrates the use of:

- Functions
- Function parameters
- Passing pointers to functions
- Pointer dereferencing (`*`)
- Address operator (`&`)
- Variables and data types
- Loops (`while`)
- Conditional statements (`switch`)
- Menu-driven programming
- User input validation

---

## 🧠 Pointer Operations

The program stores the user's number in a variable and creates a pointer that points to it.

The available operations are:

```text
Increment : (*num)++

Decrement : (*num)--

Reset     : *num = 0
```

The **Show Number** option displays:

- Current value
- Memory address of the number
- Memory address of the pointer variable inside the function

---

## 🚀 Future Improvements

Some planned improvements include:

- Validate non-numeric input using `std::cin.fail()`
- Support multiple numbers
- Dynamically allocate memory using `new` and `delete`
- Store numbers in arrays
- Navigate arrays using pointer arithmetic
- Add operation history
- Undo the last operation
- Save and load values from files
- Convert the project into an object-oriented (OOP) application

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o NumberManager
```

Run:

```bash
./NumberManager
```

---

## 📷 Example

```text
Choose a whole number: 10

=============== Number Manager ===============

1. Increment
2. Decrement
3. Reset to 0
4. Show Number
5. Exit

Please choose an operation (1-5): 1

The number became: 11

=============== Number Manager ===============

Please choose an operation (1-5): 4

Current number is: 11
The address of current number is: 0x61FF08
The address of the copy of the pointer is: 0x61FEF8
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several fundamental C++ programming concepts, including:

- Creating reusable functions
- Passing variables by address
- Understanding pointers and dereferencing
- Working with memory addresses
- Building menu-driven console applications
- Using `switch` statements effectively
- Organizing program logic into separate functions

This project serves as a foundation for future topics such as dynamic memory allocation, pointer arithmetic, arrays, linked data structures, and object-oriented programming (OOP).

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #4 |
| **Project** | Console Number Manager |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Fourth(1) project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, Robotics, and Software Development