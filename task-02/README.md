# 🏦 Console Banking System (C++)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A simple console-based banking system written in **C++** that demonstrates the fundamentals of programming, including arrays, loops, functions of a menu-driven application, user authentication, and basic banking operations.

This project was built as a practice exercise to strengthen core C++ programming concepts before moving on to more advanced topics such as file handling, object-oriented programming (OOP), and databases.

---

## ✨ Features

* Create new bank accounts
* Secure login using:

  * Account ID
  * Username
  * Password
* Deposit money
* Withdraw money
* Check account balance
* Create multiple accounts (up to 10)
* Switch between different accounts without restarting the program
* Input validation for:

  * Invalid account IDs
  * Negative deposit amounts
  * Negative withdrawal amounts
  * Insufficient balance

---

## 🖥️ Menu

After logging in, the user can choose from the following options:

```text
1. Deposit
2. Withdraw
3. Check Balance
4. Create New Account
5. Login from Another Account
6. Exit
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

* Variables and data types
* Arrays
* Strings
* Conditional statements (`if`, `else`)
* Loops (`while`)
* `switch` statements
* User input validation
* Menu-driven programming
* Basic authentication logic

---

## 📂 Data Storage

The application stores all information in memory using arrays.

```cpp
std::string userNames[10];
std::string passwords[10];
float balances[10];
```

Since no file handling or database is used, all account information is lost when the program closes.

---

## 🚀 Future Improvements

Some planned improvements include:

* Save accounts to files
* Load accounts automatically on startup
* Encrypt passwords
* Replace arrays with classes and objects (OOP)
* Add transaction history
* Transfer money between accounts
* Change password
* Delete account
* Admin account
* Better error handling
* Unlimited accounts using dynamic containers (`std::vector`)

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o BankingSystem
```

Run:

```bash
./BankingSystem
```

On Windows:

```bash
BankingSystem.exe
```

---

## 📷 Example

```text
=========================
      BANKING SYSTEM
=========================
1. Create Account

Enter username: Mohamed
Enter password: ********

Your ID is 0

Let's Login...

Enter ID: 0
Enter username: Mohamed
Enter password: ********

Login Successful!

1. Deposit
2. Withdraw
3. Check Balance
4. Create New Account
5. Login from Another Account
6. Exit
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several fundamental C++ programming concepts, including:

* Building menu-driven console applications
* Managing multiple users with arrays
* Designing simple authentication systems
* Performing input validation
* Organizing program logic using loops and switch statements

This project serves as a foundation for future banking system implementations using file handling, object-oriented programming (OOP), and databases.

---

## 📚 Course Information

| 📌 Item      | 📝 Details             |
| ------------ | ---------------------- |
| **Track**    | ITI Embedded Systems   |
| **Task**     | #2                     |
| **Project**  | Console Banking System |
| **Language** | C++                    |
| **Status**   | ✅ Completed            |

---

### 🌟 Second project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, and Robotics
