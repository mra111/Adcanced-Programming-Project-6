#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include "document.hpp"

using namespace std;

#define MAGAZINE_BORROW_TIME 2
#define MAGAZINE_EXTEND_TIME 0


class Magazine : public Document {
public:
    Magazine (string input_title, int input_year, int input_number);
    int find_penalty (int day);

private:
    int year;
    int number;
};

#endif