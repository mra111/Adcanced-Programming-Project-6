#include "Library.hpp"

using namespace std;


Library::Library () {
    day = 1;
}

int Library::find_member (string name) {
    int i;

    for (i = 0; i < members.size (); i++) {
        if (name == members[i]->get_name ()) {
            return i;
        }
    }

    return NOT_FIND;
}

int Library::find_document (string title) {
    int i;

    for (i = 0; i < documents.size (); i++) {
        if (title == documents[i]->get_title ()) {
            return i;
        }
    }

    return NOT_FIND;
}

int Library::find_available_document (string title) {
    int i;

    for (i = 0; i < documents.size (); i++) {
        if (title == documents[i]->get_title () && documents[i]->is_borrow_possible () == true) {
            return i;
        }
    }

    return NOT_FIND;
}

void Library::check_member (string name ) {
    if (find_member (name) != NOT_FIND) {
        cout << "Name already exists" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    else if (name == "") {
        cout << "Empty field" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }
}

void Library::check_book_and_refrence (string name) {
    if (find_document (name) != NOT_FIND) {
        cout << "A document with specified name already exists" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    else if (name == "") {
        cout << "Empty field" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }
}

void Library::check_magazine (string name, int year, int number) {
    if (find_document (name) != NOT_FIND) {
        cout << "A document with specified name already exists" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    else if (name == "") {
        cout << "Empty field" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    else if (year <= 0) {
        cout << "Invalid year" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    else if (number <= 0) {
        cout << "Invalid number" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }
}

void Library::add_student_member (string student_id, string student_name) {
    int id;

    check_member (student_name);
    
    if (student_id == "") {
        cout << "Empty field" << endl;
        exit (EXIT_SUCCESS);
    }

    id = stoi (student_id);
    members.push_back (new Student (id, student_name));
}

void Library::add_prof_member (string prof_name) {
    check_member (prof_name);

    members.push_back (new Professor (prof_name));
}

void Library::add_book (string book_title, int copies) {
    int i;

    check_book_and_refrence (book_title);

    for (i = 0; i < copies; i++) {
        documents.push_back (new Book (book_title));
    }
}

void Library::add_magazine (string magazine_title, int year, int number, int copies) {
    int i;

    check_magazine (magazine_title, year, number);

    for (i = 0; i < copies; i++) {
        documents.push_back (new Magazine (magazine_title, year, number));
    }
}

void Library::add_reference (string refrence_title, int copies) {
    int i;

    check_book_and_refrence (refrence_title);

    for (i = 0; i < copies; i++) {
        documents.push_back (new Refrence (refrence_title));
    }
}

void Library::check_borrow (int member_index, int document_index) {
    if (members[member_index]->can_borrow_more () == false) {
        cout << "Maximum number of allowed borrows exceeded" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    else if (document_index == NOT_FIND) {
        cout << "This document does not exist" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    else if (members[member_index]->find_document (documents[document_index]->get_title ()) != NOT_FIND) {
        cout << "You borrowed this document already" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }
}

void Library::borrow (string member_name, string document_title) {
    int member_index;
    int document_index;

    member_index = find_member (member_name);
    document_index = find_available_document (document_title);

    check_borrow (member_index, document_index);

    members[member_index]->barrow_document (documents[document_index]);
    documents[document_index]->borrow (day);
}

void Library::check_extend (int member_index, int document_index) {
    if (document_index == NOT_FIND) {
        cout << "You have not borrowed this document" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    Document* document = members[member_index]->get_document (document_index);

    if (document->is_borrow_day (day) == true) {
        cout << "You can't extend and borrow a document on the same day" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    if (document->is_after_return_day (day) == true) {
        cout << "You can't renew a document after receiving penalty" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    if (document->is_magazine () == true) {
        cout << "You can't renew magazines" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }

    if (document->can_extent_more () == false) {
        cout << "You can't renew a document more than two times" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }
}

void Library::extend (string member_name, string document_title) {
    int member_index;
    int document_index;

    member_index = find_member (member_name);
    document_index = members[member_index]->find_document (document_title);

    check_extend (member_index, document_index);

    members[member_index]->extend_document (document_index);
}

void Library::check_return (int document_index) {
    if (document_index == NOT_FIND) {
        cout << "You have not borrowed this document" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }
}

void Library::return_document (string member_name, string document_title) {
    int member_index;
    int document_index;

    member_index = find_member (member_name);
    document_index = members[member_index]->find_document (document_title);

    check_return (document_index);

    members[member_index]->return_document (document_index, day);
}

int Library::get_total_penalty (string member_name) {
    int penalty;

    int member_index = find_member (member_name);

    penalty = members[member_index]->find_total_penalty (day);

    return penalty;
}

void Library::time_pass (int days) {
    if (days < 0) {
        cout << "Invalid day" << endl;
        free_lists ();
        exit (EXIT_SUCCESS);
    }
    else {
        day = day + days;
    }
}

void Library::free_lists () {
    int i;

    for (i = 0; i < members.size (); i++) {
        delete (members[i]);
    }

    for (i = 0; i < documents.size (); i++) {
        delete (documents[i]);
    }
}

int Library::find_title (string title, vector<string> &titles_list) {
    int i;

    for (i = 0; i < titles_list.size (); i++) {
        if (title == titles_list[i]) {
            return i;
        }
    }

    return NOT_FIND;
}

vector<string> Library::available_titles () {
    int i;
    vector<string> titles_list;

    for (i = 0; i < documents.size (); i++) {
        if (documents[i]->is_borrow_possible () == true && 
            find_title (documents[i]->get_title (), titles_list) == NOT_FIND) {
            titles_list.push_back (documents[i]->get_title ());
        } 
    }

    return titles_list;
}