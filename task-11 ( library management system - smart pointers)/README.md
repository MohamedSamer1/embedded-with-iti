# 📚 Library Management System (Smart Pointer Version)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Level](https://img.shields.io/badge/Level-Intermediate-orange)
![Memory](https://img.shields.io/badge/Memory-Smart%20Pointers-success)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

A console-based **Library Management System** developed in **Modern C++** to practice Object-Oriented Programming principles, software design, and modern memory management.

This version demonstrates **Abstraction**, **Inheritance**, **Runtime Polymorphism**, **Interfaces**, **Composition**, **Encapsulation**, **Move Semantics**, and **Smart Pointers (`std::unique_ptr`)**.

---

## 🧬 UML Class Diagram

![Library UML](library-uml.svg)

> The UML diagram is identical to the raw-pointer version because replacing raw pointers with `std::unique_ptr` changes **memory management**, not the object-oriented design.

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
- Automatic memory management using `std::unique_ptr`
- No manual `delete`
- Safe ownership transfer using `std::move`

---

# 🛠️ Technologies Used

- Modern C++
- Standard Library
  - `<iostream>`
  - `<vector>`
  - `<string>`
  - `<memory>`

---

# 📚 Modern C++ Concepts Practiced

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
- RAII (Resource Acquisition Is Initialization)
- Smart Pointers (`std::unique_ptr`)
- Move Semantics
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
| `Library` | Manages books and users using smart pointers |

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
 vector<unique_ptr<Book>>  vector<unique_ptr<User>>

                         User
                           ▲
         ┌─────────────────┼─────────────────┐
         │                 │                 │
     Student          Teacher          Engineer
```

---

# 📖 Design Highlights

## 🔹 Abstraction

The `Borrow` interface defines the common behavior for borrowable objects.

```cpp
virtual void borrowBook() = 0;
virtual void returnBook() = 0;
virtual bool checkAvailability() = 0;
```

---

## 🔹 Inheritance

Multiple user types inherit from the `User` base class.

```text
User
 ├── Student
 ├── Teacher
 └── Engineer
```

Each derived class provides its own implementation of `displayUserInfo()`.

---

## 🔹 Runtime Polymorphism

The library stores different user types through base-class smart pointers.

```cpp
std::vector<std::unique_ptr<User>> users;
```

Calling

```cpp
user->displayUserInfo();
```

automatically invokes the correct derived implementation.

The same runtime polymorphism is used for books through the `Borrow` interface.

---

## 🔹 Composition

The `Library` class owns all books and users.

```cpp
std::vector<std::unique_ptr<Book>> books;
std::vector<std::unique_ptr<User>> users;
```

Ownership belongs exclusively to the `Library`.

---

## 🔹 Encapsulation

Book information is private to the `Book` class.

Borrowing state can only be modified using

```cpp
borrowBook();
returnBook();
```

preventing direct manipulation of the availability flag.

---

## 🔹 Smart Pointers & RAII

Instead of allocating raw pointers with

```cpp
new Book(...)
```

objects are created using

```cpp
std::make_unique<Book>(...)
```

Ownership is transferred into the library using

```cpp
std::move(book);
```

When the `Library` object is destroyed, all books and users are automatically released without calling `delete`.

---

## 🔹 Move Semantics

Objects are inserted into the library using move semantics.

```cpp
books.push_back(std::move(book));
users.push_back(std::move(user));
```

This transfers ownership efficiently while preventing accidental copying.

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

# 🚀 Why Smart Pointers?

Compared to the raw-pointer implementation, this version provides:

- Automatic memory cleanup
- No manual `delete`
- Exception-safe resource management
- Clear ownership semantics
- Reduced risk of memory leaks
- Modern C++ best practices

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
- Add exception handling
- Implement copy and move constructors
- Create a menu-driven interface
- Build a GUI version using Qt
- Support shared ownership using `std::shared_ptr` where appropriate

---

# ▶️ Build and Run

Compile:

```bash
g++ main.cpp -std=c++17 -o library
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

- Designing classes in Modern C++
- Object-Oriented Programming
- Abstract classes and interfaces
- Runtime polymorphism
- Function overriding
- Inheritance hierarchies
- Composition relationships
- Smart pointers
- RAII
- Move semantics
- STL vectors
- Memory-safe software design

This version also provides a strong foundation for learning **Modern C++**, **Design Patterns**, **Qt**, **C++20**, and larger software architectures.

---

# 📚 Course Information

| 📌 Item | 📝 Details |
|---------|------------|
| **Track** | ITI Embedded Systems |
| **Task** | #11 |
| **Project** | Library Management System (Smart Pointer Version) |
| **Language** | Modern C++ |
| **Memory Management** | `std::unique_ptr` |
| **Status** | ✅ Completed |

---

### 🌟 Eleventh project in my ITI Embedded Systems learning journey!

---

# 👨‍💻 Author

**Mohamed Samer**

Engineering Student | Learning Modern C++, Embedded Systems, Robotics, Qt/QML, Linux, and Software Design