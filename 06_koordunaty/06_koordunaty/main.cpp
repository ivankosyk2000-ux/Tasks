#include<iostream>

using namespace std;

struct Point {
	double x;
	double y;
};

int main() {
	Point p;

	cout << "Print x: ";
	cin >> p.x;
	cout << "Print y: ";
	cin >> p.y;

	cout << "Point have koordinats (" << p.x << ";" << p.y << ")" << endl;
	return 0;
}