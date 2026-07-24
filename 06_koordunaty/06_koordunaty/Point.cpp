#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;

Point ReadPoint() {
    Point p;
    cin >> p.x >> p.y;
    return p;
}
/*void PrintPoint(Point p) {
    cout << "{" << p.x << ", " << p.y << "}";
}*/
Vector2D PointDifference(Point p1, Point p2) {
    Vector2D v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    return v;
}
void ScaleVector(Vector2D& v, double s) {
    v.x *= s;
    v.y *= s;
}
void OffsetPoint(Point& p, Vector2D v) {
    p.x += v.x;
    p.y += v.y;
}

/*void PrintVector(Vector2D v) {
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

Point GetCenter(const Triangle& t) {
    Point p;
    p.x += (t.p1.x + t.p2.x + t.p3.x) / 3;
    p.y += (t.p1.y + t.p2.y + t.p3.y) / 3;
    return p;
}
void MovePoint(Point& p, Vector2D v) {
    p.x += v.x;
    p.y += v.y;
}
void MoveTriangle(Triangle& t, Vector2D v) {
    MovePoint(t.p1, v);
    MovePoint(t.p2, v);
    MovePoint(t.p3, v);
}
void PrintTriangle(const Triangle& t) {
    cout << "{"; 
    PrintPoint(t.p1); 
    cout << ", ";
    PrintPoint(t.p2);
    cout << ", ";
    PrintPoint(t.p3);
    cout << "}";
}*/