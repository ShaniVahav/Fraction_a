//
// Created by shani on 02/05/2023.
//
#include "sources/Fraction.hpp"
#include "doctest.h"
#include <stdexcept>
#include <sstream>
using namespace std;

/// Creates a random fraction and return it
Fraction randFrac(){
    double a = rand();
    double b = rand() + 1;  // '+1' to ensure that b is not zero

    return Fraction(a, b);
}

TEST_CASE("Constructor") {
    /// Can't divide by zero
    // each test will execute 100 times with other random fractions
    for (int i = 0; i < 100; i++) {
        double num_rand;
        num_rand = rand();
        CHECK_THROWS(Fraction(num_rand,0));
    }

}

TEST_CASE("+, -, /, *"){
    // each test will execute 100 times with other random fractions
    for (int i = 0; i < 100; i++) {
        // Two random fractions
        Fraction f1 = randFrac();
        Fraction f2 = randFrac();

        SUBCASE("operator+") {
            /// Take two random fractions and check their sum
            double result = (f1.getNum() / f1.getDen()) + (f2.getNum() / f2.getDen());
            CHECK((f1 + f2) == result);
        }

        SUBCASE("operator-") {
            /// Take two random fractions and check their differences
            double result = (f1.getNum() / f1.getDen()) - (f2.getNum() / f2.getDen());
            CHECK((f1 + f2) == result);
        }

        SUBCASE("operator*") {
            /// Take two random fractions and check their multiply
            double result = (f1.getNum() / f1.getDen()) * (f2.getNum() / f2.getDen());
            CHECK((f1 * f2) == result);
        }

        SUBCASE("operator/") {
            /// Take two random fractions and check their division
            double result = (f1.getNum() / f1.getDen()) / (f2.getNum() / f2.getDen());
            CHECK((f1 / f2) == result);
        }
    }  // end for-loop
}

TEST_CASE("++, --"){
    // each test will execute 100 times with other random fractions
    for (int i = 0; i < 100; ++i) {
        Fraction f = randFrac();

        SUBCASE("operator++(int)"){
            f++;
            double result = (f.getNum()/f.getDen()) + 1;
            CHECK(f == result);
        }

        SUBCASE("operator++"){
            double beforeIncrease = (f.getNum()/f.getDen());
            CHECK(++f == beforeIncrease);

            double afterIncrease = (f.getNum()/f.getDen()) + 1;
            CHECK(f == afterIncrease);
        }

        SUBCASE("operator--(int)"){
            f--;
            double result = (f.getNum()/f.getDen()) - 1;
            CHECK(f == result);
        }

        SUBCASE("operator--"){
            double beforeDecrease = (f.getNum()/f.getDen());
            CHECK(--f == beforeDecrease);

            double afterDecrease = (f.getNum()/f.getDen()) - 1;
            CHECK(f == afterDecrease);
        }
    }  // end fol-loop

}

TEST_CASE("!=, ==, >, >=, <, <="){
    // each test will execute 100 times with other random fractions
    for (int i = 0; i < 100; ++i) {
        // two random fractions
        Fraction f1 = randFrac();
        Fraction f2 = randFrac();

        if(f1.getNum() == f2.getNum() && f1.getDen() == f2.getDen()){
            // they are equals
            CHECK(f1 == f2);
            CHECK(f1 >= f2);
            CHECK(f1 <= f2);
        }
        else{
            // they are different
            CHECK(f1 != f2);
        }

        double num1 = f1.getNum()/f1.getDen();
        double num2 = f2.getNum()/f2.getDen();

        if(num1 > num2){
            CHECK(f1 > f2);
            CHECK(f1 != f2);
        }
        else{
            CHECK(f1 < f2);
            CHECK(f1 != f2);
        }

    }  // end for-loop
}

TEST_CASE("streaming"){
    for (int i = 0; i < 20; ++i) {
        // random fraction
        Fraction f = randFrac();

        SUBCASE("operator<<"){
            ostringstream buff;
            buff << f;
            string out = to_string(f.getNum()) + "/" + to_string(f.getDen());
            CHECK(buff.str() == out);
        }

        SUBCASE("operator>>"){
            istringstream buff;
            f >> buff;
            string out = to_string(f.getNum()) + "/" + to_string(f.getDen());
            CHECK(buff.str() == out);
        }

    }
}