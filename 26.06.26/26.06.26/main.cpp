#include <iostream>
#include <cassert>
using namespace std;

struct Point {
	int x = 1;
	int y = 0;
};

struct RGBAColor {
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 1;
};

struct TextWithStyle {
	int size = 8;
	RGBAColor color = { 0,0,0,1 };
	Point position = { 100,100 };
	bool is_bold = true;
	bool is_italic = false;
	string text = "Specify text";
};

int main() {
	TextWithStyle t;
	assert(t.size == 8);
	assert(t.color.r == 0);
	assert(t.color.g == 0);
	assert(t.color.b == 0);
	assert(t.color.a == 1);
	assert(t.position.x == 100);
	assert(t.position.y == 100);
	assert(t.is_bold);
	assert(!t.is_italic);
	assert(t.text == "Specify text");


	//Point p;
	//assert(p.x == 0);
	//assert(p.y == 0);
	///*if (p.x == 0) {
	//	cout << "Pass" << endl;
	//}
	//if (p.y == 0) {
	//	cout << "Pass" << endl;
	//}*/
	return 0;
}