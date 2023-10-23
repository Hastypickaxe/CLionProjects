#include <iostream>
#include "quadratic.h"

using namespace std;
//using namespace Lab3_quadratic;
int main() {
    try {
        Lab3_quadratic::quadratic q1, q2;

        cout << "Enter coefficients for first quadratic expression" << endl;
        cin >> q1;

        cout << "Enter coefficients for second quadratic expression" << endl;
        cin >> q2;

        cout << "First coefficient: " << q1 << endl;
        cout << "Second  coefficient: " << q2 << endl;

        double x, y;
        cout << "Enter your x: " << endl;
        cin >> x;
        cout << "Enter your y: " << endl;
        cin >> y;

        cout << "Evaluating your first expression at x = " << x << ": " << q1.evaluate_x(x) << endl;
        cout << "Evaluating your second expression at x = " << x << ": " << q2.evaluate_y(x) << endl;

        cout << "Find x for first expression at y = " << y << ": ";
        double x1 = q1.evaluate_x(y);
        cout << x1 << endl;

        cout << "Finding x for second expression at y = " << y << ": ";
        double x2 = q2.evaluate_x(y);
        cout << x2 << endl;

        Lab3_quadratic::quadratic sum = q1 + q2;
        Lab3_quadratic::quadratic scaled = q1 * 2.5;

        cout << "Sum of the two expressions: " << sum << endl;
        cout << "Scaled expression: " << scaled << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

