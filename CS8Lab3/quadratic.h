//
// Created by justd on 9/5/2023.
//

#ifndef CS8LAB3_QUADRATIC_H
#define CS8LAB3_QUADRATIC_H
#include <iostream>
using namespace std;

namespace Lab3_quadratic {
    class quadratic {
    private:
        double a, b, c;
    public:
        quadratic();

        quadratic(double a, double b, double c);

        double evaluate_y(double x) const;

        double evaluate_x(double y) const;

        double getA() const;

        void setA(double a);

        double getB() const;

        void setB(double b);

        double getC() const;

        void setC(double c);

        quadratic operator+(const quadratic& other) const;
        quadratic operator*(double scale) const;

        friend ostream& operator<<(ostream& os, const quadratic& q);
        friend istream& operator>>(istream& is, quadratic& q);

    };
}
#endif //CS8LAB3_QUADRATIC_H
