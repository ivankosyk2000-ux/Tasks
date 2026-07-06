#include <iostream>
#include "Point.h"

using namespace std;

Point ReadPoint(){
    Point p;
    cin >> p.x >> p.y;
    return p;
}

void PrintPoint(Point p){
    cout << "{" << p.x << ", " << p.y << "}";
}