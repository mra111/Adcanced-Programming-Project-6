#include "magazine.hpp"

using namespace std;


Magazine::Magazine (string input_title ,int input_year, int input_number) : Document (input_title) {
    title = input_title;
    year = input_year;
    number = input_number;
    borrow_time = MAGAZINE_BORROW_TIME;
    extend_limit = MAGAZINE_EXTEND_TIME;
}

int Magazine::find_penalty (int day) {
    int penalty;
    int delay = day - return_day;

    if (delay > 0) {
        if (year < 1390) {
            penalty = delay * 2000;
        }
        else {
            penalty = delay * 3000;
        }
    }
    else {
        penalty = 0;
    }

    return penalty;
}