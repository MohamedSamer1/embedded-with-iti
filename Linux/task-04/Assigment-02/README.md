# 🛠️ Assignment 2 – Linux System Toolkit Using Bash

![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux&logoColor=black)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnubash&logoColor=white)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## 📖 Overview

This assignment demonstrates the use of Bash scripting to create a simple Linux System Toolkit. The script provides a menu-driven interface that allows users to perform different system-related tasks such as checking the current date, system uptime, logged-in users, disk usage, memory usage, and listing files in the current directory.

---

## 🎯 Objectives

- Create a menu-driven Bash script.
- Use functions to organize script operations.
- Execute Linux system commands from Bash.
- Display useful system information.
- Use conditional statements and loops for user interaction.

---

## 🛠️ Implementation

### Linux Toolkit Script

```bash
#!/bin/bash

showDate() {
    currentDate=$(date)
    echo "Current Date: $currentDate"
}

showUptime() {
    uptimeInfo=$(uptime)
    echo "Uptime: $uptimeInfo"
}

showUsers() {
    usersLogged=$(w)
    echo "Logged Users:"
    echo "$usersLogged"
}

showDirectory() {
    currentDir=$(pwd)
    echo "Current Directory: $currentDir"
}

showDiskUsage() {
    diskUsage=$(df -h)
    echo "$diskUsage"
}

showMemoryUsage() {
    memoryUsage=$(free -h)
    echo "$memoryUsage"
}

listFiles() {
    files=$(ls)
    echo "$files"
}

while true
do
    echo "Linux Toolkit"
    echo "====================="
    echo "1) Show Date"
    echo "2) Show Uptime"
    echo "3) Show Logged Users"
    echo "4) Show Current Directory"
    echo "5) Show Disk Usage"
    echo "6) Show Memory Usage"
    echo "7) List Files"
    echo "8) Exit"

    read -p "Enter your choice: " choice

    if [ "$choice" -eq 1 ]; then
        showDate
    elif [ "$choice" -eq 2 ]; then
        showUptime
    elif [ "$choice" -eq 3 ]; then
        showUsers
    elif [ "$choice" -eq 4 ]; then
        showDirectory
    elif [ "$choice" -eq 5 ]; then
        showDiskUsage
    elif [ "$choice" -eq 6 ]; then
        showMemoryUsage
    elif [ "$choice" -eq 7 ]; then
        listFiles
    elif [ "$choice" -eq 8 ]; then
        echo "Exiting..."
        break
    else
        echo "Invalid choice."
    fi

    echo
done
```

---

## ▶️ Running the Script

Make the script executable:

```bash
chmod +x system.sh
```

Run the script:

```bash
./system.sh
```

---

## 📂 Project Structure

```text
Assignment-02/
├── system.sh
└── README.md
```

---

## 📚 Bash Concepts Used

- `#!/bin/bash` – Specifies the Bash interpreter.
- Functions – Organizes different system operations.
- `while` loop – Creates a continuous menu-driven program.
- `if-elif-else` – Handles user choices.
- `read` – Accepts user input.
- Command substitution `$( )` – Stores command output in variables.
- Linux commands:
  - `date` – Displays current date and time.
  - `uptime` – Shows system uptime information.
  - `w` – Displays logged-in users.
  - `pwd` – Shows current directory.
  - `df -h` – Displays disk usage.
  - `free -h` – Displays memory usage.
  - `ls` – Lists files and directories.

---

## ✅ Result

Successfully created a Bash-based Linux System Toolkit that:

- ✔️ Provides a user-friendly menu interface.
- ✔️ Displays important system information.
- ✔️ Uses functions to organize tasks.
- ✔️ Executes Linux commands through Bash.
- ✔️ Allows repeated operations until the user chooses to exit.

---

## 📚 Technologies Used

- Linux
- Bash Shell
- Shell Functions
- Conditional Statements
- Loops
- Linux System Commands
- Terminal Commands
