#ifndef __LIBRARY_HH__
#define __LIBRARY_HH__

#include <iostream>
#include <vector>
#include <string>
#include "student.hpp"
#include "professor.hpp"
#include "book.hpp"
#include "refrence.hpp"
#include "magazine.hpp"

using namespace std;

#define NOT_FIND -1
#define STUDENT 1
#define PROFESSOR 2
#define BOOK 1
#define REFRENCE 2
#define MAGAZINE 3


class Library {
public:
	Library ();
	void add_student_member(string student_id, string student_name);
	void add_prof_member(string prof_name);
	void add_book(string book_title, int copies);
	void add_magazine(string magazine_title, int year, int number, int copies);
	void add_reference(string reference_title, int copies);
	void borrow(string member_name, string document_title);
	void extend(string member_name, string document_title);
	void return_document(string member_name, string document_title);
	int get_total_penalty(string member_name);
	vector<string> available_titles();
	void time_pass(int days);
	void free_lists ();

private:
	int find_member (string name);
	int find_document (string title);
	int find_available_document (string title);
	void check_member (string name);
	void check_book_and_refrence (string title);
	void check_magazine (string title, int year, int number);
	void check_borrow (int member_index, int document_index);
	void check_extend (int member_index, int document_index);
	void check_return (int document_index);
	int find_title (string title, vector<string> &titles_list);

	vector<Person*> members;
	vector<Document*> documents;
	int day;
};

#endif