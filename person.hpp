#ifndef PERSON_HPP
#define PERSON_HPP

#include <vector>
#include <string>
#include "book.hpp"
#include "refrence.hpp"
#include "magazine.hpp"

using namespace std;

#define NOT_SET 0
#define NOT_FIND -1


class Person {
public:
    Person (string input_name);
    void barrow_document (Document* document);
    void extend_document (int document_index);
    void return_document (int document_index, int day);
    string get_name ();
    int find_document (string title);
    bool can_borrow_more ();
    Document* get_document (int document_index);
    int find_total_penalty (int day);

protected:
    string name;
    int penalty;
    int document_limit;
    vector<Document*> borrowed_documents;
};

#endif