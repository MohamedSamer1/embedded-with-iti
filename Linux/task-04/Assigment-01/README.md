# 🧮 Assignment 1 – Arithmetic Operations Using Bash

![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux&logoColor=black)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnubash&logoColor=white)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## 📖 Overview

This assignment demonstrates the use of Bash scripting to perform basic arithmetic operations. The script accepts two numbers as input from the user and calculates their sum, difference, product, quotient, and remainder using the `expr` command.

---

## 🎯 Objectives

- Create a Bash script.
- Read numeric input from the terminal.
- Perform arithmetic operations using `expr`.
- Store results in shell variables.
- Display the calculated results in a formatted output.

---

## 🛠️ Implementation

### Arithmetic Operations Script

```bash
#!/bin/bash

read -p "Enter first number: " num1
read -p "Enter second number: " num2

sum=$(expr $num1 + $num2)
diff=$(expr $num1 - $num2)
prod=$(expr $num1 \* $num2)
div=$(expr $num1 / $num2)
mod=$(expr $num1 % $num2)

echo "Sum = $sum"
echo "Difference = $diff"
echo "Multiplication = $prod"
echo "Division = $div"
echo "Modulus = $mod"
```

---

## ▶️ Running the Script

Make the script executable:

```bash
chmod +x file.sh
```

Run the script:

```bash
./file.sh
```

---

## 📂 Project Structure

```text
Assignment-01/
├── file.sh
└── README.md
```

---

## 📚 Bash Concepts Used

- `#!/bin/bash` – Specifies the Bash interpreter.
- `read` – Reads user input from the terminal.
- Variables – Stores numbers and calculation results.
- `expr` – Performs arithmetic operations.
- `echo` – Displays the output.
- `chmod +x` – Grants execute permission to the script.

---

## ✅ Result

Successfully created a Bash script that:

- ✔️ Accepts two numbers from the user.
- ✔️ Calculates addition, subtraction, multiplication, division, and modulus.
- ✔️ Stores each result in variables.
- ✔️ Displays all arithmetic results in a clear format.
- ✔️ Runs directly from the Linux terminal.

---

## 📚 Technologies Used

- Linux
- Bash Shell
- Shell Variables
- `expr` Command
- User Input (`read`)
- Terminal Commands
