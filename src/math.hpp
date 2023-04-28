#pragma once

#include <cmath>
struct Point 
{
    Point(const double x, const double y) : x_coordinate(x), y_coordinate(y) {}
    
    double x_coordinate;
    double y_coordinate;
};

struct Rectangle
{
    Rectangle(Point p_a, Point p_b) : point_a(p_a), point_b(p_b) {}
    
    const double get_height() {
        return std::abs(point_a.y_coordinate - point_b.y_coordinate);
    }

    const double get_width() {
        return std::abs(point_a.x_coordinate - point_b.x_coordinate);
    }

    Point point_a;
    Point point_b;
};

int add(int a, int b) 
{
    return a + b;
}