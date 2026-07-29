# 👨‍💼 Assignment 5 – Employee Registration System

![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux&logoColor=black)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnubash&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## 📖 Overview

This assignment demonstrates the basics of Bash scripting by creating a simple Employee Registration System. The script collects employee information from the user using terminal input and displays the entered information in a formatted output.

---

## 🎯 Objectives

- Create a Bash script.
- Read user input from the terminal.
- Store input in shell variables.
- Display formatted employee information.
- Execute the script from the command line.

---

## 🛠️ Implementation

### Employee Registration Script

```bash
#!/bin/bash

echo "====================================="
echo "    Employee Registration System"
echo "====================================="
echo

read -p "Enter Employee Name: " name
read -p "Enter Employee Age: " age
read -p "Enter Department: " department
read -p "Enter Salary: " salary

echo
echo "====================================="
echo "      Employee Information"
echo "====================================="
echo "Name       : $name"
echo "Age        : $age"
echo "Department : $department"
echo "Salary     : $salary"
echo "====================================="
```

---

## ▶️ Running the Script

Make the script executable:

```bash
chmod +x emp.sh
```

Run the script:

```bash
./emp.sh
```

---

## 📂 Project Structure

```text
Assignment5/
├── emp.sh
└── README.md
```

---

## 📚 Bash Concepts Used

- `#!/bin/bash` – Specifies the Bash interpreter.
- `read` – Reads user input from the terminal.
- Variables – Stores employee information.
- `echo` – Displays formatted output.
- `chmod +x` – Grants execute permission to the script.

---

## ✅ Result

Successfully created a Bash script that:

- ✔️ Registers a new employee.
- ✔️ Accepts employee name, age, department, and salary.
- ✔️ Stores the entered data in variables.
- ✔️ Displays the collected information in a clean and readable format.
- ✔️ Runs directly from the Linux terminal.

---

## 📚 Technologies Used

- Linux
- Bash Shell
- Shell Variables
- User Input (`read`)
- Terminal Commands
