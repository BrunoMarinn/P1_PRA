#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>

class Point2D {
public:
    double x;
    double y;

    Point2D(double x_ = 0.0, double y_ = 0.0) : x(x_), y(y_) {}

    static double distance(const Point2D& a, const Point2D& b) {
        return std::sqrt((a.x - b.x)*(a.x - b.x) +
                         (a.y - b.y)*(a.y - b.y));
    }

    bool operator==(const Point2D& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point2D& other) const {
        return !(*this == other);
    }
};

inline std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

#endif

