#include <iostream>
#include <string>
#include <cmath>

#include "calculator.h"

using namespace std;

Command parsecommand(const string& cmd) {
    if (cmd == "+") return Command::add;
    if (cmd == "-") return Command::sub;
    if (cmd == "*") return Command::mul;
    if (cmd == "**") return Command::pow;
    if (cmd == "/") return Command::div;
    if (cmd == "=") return Command::print;
    if (cmd == ":") return Command::set;
    if (cmd == "c") return Command::clear;
    if (cmd == "s") return Command::save;
    if (cmd == "l") return Command::load;
    if (cmd == "q") return Command::quit;

    return Command::unknown;
}

bool ReadNumber(Number& result) {
    if (!(cin >> result)) {
        cerr << "Error: Numeric operand expected" << endl;
        return false;
    }

    return true;
}

Calculator::Calculator()
    : number(0), memory(0), memoryFilled(false) {
}
void Calculator::Set(Number n) {
    number = n;
}
Number Calculator::GetNumber() const {
    return number;
}
void Calculator::Add(Number n) {
    number += n;
}
void Calculator::Sub(Number n) {
    number -= n;
}
void Calculator::Div(Number n) {
    number /= n;
}
void Calculator::Mul(Number n) {
    number *= n;
}
void Calculator::Pow(Number n) {
    number = static_cast<Number>(pow(number, n));
}
void Calculator::Save() {
    memory = number;
    memoryFilled = true;
}
void Calculator::Load() {
    number = memory;
}
bool Calculator::HasMem() const {
    return memoryFilled;
}
string Calculator::GetNumberRepr() const {
    return to_string(number);
}
bool RunCalculatorCycle() {

    Calculator calculator;

    Number value;

    if (!ReadNumber(value)) {
        return false;
    }

    calculator.Set(value);

    string cmd;

    while (cin >> cmd) {

        switch (parsecommand(cmd)) {

        case Command::add:
            if (!ReadNumber(value)) return false;
            calculator.Add(value);
            break;
        case Command::sub:
            if (!ReadNumber(value)) return false;
            calculator.Sub(value);
            break;
        case Command::mul:
            if (!ReadNumber(value)) return false;
            calculator.Mul(value);
            break;
        case Command::pow:
            if (!ReadNumber(value)) return false;
            calculator.Pow(value);
            break;
        case Command::div:
            if (!ReadNumber(value)) return false;
            calculator.Div(value);
            break;
        case Command::print:
            cout << calculator.GetNumberRepr() << endl;
            break;
        case Command::set:
            if (!ReadNumber(value)) return false;
            calculator.Set(value);
            break;
        case Command::clear:
            calculator.Set(0);
            break;
        case Command::save:
            calculator.Save();
            break;
        case Command::load:
            if (!calculator.HasMem()) {
                cerr << "Error: Memory is empty." << endl;
                return false;
            }
            calculator.Load();
            break;
        case Command::quit:
            return true;
        case Command::unknown:
        default:
            cerr << "Error: Unknown token " << cmd << "." << endl;
            return false;
        }
    }

    return false;
}