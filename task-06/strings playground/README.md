# 📝 C++ STL String Practice

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A simple console-based C++ project that explores the **`std::string`** class and its most commonly used member functions. This project demonstrates how to create, modify, search, compare, and manage strings using the C++ Standard Library.

The project was built as a practice exercise to strengthen understanding of string manipulation before moving on to file handling, data structures, and object-oriented programming (OOP).

---

## ✨ Features

* Get string length and size
* Check string capacity
* Check if a string is empty
* Insert and erase characters
* Add and remove characters using `push_back()` and `pop_back()`
* Append strings
* Replace part of a string
* Search using `find()` and `rfind()`
* Extract substrings
* Access characters using `at()` and `[]`
* Get first and last characters
* Compare two strings
* Swap two strings
* Resize strings
* Reserve memory capacity
* Shrink unused capacity
* Convert to C-style string using `c_str()`
* Clear a string

---

## 🖥️ Program Flow

The program performs the following operations:

```text
1. Create two strings
2. Display string properties
3. Insert and erase characters
4. Add and remove characters
5. Append and replace text
6. Search inside the string
7. Extract a substring
8. Access characters
9. Compare two strings
10. Swap the strings
11. Resize and reserve memory
12. Convert to C-string
13. Clear the string
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

* `std::string`
* String properties
* Character access
* String modification
* String searching
* String comparison
* Memory management
* C-style string conversion
* Standard Library functions
* Console output formatting

---

## 🔍 String Functions Covered

| Function | Purpose |
|----------|----------|
| `length()` | Returns string length |
| `size()` | Returns string size |
| `capacity()` | Returns allocated capacity |
| `empty()` | Checks whether the string is empty |
| `insert()` | Inserts characters into the string |
| `erase()` | Removes characters |
| `push_back()` | Adds one character to the end |
| `pop_back()` | Removes the last character |
| `append()` | Appends another string |
| `+=` | Concatenates strings |
| `replace()` | Replaces part of a string |
| `find()` | Finds the first occurrence |
| `rfind()` | Finds the last occurrence |
| `substr()` | Returns a substring |
| `front()` | Returns the first character |
| `back()` | Returns the last character |
| `at()` | Safe indexed access |
| `operator[]` | Direct indexed access |
| `compare()` | Compares two strings |
| `swap()` | Exchanges two strings |
| `resize()` | Changes string length |
| `reserve()` | Increases capacity |
| `shrink_to_fit()` | Reduces unused capacity |
| `c_str()` | Returns a C-style string |
| `clear()` | Removes all characters |

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o StringPractice
```

Run:

```bash
./StringPractice
```

---

## 📷 Example Output

```text
string length: 12
string size: 12
string capacity: 15
string empty: 0

string insert(!): hello, world!
string erase(!): hello, world

string after push_back(): hello, worldD
string after pop_back(): hello, world

string append(C++): hello, world C++
string += Programming: hello, world C++ Programming

string replace: Hi, world C++ Programming

string find(C++): 10
string rfind(g): 24

string front: H
string back: g

string compare: ...

string after swap(str1): C++
string after swap(str2): Hi, world C++ Programming
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several fundamental C++ concepts, including:

* Using the `std::string` class effectively
* Modifying strings dynamically
* Searching and extracting text
* Comparing and swapping strings
* Understanding string capacity versus size
* Managing string memory efficiently
* Working with C-style strings using `c_str()`

This project serves as a foundation for future work involving file handling, text processing, parsing, and data manipulation.

---

## 🚀 Future Improvements

Some planned improvements include:

* Convert strings to uppercase and lowercase
* Reverse strings manually
* Count words and characters
* Remove spaces from a string
* Check for palindromes
* Validate user input
* Search and replace words entered by the user
* Practice string algorithms without STL helper functions
* Read strings from files
* Build a simple text editor

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #6  |
| **Project** | C++ STL String Practice |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Sixth(2) project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, and Robotics