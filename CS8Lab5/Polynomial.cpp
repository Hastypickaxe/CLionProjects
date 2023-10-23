//
// Created by justd on 9/12/2023.
//

#include "Polynomial.h"

polynomial::polynomial() {
    coef = new double[1];
}

polynomial::polynomial(int degree, double *coef) : degree(degree), coef(coef) {}

void polynomial::setDegree(int degree) {
    this->degree = degree;
}

// copy constructor

polynomial::polynomial(const polynomial &source) {
    degree = source.degree;
    for(int i = 0; i < degree; i++)
    {
        coef[i] = source.coef[i];
    }
}

polynomial::~polynomial() {
    delete[] coef;
}

// ASSIGNMENT OPERATOR
polynomial& polynomial::operator =(const polynomial& source){
    degree = source.degree;
    for(int i = 0; i < degree; i++)
    {
        coef[i] = source.coef[i];
    }
}
// CONSTANT MEMBER FUNCTIONS
double polynomial::getOneCoef(unsigned int exponent) const{
    return coef[exponent];
}
// POSTCONDITION: Returns coefficient at specified exponent of this polynomial.
double* polynomial::getCoefficient() const {
    return coef;
}
int polynomial::getDegree() const {
    return degree;
}
double polynomial::evaluate(double x) const{

}

polynomial polynomial::integral() const {
    double* intergral = new double[degree + 1];
    double temp = 0;
    for(int i = 0; i < degree; i++){
        temp = (coef[i] / (i + 1));
        intergral[i + 1] = temp;
    }
}
// POSTCONDITION: The return value is the integral of this polynomial.
polynomial polynomial::derivative() const {

}

// NON-MEMBER BINARY OPERATORS
polynomial operator +(const polynomial& p1, const polynomial& p2) {
    // might have to check if garbage value.

    if (p1.getDegree() == p2.getDegree()) {
        polynomial newSum;

        double sum = *p1.getCoefficient() + *p2.getCoefficient();
        newSum.setDegree(p1.getDegree());
        *newSum.getCoefficient() = sum;

        return newSum;
    } else if(p1.getDegree() > p2.getDegree()){
//        newSum.setDegree();
        double* coef = new double[p1.getDegree()];

        for(int i = 0; i < p1.getDegree(); i++)
        {
            coef[i] = 0;
        }

        coef[p1.getDegree() == *p1.getCoefficient()];

        for(int i = 0; i < p2.getDegree(); i++)
        {
            coef[i] = 0;
        }

        coef[p2.getDegree() == *p2.getCoefficient()];

        polynomial newSum;
    }



//    p1.coef[p2.getDegree()]
}
polynomial operator *(const polynomial& p1, const polynomial& p2){

}


//// NON-MEMBER INPUT/OUTPUT FUNCTIONS
istream &operator>>(istream &in, polynomial &p) {
    return in;
}

ostream &operator<<(ostream &out, const polynomial &p) {
    return out;
}
