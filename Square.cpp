#include "Square.h"
#include <stdexcept>

Square::Square(const Point2D* vertices, const std::string& col)
    : Rectangle(vertices, col) {}

void Square::set_vertices(const Point2D* vertices) {
    Rectangle::set_vertices(vertices);
}

void Square::print(std::ostream& os) const {
    os << "Square(";
    for (int i = 0; i < N_VERTICES; ++i) {
        os << vs[i];
        if (i != N_VERTICES - 1) os << ", ";
    }
    os << ", color=" << color << ")";
}

