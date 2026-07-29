# 🐧 OverTheWire Bandit Linux Challenge

![OS](https://img.shields.io/badge/OS-Linux-E95420?logo=linux&logoColor=white)
![Terminal](https://img.shields.io/badge/Terminal-Bash-black?logo=gnubash)
![Platform](https://img.shields.io/badge/Platform-OverTheWire-blue)
![Levels](https://img.shields.io/badge/Levels-0--7-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A hands-on Linux command-line challenge designed to improve practical skills in Bash, filesystem navigation, file analysis, and basic security concepts.

The OverTheWire Bandit challenge provides real-world Linux exercises where passwords are hidden inside files and must be discovered using terminal commands.

This lab focuses on developing confidence with Linux commands, searching techniques, hidden files, file types, ownership, and permissions.

---

# ✨ Lab Objectives

- Connect to Linux systems using SSH
- Navigate the Linux filesystem
- Practice Bash terminal commands
- Read and analyze files
- Handle special filenames
- Find hidden files
- Identify file types
- Search files using conditions
- Understand Linux ownership and permissions

---

# 🖥️ Tasks Completed

The completed levels:

```text
1. Level 0 → 1 : Reading a file using cat
2. Level 1 → 2 : Reading a file named "-"
3. Level 2 → 3 : Handling filenames with spaces
4. Level 3 → 4 : Finding hidden files
5. Level 4 → 5 : Identifying readable file types
6. Level 5 → 6 : Searching files by size
7. Level 6 → 7 : Searching files by owner and group
```

---

# 🛠️ Commands Practiced

| Command | Description |
|---------|-------------|
| `ssh` | Connect to remote Linux machines |
| `ls` | List directory contents |
| `ls -a` | Show hidden files |
| `cat` | Display file contents |
| `cd` | Change directories |
| `file` | Identify file type |
| `find` | Search for files |
| `pwd` | Display current directory |
| `grep` | Search text patterns |
| `2>/dev/null` | Hide error messages |

---

# 📚 Concepts Learned

- Linux Terminal
- Bash Shell
- SSH Connections
- Filesystem Navigation
- Absolute and Relative Paths
- Hidden Files
- Special Characters in Filenames
- File Identification
- File Searching
- File Ownership
- Linux Groups
- File Permissions

---

# 🔍 Levels Completed

## Level 0 → 1

### Task

Read the password stored in a file.

### Command

```bash
cat readme
```

### Password

```text
6y2kwnwK6grgvwvpvLaa2T1cpFEKOhNR
```

---

## Level 1 → 2

### Task

Read a file named `-`.

### Command

```bash
cat ./-
```

### Password

```text
PK8fYLZg2hnHSz83plBL1iEPKdD3QToB
```

---

## Level 2 → 3

### Task

Read a file containing spaces in its filename.

### Command

```bash
cat ./--spaces\ in\ this\ filename--
```

### Password

```text
7ZZ2LFrykP2zEyvBl4m3clcL7tGYJPME
```

---

## Level 3 → 4

### Task

Find and read a hidden file.

### Commands

```bash
ls -a

cat ...Hiding-From-You
```

### Password

```text
xzTXq1rDJQVVAzdv5cHq1TQytTWufAMq
```

---

## Level 4 → 5

### Task

Find the only ASCII text file.

### Commands

```bash
file ./*
```

Result:

```text
./-file07: ASCII text
```

Read:

```bash
cat ./-file07
```

### Password

```text
6C7h9GD8M6ai5nr7wo1RonrzFjj9yIrG
```

---

## Level 5 → 6

### Task

Find a file with a specific size.

### Command

```bash
find -size 1033c
```

Result:

```text
./maybehere07/.file2
```

Read:

```bash
cat ./maybehere07/.file2
```

### Password

```text
pXa26xhMWaC2SvDotA4r9EgZkulOeSBW
```

---

## Level 6 → 7

### Task

Find a file with:

```text
Owner: bandit7
Group: bandit6
Size: 33 bytes
```

### Command

```bash
find / -size 33c -user bandit7 -group bandit6
```

Found:

```text
/var/lib/dpkg/info/bandit7.password
```

Read:

```bash
cat /var/lib/dpkg/info/bandit7.password
```

### Password

```text
Bmnnvf82KzQlfxgAI2d1zYbr1u9pr3E3
```

---

# 🚀 Skills Gained

After completing this challenge, I can:

- Use SSH to access remote Linux machines
- Navigate Linux filesystems
- Work efficiently with Bash commands
- Analyze unknown files
- Search files using advanced conditions
- Understand Linux permissions and ownership
- Solve command-line security challenges

---

# 📖 Learning Outcome

This challenge improved my understanding of Linux command-line tools and introduced practical cybersecurity concepts.

By solving these levels, I gained experience with file discovery, terminal investigation, and Linux system organization.

These skills are essential for cybersecurity, system administration, DevOps, embedded Linux, and software development.

---

# 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Platform** | OverTheWire Bandit |
| **Track** | Linux & Cybersecurity Fundamentals |
| **Operating System** | Linux |
| **Shell** | Bash |
| **Completed Levels** | 0 → 7 |
| **Status** | ✅ Completed |

---

### 🌟 Building strong Linux and cybersecurity foundations through hands-on terminal challenges!

---

# 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning Linux, Embedded Systems, Robotics, Modern C++, Cybersecurity, and System Programming