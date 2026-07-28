# 🏦 Bank Management System

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Standard](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Level](https://img.shields.io/badge/Level-Advanced-orange.svg)
![OOP](https://img.shields.io/badge/OOP-Implemented-green.svg)
![STL](https://img.shields.io/badge/STL-Used-purple.svg)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)

A **console-based Bank Management System** developed using **Modern C++** to demonstrate advanced Object-Oriented Programming principles, clean architecture, file handling, exception handling, and modern C++ practices.

The project simulates a real banking environment where users can create accounts, perform financial operations, and manage their accounts, while administrators can manage users and accounts through a dedicated admin panel.

> ✨ Developed as part of my **C++ learning journey in ITI Embedded Systems Track**, focusing on Modern C++, OOP design, and software engineering practices.

---

# 🚀 Features

## 👤 User Features

- Register a new user
- Login authentication system
- Create Saving accounts
- Create Checking accounts
- Deposit money
- Withdraw money
- Transfer money between accounts
- Display personal accounts
- Persistent data storage
- Automatic ID generation


---

## 🛡️ Admin Features

Administrators have full system management access:

- Create users
- Create Saving accounts for users
- Create Checking accounts for users
- Delete users
- Delete accounts
- Change usernames
- Change passwords
- Modify account balances
- Display all users
- Display all accounts
- Display complete user details

Admin access is controlled using role-based permissions.

---

# 💾 File Handling & Data Persistence

The system automatically saves and loads data using JSON files.

Stored data includes:

- User information
- User passwords
- User roles
- Account information
- Account types
- Account balances

The system loads all saved users and accounts automatically when the program starts.

---

# 📝 Logging System

The project includes a complete logging system.

## Transaction Logs

Every financial operation is recorded.

Examples:

```text
Deposit | SAV0001 | +500

Withdrawal | CHK0002 | -200

Transfer | SAV0001 -> CHK0002 | 300
```

Failed transactions are also recorded.

Examples:

```text
Failed Withdrawal | SAV0001 | Insufficient Balance

Failed Transfer | Invalid Account
```

---

## System Logs

The system tracks important events:

- Program startup
- Program shutdown
- User registration
- User login/logout
- Account creation
- Account deletion
- Password changes
- Username changes

---

# 🧠 Object-Oriented Programming Concepts

## 🔒 Encapsulation

All class data members are kept private and accessed through public methods.

Example:

```cpp
class Account
{
private:
    double accountBalance;

public:
    double getAccountBalance() const;
    void setAccountBalance(double balance);
};
```

This protects object data and controls how values are modified.

---

## 🧬 Inheritance

The project uses inheritance to create different account types.

```
              Account
                 |
      -------------------------
      |                       |
 SavingAccount        CheckingAccount
```

Both account types inherit common functionality from the abstract `Account` class.

---

## 🎭 Polymorphism

The system uses runtime polymorphism through virtual functions.

Example:

```cpp
virtual std::string getAccountType() const = 0;
```

Different account types provide their own implementation.

Accounts are stored using:

```cpp
std::vector<std::unique_ptr<Account>>
```

allowing different derived objects to be handled through the base class.

---

## 🧩 Abstraction

`Account` is an abstract base class that defines common account behavior.

It provides a common interface while forcing derived classes to implement specific functionality.

---

# ⚙️ Modern C++ Features Used

## Smart Pointers

The project uses smart pointers for automatic memory management.

Example:

```cpp
std::unique_ptr<User>

std::unique_ptr<Account>
```

Benefits:

- Automatic memory management
- Prevents memory leaks
- Clear ownership model

---

## STL Containers

Used STL containers:

```cpp
std::vector

std::string
```

Examples:

```cpp
std::vector<std::unique_ptr<User>> users;

std::vector<std::unique_ptr<Account>> accounts;
```

---

## Exception Handling

The system validates operations and handles errors safely.

Example:

```cpp
try
{
    bank.transfer(sender, receiver, amount);
}
catch(const std::exception& e)
{
    std::cout << e.what();
}
```

Handled exceptions include:

- Invalid user input
- Invalid account IDs
- Negative balances
- Invalid transfers
- Insufficient balance
- Wrong login information

---

# 🏗️ Project Architecture

```
Bank-System
│
├── header files
│   │
│   ├── Account.h
│   ├── SaveAcc.h
│   ├── CheckAcc.h
│   ├── User.h
│   ├── Bank.h
│   ├── SaveManger.h
│   └── Validation.h
│
├── source files
│   │
│   ├── Account.cc
│   ├── SaveAcc.cc
│   ├── CheckAcc.cc
│   ├── User.cc
│   ├── Bank.cc
│   ├── SaveManger.cc
│   └── Validation.cc
│
├── data
│   │
│   ├── users.json
│   ├── transactions.txt
│   └── logs.txt
│
└── main.cc
```

---

# 🏛️ Class Responsibilities

## Bank Class

Responsible for:

- Managing users
- Creating accounts
- Deleting users/accounts
- Handling transfers
- Searching users and accounts
- Generating unique IDs


---

## User Class

Responsible for:

- User information
- Authentication data
- Admin permissions
- Managing owned accounts


---

## Account Class (Abstract)

Responsible for:

- Account balance
- Deposit operations
- Withdrawal operations
- Common account behavior

Derived classes:

- SavingAccount
- CheckingAccount


---

## SaveManger Class

Responsible for:

- Saving users
- Loading users
- Saving transactions
- Creating system logs


---

## Validation Class

Responsible for:

- Validating user input
- Handling incorrect input formats
- Preventing invalid values

---

# 📊 UML Design

```
                 Bank
                  |
                  | owns
                  |
                  *
                 User
                  |
                  | owns
                  |
                  *
          Account (Abstract)
                  |
        --------------------
        |                  |
 SavingAccount      CheckingAccount
```

---

# ▶️ Build Instructions

Compile the project using:

```bash
g++ -std=c++17 -Wall -Wextra -O2 -I"header files" "source files"/*.cc main.cc -o bank_system
```

Run:

```bash
./bank_system
```

---

# 📌 Future Improvements

Possible improvements:

- Database integration
- Password encryption
- GUI version using Qt
- More account types
- Loan management system
- Unit testing
- Advanced authentication system

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | Final Project |
| **Project** | Bank Management System |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Final project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, Robotics, Qt/QML, Linux, and Modern C++
---

