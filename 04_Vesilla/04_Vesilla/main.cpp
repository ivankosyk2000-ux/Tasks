#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
};

int main() {
    Person groom;
    Person bride;
    getline(cin, groom.name);
    getline(cin, bride.name);
    cout << groom.name << " and " << bride.name << "! I pronounce you husband and wife.\n";

    return 0;
}