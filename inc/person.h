#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <vector>

using namespace std;

class Person
{
private :
    int id,age;
    string name;
    char gender;
public:
    Person() {}

    void Pesron(int id, int age,string name,char gender)
    {
        this->id=id;
        this->age=age;
        this->gender=gender;
        this->name=name;
    }
    void set_id(int idpr)
    {
        id=idpr;
    }
    int get_id()
    {
        return id;
    }
    void set_age(int agepr)
    {
        age=agepr;
    }
    int get_age()
    {
        return age;
    }
    void set_name(string namepr)
    {
        name=namepr;
    }
    string get_name()
    {
        return name;
    }
    void set_gender(char genderpr)
    {
        gender=genderpr;
    }
    char get_gender()
    {
        return gender;
    }
    virtual void personnone()=0;
};

#endif
/*
class University
{
// delete copy constructor
private :
    University() {}
    static University *ptr;


public:

    University(const University&obj)=delete;
    static University *getInstance()
    {
        if(ptr == NULL)
        {
            ptr = new University();
            return ptr;
        }
        else
        {
            return ptr;
        }
    }
    void add_student(int id1,int age1,int level1,float gpa1,string name1,char gender1)
    {
        Student st1;
        st1.set_name(name1);
        st1.set_age(age1);
        st1.set_id(id1);
        st1.set_gender(gender1);
        st1.set_level(level1);
        st1.set_gpa(gpa1);
        students.push_back(st1);
    }
    bool update_student_gpa(int id,float gpa)
    {
        bool flag =false;
        for(int i=0; i<students.size(); i++)
        {
            if(students[i].get_id()==id)
            {
                students[i].set_gpa(gpa);
                return true;
                break;
            }
        }
        if(flag == false)
        {
            cout<<"student id is unfound"<<endl;
            return false;

        }

    }
    bool delete_student(int id)
    {
        bool flag =false;

        for(int i=0; i<students.size(); i++)
        {
            if(students[i].get_id()==id)
            {

                students.erase(students.begin() + i);
                return true;
            }
            if(flag == false)
            {
                cout<<"student id is unfound"<<endl;
                return false;
            }
        }

    }

};
*/