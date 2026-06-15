#include <iostream>
#include <string>

using namespace std;

struct Cat {
	string name;
	int age;
};

int main() {
	Cat kit;
	kit.name = "Leopold";
	kit.age = 3;

	cout << kit.name << " is now " << kit.age << " years old";
	return 0;

}