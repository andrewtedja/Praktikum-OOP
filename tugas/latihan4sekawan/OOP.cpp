#include <iostream>
using std::string;

// * ABSTRACTION
class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{
private: // * ENCAPSULATION
    string Company;
    int Age;

protected: // ? PROTECTED -> can be accessed in child classes
    string Name;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }

    void IntroduceYourself()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    // ! CONSTRUCTOR FOR EMPLOYEE (want to be public)
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion()
    {
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << ", sorry NO promotion for you!" << std::endl;
    };
    virtual void Work()
    {
        std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
    }
};

// * INHERITANCE
class Developer : public Employee
{
public:
    string FavProgrammingLanguage;
    // ! CONSTRUCTOR FOR DEVELOPER
    Developer(string name, string company, int age, string favProgrammingLanguage)
        : Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    };

    void FixBug()
    {
        std::cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
    }
    void Work()
    {
        std::cout << Name << " is writing " << FavProgrammingLanguage << " code" << std::endl;
    }
};

// * ANOTHER INHERITANCE
class Teacher : public Employee
{
public:
    string Subject;
    void PrepareLesson()
    {
        std::cout << Name << " is preparing " << Subject << " lesson " << std::endl;
    }
    // ! CONSTRUCTOR FOR TEACHER
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        Subject = subject;
    };
    void Work()
    {
        std::cout << Name << " is teaching " << Subject << std::endl;
    }
};

int main()
{
    // ? Virtual : check if there is implementation in my derived classes, if yes execute that instead
    Developer d = Developer("John", "Microsoft", 11, "C++");
    Teacher t = Teacher("Jack", "Cool school", 35, "History");

    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();
}
