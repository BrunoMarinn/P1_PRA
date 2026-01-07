#include <iostream>
#include "Drawing.h"
#include "Rectangle.h"

int main() {
    Drawing d;

    Circle* c = new Circle(Point2D(0,0), 2.0, "blue");
    d.add_back(c);

    Point2D rvs[4] = { {0,0}, {4,0}, {4,2}, {0,2} };
    Rectangle* r = new Rectangle(rvs, "green");
    d.add_back(r);

    Point2D svs[4] = { {0,0}, {2,0}, {2,2}, {0,2} };
    Square* s = new Square(svs, "red");
    d.add_back(s);

    d.print_all(std::cout);
    std::cout << "Area total circulos: " << d.get_area_all_circles() << std::endl;

    d.move_squares(1, 1);
    d.print_all(std::cout);

    return 0;
}

