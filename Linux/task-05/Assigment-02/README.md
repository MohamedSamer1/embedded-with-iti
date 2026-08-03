# 📂 Assignment 2 – File Organizer Using Bash

![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux&logoColor=black)
![Shell](https://img.shields.io/badge/Shell-Bash-4EAA25?logo=gnubash&logoColor=white)
![Level](https://img.shields.io/badge/Level-Intermediate-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## 📖 Overview

This assignment demonstrates how to automate file organization using a Bash script. The script creates sample files with different extensions, identifies each file type using a `case` statement, and moves the files into separate folders based on their extensions.

---

## 🎯 Objectives

- Create a Bash script.
- Create a source directory containing sample files.
- Create destination directories for different file categories.
- Display all files before processing.
- Iterate through all files using a `for` loop.
- Identify file types using a `case` statement.
- Move files into their corresponding folders.
- Display a confirmation message after each file is moved.

---

## 🛠️ Implementation

### File Organizer Script

```bash
#!/bin/bash

# Create source directory
mkdir -p source_directory

# Create sample files
touch source_directory/image1.png
touch source_directory/image2.jpg
touch source_directory/image3.gif

touch source_directory/file1.txt
touch source_directory/file2.pdf
touch source_directory/file3.doc
touch source_directory/file4.docx
touch source_directory/file5.ppt
touch source_directory/file6.pptx
touch source_directory/file7.xls
touch source_directory/file8.xlsx

touch source_directory/data.xml
touch source_directory/archive.zip
touch source_directory/backup.tar

# Create destination directories
mkdir -p organizedDirectory/images
mkdir -p organizedDirectory/documents
mkdir -p organizedDirectory/others

echo "Files before processing:"
ls source_directory

echo

ffor file in source_directory/*; do
    case "${file##*.}" in
        png|jpg|jpeg|gif)
            mv "$file" organizedDirectory/images/
            ;;
        txt|pdf|doc|docx|ppt|pptx|xls|xlsx)
            mv "$file" organizedDirectory/documents/
            ;;
        *)
            mv "$file" organizedDirectory/others/
            ;;
    esac

    echo "$(basename "$file") moved successfully."
done
```

---

## ▶️ Running the Script

Give the script execute permission:

```bash
chmod +x organize_files.sh
```

Run the script:

```bash
./orgainize.sh
```

---

## 📂 Project Structure

```text
Assignment-02/
├── orgainize.sh
├── source_directory/
├── organizedDirectory/
│   ├── images/
│   ├── documents/
│   └── others/
└── README.md
```

---

## 📚 Bash Concepts Used

- `#!/bin/bash` – Specifies the Bash interpreter.
- `mkdir -p` – Creates directories if they do not already exist.
- `touch` – Creates sample files.
- `ls` – Lists files before processing.
- `for` Loop – Iterates through every file in the source directory.
- `case` Statement – Identifies file types based on file extensions.
- `${file##*.}` – Extracts the file extension.
- `mv` – Moves files to their appropriate directories.
- `basename` – Extracts the file name from its path.
- `echo` – Displays status and success messages.
- `chmod +x` – Grants execute permission to the script.

---

## ✅ Result

Successfully created a Bash script that:

- ✔️ Creates a source directory with sample files.
- ✔️ Creates destination folders for images, documents, and other files.
- ✔️ Displays all files before processing.
- ✔️ Identifies file types using a `case` statement.
- ✔️ Moves files into the appropriate folders.
- ✔️ Displays a success message for each moved file.
- ✔️ Automates file organization in Linux.

---

## 📚 Technologies Used

- Linux
- Bash Shell
- Shell Variables
- `mkdir`
- `touch`
- `ls`
- `for` Loop
- `case` Statement
- `mv`
- `basename`
- Terminal Commands
