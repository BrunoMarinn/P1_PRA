#include "Drawing.h"

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    for (int i = 0; i < shapes->size(); ++i) {
        delete shapes->get(i);
    }
    delete shapes;
}

void Drawing::add_front(Shape* s) {
    shapes->prepend(s);
}

void Drawing::add_back(Shape* s) {
    shapes->append(s);
}

void Drawing::print_all(std::ostream& os) const {
    os << "Drawing: " << shapes->size() << " shapes" << std::endl;
    for (int i = 0; i < shapes->size(); ++i) {
        os << i << ": " << *(shapes->get(i)) << std::endl;
    }
}

double Drawing::get_area_all_circles() const {
    double sum = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        if (c) sum += c->area();
    }
    return sum;
}

void Drawing::move_squares(double dx, double dy) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* s = dynamic_cast<Square*>(shapes->get(i));
        if (s) s->translate(dx, dy);
    }
}

