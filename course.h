#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstring>  

using namespace std;

class Professor{
    public:
    string name;
};

class Student{
    public:
    string name;
};

class Course {
private:
    string courseName = NULL;
    string courseCode = NULL;
    int courseHours = 0;
    Professor * professor = NULL;
    vector <Student *> students;
    int students_count = 0;
    vector <string> prerequisites;
public:
    /* Default Constructor */
    Course(){  }
    /* Parameterize Constructor */
    Course(string name, string code):courseName(name), courseCode(code) {  }
    Course(string name, string code, int hours):courseName(name), courseCode(code), courseHours(hours) {  }
    
    /* Setter */
    void set_name(string name){
        courseName = name;
    }

    void set_code(string code){
        courseCode = code;
    }

    void set_hours(int hours){
        courseHours = hours;
    }
    
    void set_professor(Professor& prof)
    {
        professor = &prof;
    }
    void set_student(Student& student)
    {
        students.insert(students.begin() + students_count , &student);
        students.push_back(NULL);                                    /* End of vector indicator */
        students_count++;
    }
    void set_prerequisites(Course& pre)
    {
        prerequisites.push_back(pre.courseCode);
    }
    /* Getter */
    string get_name(void)
    {
        return courseName;
    }
    string get_code(void)
    {
        return courseCode;
    }
    int get_hours(void)
    {
        return courseHours;
    }

    Professor * get_professor(void)
    {
        return professor;
    }
    int get_students_count(void)
    {
        return students_count;
    }
    Student * get_student(const int student_num)
    {
        Student * ret = students[student_num];
        if(student_num >= students_count){
            ret = NULL;
        }
        return ret;
    }
    vector <Student *> get_students()
    {
        return students;
    }
    vector <string> get_prerequisites(Course& pre)
    {
        return prerequisites;
    }
    /* Remove Student */
    void remove_student()
    {
        students_count--;
        students.erase(students.begin() + students_count);
    }
    void remove_student(int student_num)
    {
        students_count--;
        students.erase(students.begin() + student_num);
    }    

    /* Deconstructor */
    ~Course(){       }
};


class University{
private:
    string name;
    vector <Course> courses;
    /* Create privete Ptr from University Class */
    static University * universityPtr;
    /* Make constractor privete */
    University() : courses(){  }
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
        {
            return universityPtr; 
        }
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
    /* Add */
    void add_course(string cName, string cCode, int cHours, Professor& prof)
    {
        /* Take prof as string to hold professor name */
        /* Then search about the prof if he exist in system or not */
        if(cHours > 0 && cHours < 5)
        {
            cout<<"hello\n";
            Course crsTemp(cName, cCode, cHours);
            crsTemp.set_professor(prof);
            cout<<courses.size();
            courses.push_back(crsTemp); // Problem in vector in class
            cout<<"lol\n";
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
            }
        }
        return ret;
    }
    
};


#endif