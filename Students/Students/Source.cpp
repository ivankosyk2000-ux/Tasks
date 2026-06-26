#include<iostream>
#include "Header.h"
using namespace std;

void InputStudents(vector<Student>& students) {
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << endl;

        cout << "Name: ";
        cin >> students[i].firstName;

        cout << "Surname: ";
        cin >> students[i].lastName;

        cout << "Enter 4 grades: ";
        for (int j = 0; j < 4; j++) {
            cin >> students[i].grades[j];
        }

        cout << endl;
    }
}
double CalculateAvarage(const Student& student) {
	int sum = 0;
	for (int i = 0; i < 4;i++) {
		sum += student.grades[i];
	}
	return sum / 4.0;
}

void PrintResults(const vector<Student>& students) {
    cout << "Results:\n";

    for (int i = 0; i < 5; i++) {
        double average = CalculateAvarage(students[i]);

        cout << students[i].firstName << " "
            << students[i].lastName << " ";

        if (average < 60)
            cout << "Reported";
        else
            cout << "Passed the session";

        cout << " (average score = " << average << ")" << endl;
    }
}