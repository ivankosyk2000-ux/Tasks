#include <iostream>
#include <string>

using namespace std;

struct Person {
	string firstname;
	string lastname;
};

int main() {
	Person person1;
	person1.firstname = "Harry";
	person1.lastname = "Potter";
	Person person2;
	person2.firstname = "Hermione";
	person2.lastname = "Granger";

	cout << person1.firstname << " " << person1.lastname << endl;
	cout << person2.firstname << " " << person2.lastname << endl;

	return 0;
}