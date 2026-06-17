#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string surname;
};

int main() {
    Person groom;
    Person bride;
    cin >> groom.name >> groom.surname;
    cin >> bride.name >> bride.surname;
    cout << groom.name << " " << groom.surname << " and " << bride.name << " " << bride.surname << "! I pronounce you husband and wife.\n";

    return 0;
}