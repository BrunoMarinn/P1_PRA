#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include <iostream>

class Shape {
protected:
    std::string color;

    void check_color(const std::string& c) {
        if (c != "red" && c != "green" && c != "blue")
            throw std::invalid_argument("invalid color");
    }

public:
    Shape() : color("red") {}

    explicit Shape(const std::string& c) {
        check_color(c);
        color = c;
    }

    virtual ~Shape() = default;

    std::string get_color() const {
        return color;
    }

    void set_color(const std::string& c) {
        check_color(c);
        color = c;
    }

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double dx, double dy) = 0;
    virtual void print(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Shape& s) {
    s.print(os);
    return os;
}

#endif

