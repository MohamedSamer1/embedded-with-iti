#include <iostream>

class student
{
private:
    std::string name;
    std::string age;
    std::string studentID;
    std::string gradesAvg;
    std::string grade;

public:
    // getters
    std::string getName()
    {
        std::cout << "name       : " << name << "\n";
    }
    std::string getAge()
    {
        std::cout << "age        : " << age << "\n";
    }
    std::string getID()
    {
        std::cout << "student ID : " << studentID << "\n";
    }
    std::string getAvg()
    {
        std::cout << "average    : " << gradesAvg << "\n";
    }
    std::string getGrade()
    {
        return grade;
    }
    void printInfo()
    {
        std::cout << "====== Student Info ======" << "\n";
        std::cout << "name       : " << name << "\n";
        std::cout << "age        : " << age << "\n";
        std::cout << "student ID : " << studentID << "\n";
        std::cout << "average    : " << gradesAvg << "\n";
        std::cout << "grade      : " << grade << "\n";
        std::cout << "==========================" << "\n";
    }

    // setters
    void setName(std::string studentName)
    {
        this->name = studentName;
    }
    void setAge(std::string studentAge)
    {
        this->age = studentAge;
    }
    void setstudentId(std::string studentId)
    {
        this->studentID = studentId;
    }
    void setAverage(std::string studentAvg)
    {
        this->gradesAvg = studentAvg;
    }
    void setGrade(std::string studentGrade)
    {
        this->grade = studentGrade;
    }
};

int main()
{
    student student1;

    std::cout << "Lets set student data\n";
    student1.setName("Mohamed");
    student1.setAge("20");
    student1.setstudentId("253335");
    student1.setAverage("97%");
    student1.setGrade("A+");

    student1.printInfo();
}