# Calculator (ITI Embedded Systems Track - Task 1)

## Overview

This project is the **first assignment** in the **ITI Embedded Systems Track**.

It is a simple command-line calculator written in **C++** that performs basic arithmetic operations using a `switch` statement. The program also demonstrates input validation and proper handling of integer-only operations.

## Features

- Supports the following operations:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
  - Modulus (`%`)
- Validates operator input until a correct operator is entered.
- Uses `float` values for `+`, `-`, `*`, and `/`.
- Uses `int` values for the modulus (`%`) operator.
- Prevents division by zero.

## Concepts Practiced

- Variables and data types
- User input and output
- `if` / `else` statements
- `while` loops
- Input validation
- `switch` statements
- Arithmetic operators
- Integer vs. floating-point operations

## Example

```text
Enter an operator (+, -, *, /, %): +

+ operator can work with either integers or floats

Enter first number:
10.5

Enter second number:
2

Result: 12.5
```

### Modulus Example

```text
Enter an operator (+, -, *, /, %): %

Modulus operator works only with integers.

Enter first number:
10

Enter second number:
3

Result: 1
```

## How to Compile

Using **g++**:

```bash
g++ main.cpp -o calculator
```

Run the program:

```bash
./calculator
```

On Windows:

```bash
calculator.exe
```

## Project Structure

```
.
├── main.cpp
└── README.md
```

## Notes

- The modulus (`%`) operator is only valid for integers in C++.
- Division by zero is checked before performing division.
- The program repeatedly asks for a valid operator if the user enters an invalid one.

## Learning Outcome

By completing this task, I practiced:

- Writing clean and organized C++ code
- Using conditional statements effectively
- Applying `switch` statements for menu-driven logic
- Validating user input
- Understanding the difference between integer and floating-point arithmetic

---

**Course:** ITI Embedded Systems Track  
**Task:** 1 - Basic Calculator  
**Language:** C++  
