# 📦 C++ Vector Operations

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A beginner-friendly C++ program that demonstrates the fundamentals of the **Standard Template Library (STL) `std::vector`**. It covers different ways to initialize vectors, common vector operations, element access, and useful member functions.

This project was built as a practice exercise to understand dynamic arrays in C++ before moving on to more advanced STL containers and algorithms.

---

## ✨ Features

* Demonstrates multiple ways to initialize vectors
* Create empty vectors
* Create vectors with a fixed size
* Initialize vectors with a default value
* Initialize vectors using initializer lists
* Copy data from C-style arrays into vectors
* Add elements using `push_back()`
* Remove elements using `pop_back()`
* Insert elements at specific positions
* Erase single elements
* Erase a range of elements
* Remove all elements using `clear()`
* Access first and last elements
* Access elements using `[]` and `at()`
* Check vector size
* Check whether a vector is empty

---

## 🖥️ Program Flow

The program demonstrates the following operations in order:

```text
1. Create vectors using different initialization methods
2. Display vector contents
3. Add elements with push_back()
4. Remove elements with pop_back()
5. Insert an element at a specific index
6. Remove an element using erase()
7. Remove all elements using erase(begin, end)
8. Clear the vector
9. Display:
      • Size
      • Empty status
      • First element
      • Last element
      • Access using [] and at()
```

---

## 🛠️ Technologies Used

* C++
* Standard Library

  * `<iostream>`
  * `<vector>`
  * `<array>`
  * `<string>`

---

## 📚 Concepts Practiced

This project demonstrates the use of:

* STL `std::vector`
* Dynamic arrays
* Vector initialization
* Initializer lists
* Range-based `for` loops
* Copying arrays into vectors
* Iterators (`begin()`, `end()`)
* Vector member functions
* Element insertion and removal
* Accessing vector elements
* `std::boolalpha`
* Basic console output formatting

---

## 📦 Vector Functions Used

| Function | Description |
|----------|-------------|
| `push_back()` | Adds an element to the end of the vector |
| `pop_back()` | Removes the last element |
| `insert()` | Inserts an element at a specified position |
| `erase()` | Removes one element or a range of elements |
| `clear()` | Removes all elements |
| `size()` | Returns the number of elements |
| `empty()` | Checks whether the vector is empty |
| `front()` | Returns the first element |
| `back()` | Returns the last element |
| `at()` | Accesses an element with bounds checking |
| `operator[]` | Accesses an element without bounds checking |
| `begin()` | Returns an iterator to the first element |
| `end()` | Returns an iterator to one past the last element |

---

## 🚀 Future Improvements

Some planned improvements include:

* Demonstrate `resize()`
* Demonstrate `reserve()` and `capacity()`
* Show the difference between `size()` and `capacity()`
* Demonstrate `emplace_back()`
* Sort vectors using `std::sort()`
* Search using `std::find()`
* Remove duplicates
* Reverse vectors
* Store custom objects inside vectors
* Compare vectors with `std::array`

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o VectorOperations
```

Run:

```bash
./VectorOperations
```

---

## 📷 Example Output

```text
vector 1:

===============
vector 2:
0 0 0 0 0

vector 3:
10 10 10 10 10

===============
vector 4:
1 2

vector 5:
1 2

===============
vector 6:
1 2 3

vector 7:
1 2 3

===============

Vector before push back function:

Vector after adding 10 through push back function:
10

Vector after popping function

Vector after adding 10 through 3 push back function:
10 10 10

Vector after inserting 99 at index 2:
10 10 99 10

Vector after removing 99 at index 2:
10 10 10

Vector after removing from beginning to end:

Vector after removing everything using clear:

Size: 3
Is empty? false

First element: 1
Last element : 3

2
2
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several fundamental C++ concepts, including:

* Understanding dynamic arrays using `std::vector`
* Working with STL containers
* Using iterators
* Initializing vectors in different ways
* Inserting and removing elements efficiently
* Accessing vector data safely
* Understanding common vector member functions
* Writing cleaner code using range-based loops

This project serves as a foundation for learning more advanced STL containers such as `std::list`, `std::deque`, `std::map`, `std::set`, and STL algorithms.

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|----------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #5 |
| **Project** | C++ Vector Operations |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Fifth project in my ITI Embedded Systems learning journey!

---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, Robotics, and Modern C++