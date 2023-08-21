#ifndef REFRENCE_HPP
#define REFRENCE_HPP

#include "document.hpp"

using namespace std;

#define REFRENCE_BORROW_TIME 5
#define REFRENCE_EXTEND_TIME 2


class Refrence : public Document {
public:
    Refrence (string input_title);
    int find_penalty (int day);
};

#endif