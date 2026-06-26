#include <iostream>
#include <vector>
#include "Header.h"

using namespace std;

int main() {
    vector<Student> students(5);

    InputStudents(students);
    PrintResults(students);

    return 0;
}
    

    