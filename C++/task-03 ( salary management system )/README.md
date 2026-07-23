# 💰 Console Payroll Calculator (C++)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A simple console-based payroll calculator written in **C++** that demonstrates the fundamentals of programming, including functions, user input validation, conditional statements, and salary calculations.

This project was built as a practice exercise to strengthen core C++ programming concepts before moving on to more advanced topics such as file handling, object-oriented programming (OOP), and data management.

---

## ✨ Features

* Enter employee information
* Calculate base salary
* Calculate overtime pay
* Calculate employee bonus
* Calculate tax deduction
* Calculate total salary
* Different bonus rates for Employees and Managers
* Input validation for:

  * Employee name
  * Employee ID
  * Hours worked
  * Overtime hours
  * Employee position

---

## 🖥️ Program Flow

The program asks the user to enter:

```text
1. Employee Name
2. Hours Worked
3. Overtime Hours
4. Employee Position (Employee/Manager)
5. Employee ID
```

After collecting the data, it calculates:

* Base Salary
* Overtime Pay
* Bonus
* Tax
* Total Salary

Finally, it displays a formatted payroll report.

---

## 🛠️ Technologies Used

* C++
* Standard Library

  * `<iostream>`
  * `<string>`
  * `<iomanip>`
  * `<cctype>`

---

## 📚 Concepts Practiced

This project demonstrates the use of:

* Functions
* Function parameters
* Default function arguments
* Variables and data types
* Strings
* Conditional statements (`if`, `else`)
* Loops (`while`)
* User input validation
* Character manipulation (`tolower`)
* Formatted output using `iomanip`

---

## 🧮 Salary Calculation

The program uses the following calculations:

```text
Base Salary   = Hours Worked × $20

Overtime Pay  = Overtime Hours × $30

Bonus         = (Base Salary + Overtime Pay) × Bonus Rate

Tax           = (Base Salary + Overtime Pay) × 15%

Total Salary  = Base Salary + Overtime Pay + Bonus − Tax
```

### Bonus Rates

| Position | Bonus Rate |
|----------|-----------:|
| Employee | 10% |
| Manager  | 15% |

---

## 🚀 Future Improvements

Some planned improvements include:

* Save employee records to files
* Load employee data automatically
* Support multiple employees
* Generate payroll reports
* Allow custom hourly rates
* Add monthly and yearly salary calculations
* Replace functions with classes (OOP)
* Store employees using `std::vector`
* Better error handling
* Export payroll reports as text or CSV files

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o PayrollCalculator
```

Run:

```bash
./PayrollCalculator
```

---

## 📷 Example

```text
========== Payroll Calculator ==========

Enter employee name: Mohamed
Enter the number of hours worked: 40
Enter overtime hours: 8
Employee or Manager? (e/m): m
Enter Employee ID: 1025

=========== Employee Payroll ===========
Employee Name : Mohamed
Employee ID   : 1025
Base Salary   : $800.00
Overtime Pay  : $240.00
Bonus         : $156.00
Tax           : $156.00
----------------------------------------
Total Salary  : $1040.00
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several fundamental C++ programming concepts, including:

* Creating reusable functions
* Passing parameters between functions
* Using default arguments
* Performing user input validation
* Designing simple console applications
* Organizing calculations into separate functions
* Formatting output professionally using `iomanip`

This project serves as a foundation for future payroll management systems using file handling, object-oriented programming (OOP), and databases.

---

## 📚 Course Information

| 📌 Item      | 📝 Details              |
| ------------ | ----------------------- |
| **Track**    | ITI Embedded Systems    |
| **Task**     | #3                      |
| **Project**  | Console Payroll Calculator |
| **Language** | C++                     |
| **Status**   | ✅ Completed             |

---

### 🌟 Third project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, and Robotics