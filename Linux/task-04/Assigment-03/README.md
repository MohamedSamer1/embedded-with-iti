# 🔐 Assignment 3 – Password Strength Checker Using Bash

![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux&logoColor=black)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnubash&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## 📖 Overview

This assignment demonstrates the use of Bash scripting to create a Password Strength Checker. The script securely accepts a password from the user, analyzes its complexity based on different security requirements, and generates a strength report showing whether the password is weak, medium, or strong.

---

## 🎯 Objectives

- Create a Bash script for password validation.
- Accept hidden user input using secure password entry.
- Check password complexity requirements.
- Use regular expressions for character validation.
- Calculate a password strength score.
- Display a detailed password strength report.

---

## 🛠️ Implementation

### Password Strength Checker Script

```bash
#!/bin/bash

read -s -p "Enter password: " password

length=${#password}
hasUpper=0
hasLower=0
hasDigit=0
hasSpecial=0
score=0

if [[ $password =~ [A-Z] ]]; then
    hasUpper=1
    score=$(expr $score + 1)
fi

if [[ $password =~ [a-z] ]]; then
    hasLower=1
    score=$(expr $score + 1)
fi

if [[ $password =~ [0-9] ]]; then
    hasDigit=1
    score=$(expr $score + 1)
fi

if [[ $password =~ [^a-zA-Z0-9] ]]; then
    hasSpecial=1
    score=$(expr $score + 1)
fi

echo
echo "Password Strength Report"
echo

if [ $length -ge 8 ]; then
    echo "Length          : OK"
    score=$(expr $score + 1)
else
    echo "Length          : Missing"
fi

if [ $hasUpper -eq 1 ]; then
    echo "Uppercase       : OK"
else
    echo "Uppercase       : Missing"
fi

if [ $hasLower -eq 1 ]; then
    echo "Lowercase       : OK"
else
    echo "Lowercase       : Missing"
fi

if [ $hasDigit -eq 1 ]; then
    echo "Digit           : OK"
else
    echo "Digit           : Missing"
fi

if [ $hasSpecial -eq 1 ]; then
    echo "Special Char    : OK"
else
    echo "Special Char    : Missing"
fi

echo

if [ $score -eq 5 ]; then
    echo "Overall: Strong"
elif [ $score -ge 3 ]; then
    echo "Overall: Medium"
else
    echo "Overall: Weak"
fi
```

---

## ▶️ Running the Script

Make the script executable:

```bash
chmod +x password.sh
```

Run the script:

```bash
./password.sh
```

---

## 📂 Project Structure

```text
Assignment-03/
├── password.sh
└── README.md
```

---

## 📚 Bash Concepts Used

- `#!/bin/bash` – Specifies the Bash interpreter.
- `read -s` – Reads password input securely without displaying it.
- Variables – Stores password details and validation results.
- `${#variable}` – Calculates the length of the password.
- Regular Expressions (`=~`) – Checks for uppercase, lowercase, digits, and special characters.
- `if-elif-else` – Performs conditional checks.
- Command substitution `$( )` – Stores calculation results.
- `expr` – Performs arithmetic operations.

---

## 🔍 Password Validation Rules

The script checks the following requirements:

- ✔️ Password length must be at least 8 characters.
- ✔️ Contains at least one uppercase letter.
- ✔️ Contains at least one lowercase letter.
- ✔️ Contains at least one digit.
- ✔️ Contains at least one special character.

---

## ✅ Result

Successfully created a Bash Password Strength Checker that:

- ✔️ Accepts passwords securely through hidden input.
- ✔️ Analyzes password complexity.
- ✔️ Provides a detailed validation report.
- ✔️ Calculates a strength score.
- ✔️ Classifies passwords as Weak, Medium, or Strong.

---

## 📚 Technologies Used

- Linux
- Bash Shell
- Shell Variables
- Regular Expressions
- Conditional Statements
- Arithmetic Operations
- User Input Handling
- Terminal Commands