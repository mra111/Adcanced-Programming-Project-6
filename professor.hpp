#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "person.hpp"

using namespace std;

#define PROFESSOR_LIMIT 5


class Professor : public Person {
public:
    Professor (string input_name);
};

#endif