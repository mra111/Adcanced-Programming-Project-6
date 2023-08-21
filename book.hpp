#ifndef BOOK_HPP
#define BOOK_HPP

#include "document.hpp"

using namespace std;

#define BOOK_BORROW_TIME 10
#define BOOK_EXTEND_TIME 2


class Book : public Document {
public:
    Book (string input_title);
    int find_penalty (int day);
};

#endif