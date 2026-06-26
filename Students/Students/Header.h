#pragma once
#include <string>
#include <vector>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int grades[4];
};
void InputStudents(vector<Student>& students);
void PrintResults(const vector<Student>& students);
double CalculateAvarage(const Student& student);
