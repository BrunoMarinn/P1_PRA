#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point2D.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    Circle(const Point2D& c, double r, const std::string& col = "red");

    double area() const override;
    double perimeter() const override;
    void translate(double dx, double dy) override;
    void print(std::ostream& os) const override;
};

#endif

