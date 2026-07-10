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
void PrintPoint(Point p);

Vector2D PointDifference(Point p1, Point p2);
void PrintVector(Vector2D v);
double FindLength(Vector2D v);

Triangle ReadTriangle();
double FindPerimeter(const Triangle& t);

Point GetCenter(const Triangle& t);
void MovePoint(Point& p, Vector2D v);
void MoveTriangle(Triangle& t, Vector2D v);
void PrintTriangle(const Triangle& t);