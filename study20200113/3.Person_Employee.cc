#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
class Person
{
public:
    Person(const char *name,int age)
        :_name(new char[strlen(name)+1]())
         ,_age(age)
    {
        strcpy(_name,name);
    cout<<"Person(const char *,int )"<<endl;
    }
    void display() const;
protected:
    char * _name;
      int  _age;
};

class Employee
:public Person
{
public:
    Employee(const char *name,int age,const char *department,double salary)
        :Person(name,age)
         ,_department(new char[strlen(department)+1]())
         ,_salary(salary)
    {
        strcpy(_department,department);
    cout<<"Employee(const char * ,int ,const char * ,double)"<<endl;
    }
    void display();
    double getSalary()
    {
        return _salary;
    }
private:
    char * _department;
    double _salary;
};

void Person::display() const
{
    cout<<"   name   :"<<_name<<endl;
    cout<<"   age    :"<<_age<<endl;
}
void Employee::display()
{
    Person::display();
    cout<<"department:"<<_department<<endl;
    cout<<"  salary  :"<<_salary<<endl; 
}
int main()
{
 Employee A={"zhangsan",27,"design",8888.8}\
            ,B={"lisi",32,"market",9999.9}\
            ,C={"wanger",23,"soft",23456.7};
    A.display();
    cout<<endl;
    B.display();
    cout<<endl;
    C.display();
    cout<<endl;
    double totalSalary=A.getSalary()+B.getSalary()+C.getSalary();
    cout<<"平均薪水为:"<<totalSalary/3<<endl;
}

