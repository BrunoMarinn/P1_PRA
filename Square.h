#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square(const Point2D* vertices, const std::string& col = "red");

    void set_vertices(const Point2D* vertices) override;
    void print(std::ostream& os) const override;
};

#endif

