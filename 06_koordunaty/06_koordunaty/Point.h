#pragma once

struct Point {
    double x;
    double y;
};
struct Vector2D {
    double x = 0;
    double y = 0;
};
Point ReadPoint();
void PrintPoint(Point p);
Vector2D PointDifference(Point p1, Point p2);
void PrintVector(Vector2D v);
double FindLength(Vector2D v);