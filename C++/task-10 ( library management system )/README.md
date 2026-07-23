# 📚 Library Management System

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Intermediate-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A console-based **Library Management System** developed in **C++** to practice Object-Oriented Programming principles and software design.

The project demonstrates **Abstraction**, **Inheritance**, **Runtime Polymorphism**, **Interfaces**, **Composition**, **Encapsulation**, and **Dynamic Memory Management** through a simple library system that manages books and users.

---

## 🧬 UML Class Diagram

![Library UML](library-uml.svg)

---

# ✨ Features

- Add books to the library
- Register different user types
  - Student
  - Teacher
  - Engineer
- Display all books
- Display all registered users
- Borrow books using their ID
- Return borrowed books
- Prevent borrowing unavailable books
- Prevent returning books that haven't been borrowed
- Automatic cleanup of dynamically allocated memory

---

# 🛠️ Technologies Used

- C++
- Standard Library
  - `<iostream>`
  - `<vector>`
  - `<string>`

---

# 📚 Object-Oriented Concepts Practiced

This project demonstrates:

- Object-Oriented Programming (OOP)
- Classes and Objects
- Encapsulation
- Abstraction
- Abstract Classes
- Pure Virtual Functions
- Interfaces
- Inheritance
- Runtime Polymorphism
- Function Overriding
- Virtual Functions
- Base-Class Pointers
- Composition
- Dynamic Memory Allocation
- Constructors
- Destructors
- STL Vectors

---

# 📦 Class Overview

| Class | Purpose |
|--------|---------|
| `Borrow` | Abstract interface defining borrowing operations |
| `Book` | Stores book information and borrowing logic |
| `User` | Base class for all library users |
| `Student` | Derived user class |
| `Teacher` | Derived user class |
| `Engineer` | Derived user class |
| `Library` | Manages books and users |

---

# 🧬 Class Relationships

```text
                     Borrow
                       ▲
                       │
                    Book
                      │
                      │
                 Managed by
                      │
                ┌──────────┐
                │ Library  │
                └──────────┘
               /            \
              /              \
     vector<Book*>     vector<User*>

                         User
                           ▲
         ┌─────────────────┼─────────────────┐
         │                 │                 │
     Student          Teacher          Engineer
```

---

# 📖 Design Highlights

## 🔹 Abstraction

The `Borrow` interface defines the operations that every borrowable object must implement.

```cpp
virtual void borrowBook() = 0;
virtual void returnBook() = 0;
virtual bool checkAvailability() = 0;
```

---

## 🔹 Inheritance

Different user types inherit from the `User` base class.

```text
User
 ├── Student
 ├── Teacher
 └── Engineer
```

Each derived class overrides `displayUserInfo()`.

---

## 🔹 Runtime Polymorphism

The library stores different user types using base-class pointers.

```cpp
std::vector<User*> users;
```

Calling

```cpp
user->displayUserInfo();
```

automatically invokes the correct derived implementation.

The same concept is used for books through the `Borrow` interface.

---

## 🔹 Composition

The `Library` class owns collections of books and users.

```cpp
std::vector<Book*> books;
std::vector<User*> users;
```

The `Library` class is responsible for managing their lifetime.

---

## 🔹 Encapsulation

Book data is encapsulated inside the `Book` class.

The availability status can only be modified through

```cpp
borrowBook();
returnBook();
```

instead of being changed directly.

---

## 🔹 Dynamic Memory Management

Books and users are dynamically allocated.

```cpp
new Book(...)
new Student(...)
new Teacher(...)
new Engineer(...)
```

The `Library` destructor automatically releases all allocated memory.

```cpp
delete book;
delete user;
```

---

# 🔄 Borrowing Workflow

```text
User
   │
   ▼
Enter Book ID
   │
   ▼
Library searches books
   │
   ▼
Book found?
 ├── No → Print "Book not found"
 └── Yes
        │
        ▼
borrowBook()
        │
        ▼
Available?
 ├── No → Already borrowed
 └── Yes
        │
        ▼
Mark as borrowed
```

---

# 🚀 Future Improvements

- Search books by title
- Search books by author
- Remove books
- Remove users
- Track which user borrowed each book
- Store borrowing history
- Save data to files
- Load data from files
- Replace raw pointers with `std::unique_ptr`
- Add exception handling
- Implement copy and move constructors
- Create a menu-driven interface
- Build a GUI version using Qt

---

# ▶️ Build and Run

Compile:

```bash
g++ main.cpp -o library
```

Run:

```bash
./library
```

---

# 📖 Sample Output

```text
Added to library
Added to library
Added to library users
Added to library users
Added to library users
Added to library users

List of users:
student username: mohamed
student username: jason
Teacher username: amgad
engineer username: anas

List of books:
book name: book1
book name: book2

you have borrowed: book1

the book: book1 has already been borrowed

you have returned: book1
```

---

# 📖 Learning Outcomes

This project strengthened my understanding of:

- Designing classes in C++
- Object-Oriented Programming
- Abstract classes and interfaces
- Runtime polymorphism
- Function overriding
- Inheritance hierarchies
- Composition relationships
- Dynamic memory management
- STL vectors
- Designing maintainable software

It also serves as a foundation for learning **Modern C++**, **Smart Pointers**, **Design Patterns**, **Qt**, and larger software architectures.

---

# 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #10 |
| **Project** | Library Management System |
| **Language** | C++ |
| **Status** | ✅ Completed |

---

### 🌟 Tenth project in my ITI Embedded Systems learning journey!

---

# 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning C++, Embedded Systems, Robotics, Qt/QML, Linux, and Modern C++