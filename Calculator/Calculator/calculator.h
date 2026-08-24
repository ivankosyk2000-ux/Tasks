#pragma once

#include <string>

using Number = double;

enum class Command {
    add,
    sub,
    mul,
    pow,
    div,
    print,
    set,
    clear,
    save,
    load,
    quit,
    unknown
};

Command parsecommand(const std::string& cmd);

bool ReadNumber(Number& result);

class Calculator {
private:
    Number number;
    Number memory;
    bool memoryFilled;

public:
    Calculator();

    void Set(Number n);
    Number GetNumber() const;

    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);

    void Save();
    void Load();

    bool HasMem() const;

    std::string GetNumberRepr() const;
};

bool RunCalculatorCycle();