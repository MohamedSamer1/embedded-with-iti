# 🛠️ Assignment 4 – Customize Your Linux Terminal

![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux&logoColor=black)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnubash&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## 📖 Overview

This assignment customizes the Bash shell by creating a collection of user-defined functions. These functions provide convenient commands for common file system operations such as listing directory contents, navigating directories, searching files, displaying file contents, deleting files with confirmation, creating directory hierarchies, and creating new files.

All functions were added to the `~/.bashrc` file, making them available automatically in every new terminal session.

---

## 🎯 Objectives

- Create custom Bash commands using shell functions.
- Simplify common terminal operations.
- Learn how to customize the Bash environment.
- Automatically load custom commands in every new terminal session.

---

## 🛠️ Implementation

The following functions were added to the `~/.bashrc` file.

### Display Directory Contents

```bash
print_content() {
    ls -la
}
```

Displays all files and directories in the current directory.

---

### Change Directory

```bash
go_to() {
    cd "$1"
}
```

Changes the current working directory to the specified path.

---

### Search Inside a File

```bash
search() {
    grep --color=always -n "$1" "$2"
}
```

Searches for a keyword inside a file while displaying matching line numbers and highlighting the matching text.

---

### Display File with Line Numbers

```bash
show_file() {
    nl "$1"
}
```

Displays the contents of a file with numbered lines.

---

### Remove a File with Confirmation

```bash
remove() {
    rm -i "$1"
}
```

Prompts for confirmation before deleting a file.

---

### Create Directory Hierarchy

```bash
make_dir() {
    mkdir -p "$1"
}
```

Creates nested directories, including any missing parent directories.

---

### Create an Empty File

```bash
create_file() {
    touch "$1"
}
```

Creates a new empty file.

---

## ▶️ Reload Bash Configuration

After editing the configuration file, reload it using:

```bash
source ~/.bashrc
```

This makes all custom commands available immediately.

---

## 📂 Project Structure

```text
Assignment4/
└── README.md
```

---

## 📚 Custom Commands

| Command                     | Description                                               |
| --------------------------- | --------------------------------------------------------- |
| `print_content`             | Displays the contents of the current directory.           |
| `go_to <directory>`         | Changes the current working directory.                    |
| `search "keyword" filename` | Searches for text inside a file with highlighted matches. |
| `show_file filename`        | Displays a file with line numbers.                        |
| `remove filename`           | Deletes a file after confirmation.                        |
| `make_dir path`             | Creates nested directories.                               |
| `create_file filename`      | Creates an empty file.                                    |

---

## 💡 Why `~/.bashrc`?

The `~/.bashrc` file is executed automatically whenever a new interactive Bash shell starts. By storing the custom functions in this file, the commands become permanently available in every new terminal session without requiring manual setup.

---

## ✅ Result

Successfully customized the Bash environment by creating reusable shell functions that:

- ✔️ Display directory contents.
- ✔️ Navigate between directories.
- ✔️ Search for text inside files.
- ✔️ Display files with line numbers.
- ✔️ Remove files with confirmation.
- ✔️ Create nested directories.
- ✔️ Create new empty files.
- ✔️ Load automatically in every new Bash terminal session.

---

## 📚 Technologies Used

- Linux
- Bash Shell
- Bash Functions
- Bash Startup Configuration (`.bashrc`)
- Linux File System Commands
