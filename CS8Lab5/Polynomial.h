//
// Created by justd on 9/12/2023.
//

#ifndef CS8LAB5_POLYNOMIAL_H
#define CS8LAB5_POLYNOMIAL_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

class polynomial
{
public:
// You may add more member functions including constructors.
    polynomial();
// POSTCONDITION: This polynomial has been created with all zero coefficients.
    polynomial(const polynomial& source);

    polynomial(int degree, double *coef);

    // copy constructor
    ~polynomial(); // destructor
// ASSIGNMENT OPERATOR
    polynomial& operator =(const polynomial& source);
// CONSTANT MEMBER FUNCTIONS
    double getOneCoef(unsigned int exponent) const;
// POSTCONDITION: Returns coefficient at specified exponent of this polynomial.
    double* getCoefficient() const;
    int getDegree() const;
    double evaluate(double x) const;
    polynomial integral() const;
// POSTCONDITION: The return value is the integral of this polynomial.
    polynomial derivative () const;

    void setDegree(int degree);

//    double *getCoef() const;

//    void setCoef(double *coef);

    // POSTCONDITION: The return value is the derivative of this polynomial.

    // NON-MEMBER BINARY OPERATORS
    friend polynomial operator +(const polynomial& p1, const polynomial& p2);
    friend polynomial operator *(const polynomial& p1, const polynomial& p2);

// NON-MEMBER INPUT/OUTPUT FUNCTIONS
    friend istream & operator >> (istream& in, polynomial& p);
    friend ostream & operator << (ostream& out, const polynomial& p);


private:
    int degree;
    double* coef;
};

#endif //CS8LAB5_POLYNOMIAL_H
