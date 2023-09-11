#include <iostream>

#include "./inc/university.h"

University *uni;

int main()
{
    uni = University::get_university_ptr();
    
    uni->printAll();

    uni->delete_course("Net521");

    uni->printAll();
    
    return 0;
}