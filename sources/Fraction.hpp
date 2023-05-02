//
// Created by shani on 20/04/2023.
//

#ifndef FRACTION_A_FRACTION_H
#define FRACTION_A_FRACTION_H

#include <iostream>
using namespace std;
namespace ariel{}

class Fraction {
public:
    Fraction(double a = 0.0, double b = 1.0) : _a(a), _b(b){}

    friend Fraction operator+ (Fraction frac1, Fraction frac2);
    friend Fraction operator- (Fraction frac1, Fraction frac2);
    friend Fraction operator* (Fraction frac1, Fraction frac2);
    friend Fraction operator/ (Fraction frac1, Fraction frac2);
    Fraction& operator++ (int);
    Fraction& operator++ ();
    Fraction& operator-- (int);
    Fraction& operator-- ();
    friend bool operator!= (Fraction frac1, Fraction frac2);
    friend bool operator== (Fraction frac1, Fraction frac2);
    friend bool operator> (Fraction frac1, Fraction frac2);
    friend bool operator>= (Fraction frac1, Fraction frac2);
    friend bool operator< (Fraction frac1, Fraction frac2);
    friend bool operator<= (Fraction frac1, Fraction frac2);
    friend ostream& operator<< (ostream& buff, Fraction frac2);
    friend istream& operator>> (Fraction frac1, istream& buff);

    double getNum() const{return this->_a;}
    double getDen() const{return this->_b;}

private:
    double _a;
    double _b;

};


#endif //FRACTION_A_FRACTION_H
