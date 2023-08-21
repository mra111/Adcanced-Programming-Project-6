#include <iostream>
#include <set>
#include "Library.hpp"

using namespace std;


int main () {
    Library ut_lib;
	vector<string> titles;
	ut_lib.add_student_member("0", "std1");
	ut_lib.add_book("book1", 2);
	ut_lib.time_pass(10);
	ut_lib.add_reference("ref1", 3000);
	ut_lib.time_pass(10);
	ut_lib.add_magazine("magazine1", 2010, 10, 2);
	ut_lib.time_pass(10);

	ut_lib.borrow("std1", "ref1");
	ut_lib.borrow("std1", "magazine1");
	ut_lib.time_pass(1);
	ut_lib.extend("std1", "ref1");
	ut_lib.time_pass(1);

	ut_lib.return_document("std1", "magazine1");
	ut_lib.time_pass(10);

	titles = ut_lib.available_titles();
	ut_lib.return_document("std1", "ref1");
	ut_lib.time_pass(100);

	ut_lib.borrow("std1", "ref1");
	ut_lib.borrow("std1", "book1");
	cout << ut_lib.get_total_penalty("std1") << endl;
  	
    return 0;
}