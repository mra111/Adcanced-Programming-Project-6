#include "person.hpp"

using namespace std;


Person::Person (string input_name) {
    name = input_name;
    penalty = 0;
    document_limit = NOT_SET;
}

string Person::get_name () {
    return name;
}

void Person::barrow_document (Document* document) {
    borrowed_documents.push_back (document);
}

void Person::extend_document (int document_index) {
    borrowed_documents[document_index]->extend ();
}

void Person::return_document (int document_index, int day) {
    penalty = penalty + borrowed_documents[document_index]->find_penalty (day);

    borrowed_documents[document_index]->return_document ();
    
    borrowed_documents.erase (borrowed_documents.begin () + document_index);
}

int Person::find_document (string title) {
    int i;

    for (i = 0; i < borrowed_documents.size (); i++) {
        if (title == borrowed_documents[i]->get_title ()) {
            return i;
        }
    }

    return NOT_FIND;
}

bool Person::can_borrow_more () {
    if (document_limit > borrowed_documents.size ()) {
        return true;
    }
    else {
        return false;
    }
}

Document* Person::get_document (int document_index) {
    return borrowed_documents[document_index];
}

int Person::find_total_penalty (int day) {
    int documents_penalty = 0;
    int i;

    for (i = 0; i < borrowed_documents.size (); i++) {
        documents_penalty = documents_penalty + borrowed_documents[i]->find_penalty (day);
    }

    return penalty + documents_penalty;
}