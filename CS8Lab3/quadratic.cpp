#include "quadratic.h"
#include <cmath>

//
// Created by justd on 9/5/2023.
//

namespace Lab3_quadratic {
    quadratic::quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    double quadratic::getA() const {
        return a;
    }

    void quadratic::setA(double a) {
        quadratic::a = a;
    }

    double quadratic::getB() const {
        return b;
    }

    void quadratic::setB(double b) {
        quadratic::b = b;
    }

    double quadratic::getC() const {
        return c;
    }

    void quadratic::setC(double c) {
        quadratic::c = c;
    }

    double quadratic::evaluate_y(double x) const {
        return a * x + b * x + c;
    }

    double quadratic::evaluate_x(double y) const {
        double quad = b * b - 4 * a * (c - y);
        if (quad < 0){
            throw runtime_error("There is no real solution");
        }

        double sqrtDiscriminate = sqrt(quad);
        double x1 = (-b + sqrtDiscriminate) / (2 * a);
        double x2 = (-b - sqrtDiscriminate) / (2 * a);

        if(x1 >= 0)
        {
            return x1;
        }else if(x2 >= 0)
        {
            return x2;
        }
        else
        {
            throw runtime_error("There is no real solution");
        }
    }

    quadratic quadratic::operator+(const Lab3_quadratic::quadratic &other) const {
        return quadratic(a + other.a, b + other.b, c + other.c);
    }

    quadratic quadratic::operator*(double scale) const {
        return quadratic(a * scale, b * scale, c * scale);
    }

    ostream& operator<< (ostream& os, const quadratic& q)
    {
        os << q.a << "x^2 + " << q.b << "x + " << q.c;
        return os;
    }

    istream& operator>> (istream& is, quadratic& q)
    {
        is >> q.a >> q.b >> q.c;
        return is;
    }

    quadratic::quadratic() {

    }
}