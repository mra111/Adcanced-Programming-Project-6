#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

using namespace std;

#define STUDENT_LIMIT 2


class Student : public Person {
public:
    Student (int input_id, string input_name);
    
private:
    int id;
};

#endif