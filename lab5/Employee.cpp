#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string name;
    int id;
    string dept;

public:

    Employee() :name(""), id(0), dept("")
    {}

    Employee(const string& name, int id, const string& dept) :name(name), id(id), dept(dept)
    {}


    string get_name() const
    {
        return name;
    }

    int get_id() const
    {
        return id;
    }

    string get_dept() const
    {
        return dept;
    }


    void set_dept(const string& dept)
    {
        this->dept = dept;
    }

    void set_name(const string& name)
    {
        this->name = name;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void print() const
    {
        std::cout << get_id() << ", "
            << get_name() << ", "
            << get_dept() << std::endl;
    }

    friend ostream& operator<<(ostream& output, const Employee& e)
    {
        output << e.get_id() << " " << e.get_name() << " " << e.get_dept();
        return output;
    }

    friend bool operator== (const Employee& e1, const Employee& e2)
    {
        return (e1.name == e2.name &&
            e1.id == e2.id &&
            e1.dept == e2.dept);
    }

    friend bool operator!= (const Employee& e1, const Employee& e2)
    {
        return !(e1.name == e2.name &&
            e1.id == e2.id &&
            e1.dept == e2.dept);
    }

};
#endif



