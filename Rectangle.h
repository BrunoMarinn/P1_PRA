#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    static const int N_VERTICES = 4;
    Point2D* vs;

    void check(const Point2D* vertices) const;

public:
    Rectangle(const Point2D* vertices, const std::string& col = "red");
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    virtual ~Rectangle();

    double area() const override;
    double perimeter() const override;
    void translate(double dx, double dy) override;
    void print(std::ostream& os) const override;

    virtual void set_vertices(const Point2D* vertices);
};

#endif

