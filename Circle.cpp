#include "Circle.h"
#include <cmath>

Circle::Circle(const Point2D& c, double r, const std::string& col)
    : Shape(col), center(c), radius(r) {}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::translate(double dx, double dy) {
    center.x += dx;
    center.y += dy;
}

void Circle::print(std::ostream& os) const {
    os << "Circle(center=" << center
       << ", r=" << radius
       << ", color=" << color << ")";
}

