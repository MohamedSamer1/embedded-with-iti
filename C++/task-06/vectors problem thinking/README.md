# 🔢 C++ STL Vector Practice

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Beginner-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A simple console-based C++ project that practices common **STL vector operations** and algorithms. This project demonstrates how to manipulate vectors manually without relying heavily on the Standard Library algorithms, making it a great exercise for understanding how these operations work internally.

The project was built to strengthen knowledge of **vectors, maps, loops, iterators, sorting, and algorithmic thinking** before moving on to more advanced C++ topics.

---

## ✨ Features

* Reverse a vector manually using two pointers
* Reverse a vector using a custom method (`pop_back()` + `insert()`)
* Count occurrences of each element using `std::map`
* Display occurrence frequencies
* Sort a vector in ascending order
* Find the second largest element
* Remove duplicate values from a sorted vector
* Display results after every operation

---

## 🖥️ Program Flow

The program performs the following operations:

```text
1. Create a vector with sample values
2. Reverse the vector manually
3. Reverse it again using another custom approach
4. Count occurrences of every number
5. Print frequency table
6. Sort the vector
7. Find the second greatest element
8. Remove duplicate values
9. Print the final vector
```

---

## 🛠️ Technologies Used

* C++
* Standard Library

  * `<iostream>`
  * `<vector>`
  * `<map>`
  * `<algorithm>`

---

## 📚 Concepts Practiced

This project demonstrates the use of:

* Vectors (`std::vector`)
* Maps (`std::map`)
* Range-based for loops
* Index-based loops
* Two-pointer technique
* `std::swap()`
* `push_back()`
* `pop_back()`
* `insert()`
* `erase()`
* `sort()`
* Frequency counting
* Removing duplicates manually
* Iterating through maps
* Algorithm design and problem solving

---

## 🔍 Algorithms Implemented

### Reverse Vector (Two Pointers)

```text
left = first element
right = last element

Swap left and right
Move left forward
Move right backward

Repeat until they meet
```

---

### Reverse Vector (Custom Method)

```text
Take the last element
Remove it
Insert it at the beginning

Repeat until every element has been moved
```

---

### Count Occurrences

```text
For every element:

frequency[element]++
```

Example:

```text
1 -> 6
2 -> 3
3 -> 4
...
```

---

### Find Second Largest

```text
Sort the vector

Second largest =
vector[size - 2]
```

---

### Remove Duplicates

```text
Sort the vector

Compare each element with the next one.

If equal:
    erase current element

Continue until the end.
```

---

## ▶️ How to Run

Compile using **g++**:

```bash
g++ main.cpp -o STLPractice
```

Run:

```bash
./STLPractice
```

---

## 📷 Example Output

```text
Vector after first reverse:
122 99 11 1 2 3 ...

Key : Value

1 : 6
2 : 3
3 : 4
4 : 3
...

Sorted:
1 1 1 1 1 1 2 2 2 3 ...

Second greatest element:
122

Vector after removing duplicates:
1 2 3 4 5 6 7 8 11 99 122 1000
```

---

## 📖 Learning Outcome

Developing this project helped reinforce several important C++ concepts, including:

* Working efficiently with `std::vector`
* Understanding vector memory operations
* Using `std::map` for frequency counting
* Implementing common interview-style algorithms
* Practicing sorting and duplicate removal
* Applying the two-pointer technique
* Improving algorithmic thinking without relying entirely on STL algorithms

This project serves as a foundation for more advanced topics such as custom data structures, searching algorithms, and STL containers.

---

## 🚀 Future Improvements

Some planned improvements include:

* Implement binary search
* Add linear and binary search comparisons
* Rotate vectors left and right
* Shuffle vector elements
* Find maximum and minimum without STL
* Find the kth largest element
* Add user input instead of fixed values
* Compare execution time of different algorithms
* Implement the same algorithms using iterators
* Create reusable utility functions

---

## 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #6 |
| **Project** | C++ STL Vector Algorithms |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Sixth(1) project in my ITI Embedded Systems learning journey!
---

## 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, and Robotics