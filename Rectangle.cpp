#include "Rectangle.h"
#include <stdexcept>

void Rectangle::check(const Point2D* vertices) const {
    if (!vertices)
        throw std::invalid_argument("null vertices");
}

Rectangle::Rectangle(const Point2D* vertices, const std::string& col)
    : Shape(col), vs(new Point2D[N_VERTICES]) {
    check(vertices);
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle& other)
    : Shape(other.color), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = other.vs[i];
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        color = other.color;
        for (int i = 0; i < N_VERTICES; ++i)
            vs[i] = other.vs[i];
    }
    return *this;
}

Rectangle::~Rectangle() {
    delete[] vs;
}

void Rectangle::set_vertices(const Point2D* vertices) {
    check(vertices);
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

double Rectangle::area() const {
    double w = Point2D::distance(vs[0], vs[1]);
    double h = Point2D::distance(vs[1], vs[2]);
    return w * h;
}

double Rectangle::perimeter() const {
    double w = Point2D::distance(vs[0], vs[1]);
    double h = Point2D::distance(vs[1], vs[2]);
    return 2 * (w + h);
}

void Rectangle::translate(double dx, double dy) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += dx;
        vs[i].y += dy;
    }
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle(";
    for (int i = 0; i < N_VERTICES; ++i) {
        os << vs[i];
        if (i != N_VERTICES - 1) os << ", ";
    }
    os << ", color=" << color << ")";
}

