#include <iostream>
#include "Point.h"

using namespace std;

int main(){
    Point p = ReadPoint();

    cout << "Read point: ";
    PrintPoint(p);
    cout << endl;

    Point symmetric;
    symmetric.x = -p.x;
    symmetric.y = -p.y;

    cout << "Symmetric point: ";
    PrintPoint(symmetric);

    return 0;
}