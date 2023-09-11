#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include "person.h"

using namespace std;

class Professor: public Person
{
private:
    string degree;
    double salary;
    Department * department;
public:
    Professor() { }
    Professor(int id, string _name, int age, char gender, Department * profDep, double _salary, string profDeg) : degree(profDeg), salary(_salary), department(profDep)
    {
        set_name(_name);
        set_gender(gender);
        set_id(id);
        set_age(age);
    }
    void set_degree(int s)
    {
        degree = s;
    }
    void set_department(Department * _department)
    {
        department = _department;
    }
    void set_salary(double num)
    {
        salary = num;
    }
    string get_degree()
    {
        return degree;
    }
    Department * get_department()
    {
        return department;
    }
    double get_salary()
    {
        return salary;
    }
    void personnone() {}
};

#endif