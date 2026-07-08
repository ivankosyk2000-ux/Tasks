#pragma once

struct Point {
    double x;
    double y;
};
struct Vector2D {
    double x = 0;
    double y = 0;
};
struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};
Point ReadPoint();
Vector2D PointDifference(Point p1, Point p2);
void PrintVector(Vector2D v);
double FindLength(Vector2D v);

Triangle ReadTriangle();
double FindPerimeter(const Triangle& t);