#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;

Point ReadPoint() {
    Point p;
    cin >> p.x >> p.y;
    return p;
}
void PrintPoint(Point p) {
    cout << "{" << p.x << ", " << p.y << "}";
}
Vector2D PointDifference(Point p1, Point p2) {
    Vector2D v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    return v;
}
void PrintVector(Vector2D v) {
    cout << "{" << v.x << ", " << v.y << "}";
}
double FindLength(Vector2D v) {
    return hypot(v.x, v.y);
}
Triangle ReadTriangle() {
    Triangle t;
    t.p1 = ReadPoint();
    t.p2 = ReadPoint();
    t.p3 = ReadPoint();
    return t;
}
double FindPerimeter(const Triangle& t) {
    double a = FindLength(PointDifference(t.p1, t.p2));
    double b = FindLength(PointDifference(t.p2, t.p3));
    double c = FindLength(PointDifference(t.p3, t.p1));
    return a + b + c;     
}