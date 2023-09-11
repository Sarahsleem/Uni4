#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstring> 
#include "professor.h"
#include "student.h"

using namespace std;

class Course {
private:
    string courseName = NULL;
    string courseCode = NULL;
    int courseHours = 0;
    Professor * professor = NULL;
    vector <Student *> students;
    
    int students_count = 0;
    vector <Course *> prerequisites;
public:
    /* Default Constructor */
    Course(){  }
    /* Parameterize Constructor */
    Course(string name, string code, int hours, vector<Course*> prePtr, Professor * prfPtr, vector<Student*> stPtr):courseName(name), courseCode(code), courseHours(hours) 
    {
        prerequisites = prePtr;
        professor = prfPtr;
        students = stPtr;
    }
    
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
    void set_prerequisites(vector <Course *> pre)
    {
        prerequisites = pre;
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
    vector <Course *> get_prerequisites()
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


#endif