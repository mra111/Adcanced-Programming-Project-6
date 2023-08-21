#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>

using namespace std;

#define BORROWED 1
#define NOT_BORROW 0
#define NOT_SET 0


class Document {
public:
    Document (string input_title);
    string get_title ();
    bool is_borrow_possible ();
    void borrow (int day);
    void extend ();
    void return_document ();
    bool is_borrow_day (int day);
    bool is_after_return_day (int day);
    bool can_extent_more ();
    bool is_magazine ();
    virtual int find_penalty (int day) = 0;

protected:
    string title;
    int status;
    int borrow_day;
    int return_day;
    int borrow_time;
    int extend_time;
    int extend_limit;
};

#endif