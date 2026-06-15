#include<iostream>
#include<string>

using namespace std;

struct Fruit {
	string name;
	double weight;
	string date_of_expiration;
};

int main() {
	Fruit fruits[3];

	for (int i = 0; i < 3; i++) {
		cout << "Print fruit parametrs: " << i + 1 << ":" << endl;

		cout << "Name: ";
		cin >> fruits[i].name;

		cout << "Weight: ";
		cin >> fruits[i].weight;

		cout << "Expiration on date: ";
		cin >> fruits[i].date_of_expiration;

		cout << endl;
	}
	cout << "Information on fruits: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Fruit: " << i + 1 << ":" << endl;
		cout << "Name: " << fruits[i].name << endl;
		cout << "Weight: " << fruits[i].weight << endl;
		cout << "Expiration on date: " << fruits[i].date_of_expiration << endl;
		cout << endl;
	}
	return 0;
}