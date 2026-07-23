#include <iostream>
#include <vector>
#include <string>

class User
{
protected:
    std::string userName;
    std::string userID;

public:
    User(std::string userName, std::string userID) : userName(userName), userID(userID) {}
    virtual void displayUserInfo()
    {
        std::cout << "username: " << userName << "  ID: " << userID << "\n";
    }
    ~User() = default;
};

class Student : public User
{
public:
    Student(std::string userName, std::string userID) : User(userName, userID) {}
    void displayUserInfo() override
    {
        std::cout << "student username: " << userName << "    ,user ID: " << userID << "\n";
    }
};

class Engineer : public User
{
public:
    Engineer(std::string userName, std::string userID) : User(userName, userID) {}
    void displayUserInfo() override
    {
        std::cout << "engineer username: " << userName << "    ,engineer ID: " << userID << "\n";
    }
};

class Teacher : public User
{
public:
    Teacher(std::string userName, std::string userID) : User(userName, userID) {}
    void displayUserInfo() override
    {
        std::cout << "Teacher username: " << userName << "    ,Teacher ID: " << userID << "\n";
    }
};

class Borrow
{
public:
    virtual void borrowBook() = 0;
    virtual void returnBook() = 0;
    virtual bool checkAvailability() = 0;

    virtual ~Borrow() = default;
};

class Book : public Borrow
{
protected:
    std::string bookTitle;
    std::string bookAuthor;
    std::string bookID;
    bool isAvailable;

public:
    Book(std::string bookTitle, std::string bookAuthor, std::string bookID, bool isAvailable) : bookTitle(bookTitle), bookAuthor(bookAuthor), bookID(bookID), isAvailable(isAvailable) {}

    virtual void displayBookInfo()
    {
        std::cout << "book name: " << bookTitle << "   ,written by: " << bookAuthor << "     ,book ID: " << bookID << "     ,availability: " << (isAvailable ? "Available" : "Not Available") << "\n";
    }

    virtual std::string getID()
    {
        return bookID;
        // std::cout << "book ID: " << bookID << "\n";
    }
    void borrowBook() override
    {
        if (isAvailable)
        {
            std::cout << "you have borrowed: " << bookTitle << "\n";
            isAvailable = false;
        }
        else
        {
            std::cout << "the book: " << bookTitle << " has already been borrowed" << "\n";
        }
    }
    virtual void returnBook() override
    {
        if (isAvailable)
        {
            std::cout << "the book: " << bookTitle << " has not been borrowed" << "\n";
        }
        else
        {
            std::cout << "you have returned: " << bookTitle << "\n";
            isAvailable = true;
        }
    }
    virtual bool checkAvailability()
    {
        return isAvailable;
    }
};

class Library
{
private:
    std::vector<Book *> books;
    std::vector<User *> users;

public:
    void addBook(Book *bookName)
    {
        books.push_back(bookName);
        std::cout << "Added to library\n";
    }
    void addUser(User *userr)
    {
        users.push_back(userr);
        std::cout << "Added to library users\n";
    }
    void displayBooks()
    {
        std::cout << "List of books:\n";
        for (Book *book : books)
        {
            book->displayBookInfo();
        }
    }
    void displayUsers()
    {
        std::cout << "List of users:\n";

        for (User *user : users)
        {
            user->displayUserInfo();
        }
    }
    void borrowBook(std::string id)
    {
        for (Book *book : books)
        {
            if (book->getID() == id)
            {
                book->borrowBook();
                return;
            }
        }

        std::cout << "Book not found.\n";
    }
    void returnBook(std::string id)
    {
        for (Book *book : books)
        {
            if (book->getID() == id)
            {
                book->returnBook();
                return;
            }
        }

        std::cout << "Book not found.\n";
    }
    ~Library()
    {
        for (Book *book : books)
        {
            delete book;
        }
        for (User *user : users)
        {
            delete user;
        }
    }
};

int main()
{
    Library library;

    library.addBook(new Book("book1", "Mohamed", "1111", true));
    library.addBook(new Book("book2", "Samer", "1112", true));
    library.addUser(new Student("mohamed", "253335"));
    library.addUser(new Student("jason", "251086"));
    library.addUser(new Teacher("amgad", "1234"));
    library.addUser(new Engineer("anas", "1259"));

    library.displayUsers();
    std::cout << "\n\n";
    library.displayBooks();
    std::cout << "\n\n";

    library.borrowBook("1111");
    library.displayBooks();
    std::cout << "\n\n";
    library.borrowBook("1111");

    library.returnBook("1111");
    library.displayBooks();
    std::cout << "\n\n";
}