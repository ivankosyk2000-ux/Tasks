#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    //Point p1 = ReadPoint();
    //Point p2 = ReadPoint();

    //Vector2D v = PointDifference(p1, p2);

    //PrintVector(v);
    //cout << endl;
    //cout << FindLength(v) << endl;

    Triangle t = ReadTriangle();
    cout << FindPerimeter(t) << endl;

    return 0;
}