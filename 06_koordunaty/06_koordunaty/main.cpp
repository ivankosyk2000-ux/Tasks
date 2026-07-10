#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    /*Point p1 = ReadPoint();
    Point p2 = ReadPoint();
    
    Vector2D v = PointDifference(p1, p2);

    PrintVector(v);
    cout << endl;
    cout << FindLength(v) << endl;*/

    //Triangle t = ReadTriangle();
    //cout << FindPerimeter(t) << endl;


    Triangle t = ReadTriangle();
    Point origin = GetCenter(t);
    Point center = ReadPoint();
    Vector2D offset = PointDifference(center, origin);
    std::cout << "Original center: ";
    PrintPoint(origin);
    std::cout << endl;
    std::cout << "Bias: ";
    PrintVector(offset);
    std::cout << endl;
    MoveTriangle(t, offset);
    PrintTriangle(t);
    std::cout << endl;
    return 0;
}
