#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace std::literals;

class Duck {
public:
	void SetName(const std::string& name) {
		name_ = name;
	}
	void Fly(int distance) {
		total_distanse_ += distance;
		std::cout << name_ << " flies " << distance << "km. Total flight distance is " << total_distanse_ << "km." << std::endl;

	}
private:
	std::string name_;
	int total_distanse_ = 0;
};
int main() {
	int n;
	std::cin >> n;

	vector<Duck> ducks(n);
	for (int i = 0; i < n; i++) {
		string name;
		getline(cin, name);
		if (name.empty()) {
			getline(cin, name);
		}
		ducks[i].SetName(name);
	}
	int num_commands;
	cin >> num_commands;

	for (int i = 0; i < num_commands; i++) {
		int duck_number, distance;
		cin >> duck_number >> distance;
		ducks[duck_number].Fly(distance);
	}
	return 0;
}
