#include "book.hpp"

using namespace std;


Book::Book (string input_title) : Document (input_title) {
    title = input_title;
    borrow_time = BOOK_BORROW_TIME;
    extend_limit = BOOK_EXTEND_TIME;
}

int Book::find_penalty (int day) {
    int penalty = 0;
    int delay = day - return_day;
    int i;

    for (i = 1; i <= delay; i++) {
        if (i <= 7) {
            penalty = penalty + 2000;
        }
        else if (i >= 8 && i <= 21) {
            penalty = penalty + 3000;
        }
        else {
            penalty = penalty + 5000;
        }
    }

    return penalty;
}