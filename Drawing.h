#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "List.h"
#include "ListArray.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"

class Drawing {
private:
    List<Shape*>* shapes;

public:
    Drawing();
    ~Drawing();

    void add_front(Shape* s);
    void add_back(Shape* s);

    void print_all(std::ostream& os) const;

    double get_area_all_circles() const;
    void move_squares(double dx, double dy);
};

#endif

