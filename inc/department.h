#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_

#include <iostream>
#include <string>

class Department
{
private:
    string name;
    int capacity;
    double required_gpa;
public:
    Department() { }
    Department(string _name, int _capacity, double _required_gpa) 
    : name(_name), capacity(_capacity), required_gpa(_required_gpa) 
    {

    }

    void set_name(string dpname)
    {
        name = dpname;
    }

    void set_capacity(int s)
    {
        capacity = s;
    }
    void set_required_gpa(double gpa)
    {
        required_gpa = gpa;
    }

    string get_name()
    {
        return name;
    }
    int get_capacity()
    {
        return capacity;
    }
    double get_required_gpa()
    {
        return required_gpa;
    }
};

#endif /* _DEPARTMENT_H_ */
