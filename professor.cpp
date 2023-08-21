#include "professor.hpp"

using namespace std;


Professor::Professor (string input_name) : Person (input_name) {
    name = input_name;
    penalty = 0;
    document_limit = PROFESSOR_LIMIT;
}