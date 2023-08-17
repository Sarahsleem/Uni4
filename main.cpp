#include <iostream>
#include <vector>

using namespace std;

class person
{
private :
    int id,age;
    string name;
    char gender;
public:
    person() {}

    void pesron(int id, int age,string name,char gender)
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

class Student: public person
{
private:
    int level;
    float gpa;
public:
    Student() {}
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
class University
{
// delete copy constructor
private :
    University() {}
    static University *ptr;

    vector <Student> students;

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
    void add(int id1,int age1,int level1,float gpa1,string name1,char gender1)
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
    bool update_gpa(int id,float gpa)
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
    bool Delete(int id)
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
int main()
{



    return 0;
}
