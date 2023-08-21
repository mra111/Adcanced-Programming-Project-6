#include "student.hpp"

using namespace std;


Student::Student (int input_id, string input_name) : Person (input_name) {
    id = input_id;
    name = input_name;
    document_limit = STUDENT_LIMIT;
}