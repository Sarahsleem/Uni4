#ifndef _UNIVERSITY_H_
#define _UNIVERSITY_H_

#include "student.h"
#include "department.h"
#include "course.h" 
#include "professor.h"

class University{
private:
    string name;
    vector <Student> students;
    vector <Course> courses;
    vector <Department> departments;
    vector <Professor> professors;
    /* Create privete Ptr from University Class */
    static University * universityPtr ;
    /* Make constractor privete */
    University()
    { 
        addData();
        //printAll();
    }
public:
    /* Delete Copy_constructor */
    University(const University& obj) = delete;
    /* Get instance */
    static University *get_university_ptr()
    {
        if(universityPtr == NULL)
        {
            universityPtr = new University();
        }
        else
        {   }
        return universityPtr;
    }
    
    void set_name(string name)
    {
        this->name = name;
    }
    string get_name(void)
    {
        return name;
    }
    vector <Course> get_courses(void)
    {
        return courses;
    }
    /* Course Functions */
    void add_course(string cName, string cCode, int cHours, vector<Course*> prePtr, Professor& prof, vector<Student*> stPtr)
    {
        /* Take prof as string to hold professor name */
        /* Then search about the prof if he exist in system or not */
        if(cHours > 0 && cHours < 5)
        {
            //cout<<"hello\n";
            Course crsTemp(cName, cCode, cHours, prePtr, &prof, stPtr);
            crsTemp.set_professor(prof);
            //cout<<courses.size();
            courses.push_back(crsTemp); // Problem in vector in class
            //cout<<"lol\n";
        }
    }
    bool update_course(string uiCode, int hour)
    {
        bool ret = false;
        for(int i = 0; i < courses.size(); i++)
        {
            if(courses[i].get_code().compare(uiCode) == 0)
            {
                courses[i].set_hours(hour);
                ret = true;
                break;
            }
            else{    }
        }
        return ret;
    }

    bool delete_course(string uiCode)
    {   
        bool ret = false;
        for(int i = 0; i < courses.size(); i++)
        {
             if(courses[i].get_code().compare(uiCode) == 0)
            {
                courses.erase(courses.begin() + i);
                ret = true;
                break;
            }
        }
        return ret;
    }
    /* Student  */
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
   /* Department Funcs */
   void add_department(string name,int capacity,double required_Gpa)
   {
        Department ss;
        ss.set_name(name);
        ss.set_capacity(capacity);
        ss.set_required_gpa(required_Gpa);

        departments.push_back(ss);
    }

    bool update_departmant(string dpName, double dpGpa)
    {
        bool ret = false;
        for(uint64_t i = 0; i < departments.size(); i++)
        {
            if((departments[i].get_name()).compare(dpName) == 0)
            {
                departments[i].set_required_gpa(dpGpa);

                ret = true;
                break;
            }
        }
        return ret;
    }
        bool delete_departmant(string dpName)
    {
        bool ret = false;
        for(uint64_t i = 0; i < departments.size(); i++)
        {
            if(departments[i].get_name().compare(dpName) == 0)

            {
                departments.erase(departments.begin() + i);

                ret = true;
                break;
            }
        }
        return ret;
    }
    /* Prof Funcs */
    void add_professer(int id1,int age1,string name1,char gender1, int degree, double salary)
    {
        Professor prof;
        prof.set_name(name1);
        prof.set_age(age1);
        prof.set_id(id1);
        prof.set_gender(gender1);
        prof.set_degree(degree);
        prof.set_salary(salary);
        professors.push_back(prof);
    }
    bool update_professor_salary(int id, double salary)
    {
        bool flag =false;
        for(int i=0; i<professors.size(); i++)
        {
            if(professors[i].get_id()== id)
            {
                professors[i].set_salary(salary);
                flag = true;
                break;
            }
        }
        return flag;
    }
    bool delete_professor(int id)
    {
        bool flag = false;

        for(int i=0; i<professors.size(); i++)
        {
            if(professors[i].get_id()==id)
            {

                professors.erase(professors.begin() + i);
                flag =  true;
                break;
            }
        }
        return flag;
   }
   /* Add Data */
   void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2,"Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4,"Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5,"Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6,"Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8,"Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(1, "Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professors.push_back(p1);
        Professor p2(2,"Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professors.push_back(p2);
        Professor p3(3,"Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professors.push_back(p3);
        Professor p4(4,"Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professors.push_back(p4);
        Professor p5(5,"Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professors.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i].get_name()<<endl;
        }
        for(int i=0; i<professors.size(); i++)
        {
            cout<<"Professor Name: "<<professors[i].get_name()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i].get_name()<<endl;
        }
        for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i].get_name()<<endl;
        }
    }
};

#endif