#include <iostream>

enum class Gender { MALE, FEMALE };
struct Date {
    int year;
    int month;
    int day;
};

struct Person {
    Date birth_date;
    std::string name; // Имя.
    int age;          // Возраст.
    Gender gender;    // Пол.
};

using namespace std::literals;

int main() {

    Person person = { {2009,9,7},"Ivan",17,Gender::MALE };
    Person person2 = { {2001,1,22},"Vlad", 25, Gender::MALE };
    //person2 = person;

    // Используем поля переменной person без предварительной инициализации.
    std::cout << "Date: "s << person.birth_date.year <<" "<< person.birth_date.month<<" "<< person.birth_date.day << std::endl;
    std::cout << "Name: "s << person.name << std::endl;
    std::cout << "Age: "s << person.age << std::endl;
    std::cout << "Gender: "s;
    if (person.gender == Gender::MALE) {
        std::cout << "Male"s;
    }
    else if (person.gender == Gender::FEMALE) {
        std::cout << "Female"s;
    }
    else {
        std::cout << "Unknown"s;
    }

    std::cout << std::endl;
    std::cout << "Date: "s << person2.birth_date.year << " " << person2.birth_date.month << " " << person2.birth_date.day << std::endl;
    std::cout << "Name: "s << person2.name << std::endl;
    std::cout << "Age: "s << person2.age << std::endl;
    std::cout << "Gender: "s;
    if (person2.gender == Gender::MALE) {
        std::cout << "Male"s;
    }
    else if (person2.gender == Gender::FEMALE) {
        std::cout << "Female"s;
    }
    else {
        std::cout << "Unknown"s;
    }
    std::cout << std::endl;

    
}