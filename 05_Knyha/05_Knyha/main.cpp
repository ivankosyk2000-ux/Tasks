#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int publikation_year;
};

int main() {
    Book book;
    getline(cin, book.title);
    getline(cin, book.author);
    cin >> book.publikation_year;

    cout << book.title << " by " << book.author << " was published in " << book.publikation_year << "." << endl;

    return 0;
}