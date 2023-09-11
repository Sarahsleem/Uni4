#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "person.h"


class Student: public Person
{
private:
    int level;
    float gpa;
public:
    Student() {}
    Student(int id, string name, int age,char gender,int level ,double gpa)
    {
        set_id(id);
        set_age(age);
        set_gender(gender);
        set_name(name);
        this->level=level;
        this->gpa=gpa;
    }
    void set_level(int levelst)
    {
        level=levelst;
    }
    int get_level()
    {
        return level;
    }
    void set_gpa(float gpast)
    {
        gpa=gpast;
    }
    float get_gpa()
    {
        return gpa;
    }
    void personnone() {}


};

#endif