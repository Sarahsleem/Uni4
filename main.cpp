#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Department
{
private:
    string department_name;
    int capacity;
    double required_gpa;


public:

    void set_department_name(string dpname)
    {
        department_name = dpname;
    }

    void set_capacity(int s)
    {
        capacity = s;
    }
    void set_required_gpa(double gpa)
    {
        required_gpa = gpa;
    }

    string get_department_name()
    {
        return department_name;
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

class Proffeser: public person
{
private:
    string Proffeser_name;
    int degree;
    double salary;

public:

    void set_Proffeser_name(string pname)
    {
        Proffeser_name = pname;
    }

    void set_degree(int s)
    {
        degree = s;
    }
    void set_salary(double num)
    {
        salary = num;
    }

    string get_Proffeser_name()
    {
        return Proffeser_name;
    }
    int get_degree()
    {
        return degree;
    }
    double get_salary()
    {
        return salary;
    }

};

class University
{
private:
    vector<department> departments;
    vector<Proffeser> Proffesers;

    string name;
    static University *instancePtr;
    University() {}
public:
    University(const University& obj) = delete;
    static University *getInstance()
    {
        if(instancePtr == NULL)
        {
            instancePtr = new University();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }
    void add_department(string name,int capacity,double required_Gpa)
    {
        department ss;
        ss.set_department_name(name);
        ss.set_capacity(capacity);
        ss.set_required_gpa(required_Gpa);

        departments.push_back(ss);
    }

    bool update_departmant(string dpName, double dpGpa)
    {
        bool ret = false;
        for(uint64_t i = 0; i < departments.size(); i++)
        {
            if((departments[i].get_department_name()).compare(dpName) == 0)
            {
                departments[i].set_required_gpa(dpGpa);

                ret = true;
            }
        }
        return ret;
    }
     bool delete_departmant(string dpName)
    {
        bool ret = false;
        for(uint64_t i = 0; i < departments.size(); i++)
        {
            if(departments[i].get_department_name().compare(dpName) == 0)

            {
                departments.erase(departments.begin() + i);

                ret = true;
            }
        }
        return ret;
    }


    void setName(string name)
    {
        this->name = name;
    }


    string get_name()
    {
        return name;
    }

    void print()
    {
        cout<<"Name: "<<name<<endl;
    }
};

University* University::instancePtr = NULL;

int main()
{

}
cs
