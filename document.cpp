#include "document.hpp"

using namespace std;

Document::Document (string input_title) {
    title = input_title;
    status = NOT_BORROW;
    borrow_day = NOT_SET;
    return_day = NOT_SET;
    borrow_time = NOT_SET;
    extend_time = NOT_SET;
    extend_limit = NOT_SET;
}

string Document::get_title () {
    return title;
}

bool Document::is_borrow_possible () {
    if (status == NOT_BORROW) {
        return true;
    }
    else {
        return false;
    }
}

void Document::borrow (int day) {
    borrow_day = day;
    return_day = day + borrow_time;
    status = BORROWED;
    extend_time = 0;
}

void Document::extend () {
    return_day = return_day + borrow_time;
    extend_time = extend_time + 1;
}

void Document::return_document () {
    status = NOT_BORROW;
    borrow_day = NOT_SET;
    return_day = NOT_SET;
    extend_time = NOT_SET;
}

bool Document::is_borrow_day (int day) {
    if (day == borrow_day) {
        return true;
    }
    else {
        return false;
    }
}

bool Document::is_after_return_day (int day) {
    if (day > return_day) {
        return true;
    }
    else {
        return false;
    }
}

bool Document::can_extent_more () {
    if (extend_time < extend_limit) {
        return true;
    }
    else {
        return false;
    }
}

bool Document::is_magazine () {
    if (extend_limit == 0) {
        return true;
    }
    else {
        return false;
    }
}