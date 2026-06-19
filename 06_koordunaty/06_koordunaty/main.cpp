#include<iostream>
#include "Point.h"

using namespace std;

int main() {
	Point p;

	cout << "Print x: ";
	cin >> p.x;
	cout << "Print y: ";
	cin >> p.y;

	cout << "Point have koordinats (" << p.x << ";" << p.y << ")" << endl;
	return 0;
}