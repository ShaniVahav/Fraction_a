//
// Created by shani on 20/04/2023.
//

#include "Fraction.hpp"
Fraction f();

Fraction operator+ (Fraction frac1, Fraction frac2){return Fraction();}
Fraction operator- (Fraction frac1, Fraction frac2){return Fraction();}
Fraction operator* (Fraction frac1, Fraction frac2){return Fraction();}
Fraction operator/ (Fraction frac1, Fraction frac2){return Fraction();}
Fraction& Fraction::operator++ (int){return *this;}
Fraction& Fraction::operator++ (){return *this;};
Fraction& Fraction::operator-- (int){return *this;}
Fraction& Fraction::operator-- (){return *this;}
bool operator!= (Fraction frac1, Fraction frac2){return false;}
bool operator== (Fraction frac1, Fraction frac2){return false;}
bool operator> (Fraction frac1, Fraction frac2){return false;}
bool operator>= (Fraction frac1, Fraction frac2){return false;}
bool operator< (Fraction frac1, Fraction frac2){return false;}
bool operator<= (Fraction frac1, Fraction frac2){return false;}
ostream& operator<< (ostream& buff, Fraction frac2){return buff;}
istream& operator>> (Fraction frac1, istream& buff){return buff;}
