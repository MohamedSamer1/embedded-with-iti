# 👥 Assignment 1 – Linux User and Group Management Using Bash

![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux&logoColor=black)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnubash&logoColor=white)
![Level](https://img.shields.io/badge/Level-Intermediate-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## 📖 Overview

This assignment demonstrates how to automate Linux user and group management using a Bash script. The script creates a new user and group, verifies their creation, adds the user to the group, and displays the group members.

---

## 🎯 Objectives

- Create a Bash script.
- Display the current date and a welcome message.
- Create a new Linux user.
- Create a new Linux group.
- Verify the creation of the user and group.
- Add the user to the group.
- Display the members of the group.
- Automate user and group management tasks.

---

## 🛠️ Implementation

### User and Group Management Script

```bash
#!/bin/bash

echo "========================================"
echo "Linux User and Group Management Script"
echo "Date: $(date)"
echo "Welcome!"
echo "========================================"

USER_NAME="student"
GROUP_NAME="ITI"

# Create user
useradd -m "$USER_NAME"

# Create group
groupadd "$GROUP_NAME"

# Verify user
echo
echo "Checking /etc/passwd for user..."
grep "^$USER_NAME:" /etc/passwd

# Verify group
echo
echo "Checking /etc/group for group..."
grep "^$GROUP_NAME:" /etc/group

# Add user to the group
usermod -aG "$GROUP_NAME" "$USER_NAME"

echo
echo "Members of group '$GROUP_NAME':"
getent group "$GROUP_NAME"
```

---

## ▶️ Running the Script

Give the script execute permission:

```bash
chmod +x manger.sh
```

Run the script as the root user or with `sudo`:

```bash
sudo ./manger.sh
```

---

## 📂 Project Structure

```text
Assignment-01/
├── manger.sh
└── README.md
```

---

## 📚 Bash Concepts Used

- `#!/bin/bash` – Specifies the Bash interpreter.
- `echo` – Displays messages to the terminal.
- `date` – Prints the current system date and time.
- Variables – Stores the user and group names.
- `useradd` – Creates a new Linux user.
- `groupadd` – Creates a new Linux group.
- `grep` – Verifies user and group creation.
- `usermod -aG` – Adds a user to a group.
- `getent` – Displays group information and members.
- `chmod +x` – Grants execute permission to the script.
- `sudo` – Executes administrative commands with root privileges.

---

## ✅ Result

Successfully created a Bash script that:

- ✔️ Displays the current date and a welcome message.
- ✔️ Creates a new Linux user.
- ✔️ Creates a new Linux group.
- ✔️ Verifies the user in `/etc/passwd`.
- ✔️ Verifies the group in `/etc/group`.
- ✔️ Adds the user to the specified group.
- ✔️ Displays the members of the group.
- ✔️ Automates Linux user and group management.

---

## 📚 Technologies Used

- Linux
- Bash Shell
- Shell Variables
- `useradd`
- `groupadd`
- `usermod`
- `grep`
- `getent`
- Terminal Commands
