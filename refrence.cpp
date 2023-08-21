#include "refrence.hpp"

using namespace std;


Refrence::Refrence (string input_title) : Document (input_title) {
    title = input_title;
    borrow_time = REFRENCE_BORROW_TIME;
    extend_limit = REFRENCE_EXTEND_TIME;
}

int Refrence::find_penalty (int day) {
    int penalty = 0;
    int delay = day - return_day;
    int i;

    for (i = 1; i <= delay; i++) {
        if (i <= 3) {
            penalty = penalty + 5000;
        }
        else {
            penalty = penalty + 7000;
        }
    }

    return penalty;
}