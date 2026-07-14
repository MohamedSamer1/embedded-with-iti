# 🎓 Console Student Grade Management System (C++)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A simple console-based **Student Grade Management System** written in **C++** that demonstrates the fundamentals of pointers, functions, user input validation, and menu-driven programming.

This project was built as a practice exercise to strengthen core C++ concepts, including passing arguments by address, pointer dereferencing, reusable functions, loops, conditional statements, and program organization before moving on to dynamic memory allocation and object-oriented programming (OOP).

---

## ✨ Features

- Enter student name
- Enter marks for Math, Physics, and English
- Validate marks (0–100)
- Automatically calculate the average
- Automatically assign a letter grade (A–F)
- Print a formatted student report
- Advanced menu for updating marks
- Recalculate the average at any time
- Reprint the student report
- Menu-driven interface
- Input validation for menu selection

---

## 🖥️ Program Flow

The program performs the following steps:

```text
1. Ask the user to enter the student's name.
2. Enter marks for three subjects.
3. Validate all marks.
4. Calculate the average.
5. Assign a letter grade.
6. Display the student report.
7. Ask whether to enter Advanced Mode.
8. Allow updating marks, recalculating the average, or printing the report until Exit is selected.
```

### Main Menu (Advanced Mode)

```text
=================== Student Report ===================

1. Update mark
2. Recalculate the average
3. Print the report again
4. Exit
```

---

## 🛠️ Technologies Used

- C++
- Standard Library
  - `<iostream>`
  - `<string>`

---

## 📚 Concepts Practiced

This project demonstrates the use of:

- Functions
- Function parameters
- Passing pointers to functions
- Pointer dereferencing (`*`)
- Address operator (`&`)
- Variables and data types
- User input validation
- Loops (`while`, `do-while`)
- Conditional statements (`if-else`)
- `switch` statements
- Menu-driven programming
- Code modularization

---

## 🧠 Grade Calculation


Grades are assigned according to the following scale:

```text
90 - 100 : A
80 - 89  : B
70 - 79  : C
60 - 69  : D
Below 60 : F
```

All marks must be between **0** and **100**. Invalid input prompts the user to re-enter the marks.

---

## 📄 Student Report

The generated report displays:

- Student name
- Math mark
- Physics mark
- English mark
- Average percentage
- Final letter grade

Example:

```text
=================== Student Report ===================

Name         : Mohamed

Math Mark    : 95
Physics Mark : 88
English Mark : 91

Average      : 91%
Grade        : A

======================================================
```

---

## 🚀 Future Improvements

Some planned improvements include:

- Validate non-numeric input using `std::cin.fail()`
- Support multiple students
- Store student records using arrays or vectors
- Search students by name
- Edit individual subject marks instead of all marks
- Save and load student records from files
- Display class statistics
- Calculate highest, lowest, and median grades
- Convert the project into an object-oriented (OOP) application

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o StudentGradeManager
```

Run:

```bash
./StudentGradeManager
```

---

## 📷 Example

```text
Enter Name: Mohamed

Please enter the mark for Math: 90
Please enter the mark for Physics: 80
Please enter the mark for English: 95

=================== Student Report ===================

Name         : Mohamed

Math Mark    : 90
Physics Mark : 80
English Mark : 95

Average      : 88.3333%
Grade        : B

======================================================

Advanced options (y/n): y

1. Update mark
2. Recalculate the average
3. Print the report again
4. Exit
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several fundamental C++ programming concepts, including:

- Creating reusable functions
- Passing variables by address using pointers
- Working with pointer dereferencing
- Validating user input
- Organizing code into multiple functions
- Calculating averages and assigning grades
- Building menu-driven console applications
- Using loops and `switch` statements effectively

This project serves as another step toward more advanced C++ topics such as dynamic memory allocation, arrays, file handling, data structures, and object-oriented programming (OOP).

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #4 |
| **Project** | Console Student Grade Management System |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Fourth(2) project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, Robotics, and Software Development