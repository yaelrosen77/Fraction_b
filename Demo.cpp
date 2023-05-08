/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    // Fraction a(5,3), b(14,21);
    // std::stringstream ss_in("1 2 3 -4");
    // Fraction frac1, frac2;
    // ss_in >> frac1 >> frac2;
    // cout <<frac1<< endl;
    // cout<< frac2<< endl;
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    // // Test arithmetic with large numerator and/or denominator
    Fraction f4(max_int - 100, max_int);
    Fraction f1(max_int, 1);
    Fraction f2(1, max_int);
    Fraction f3(max_int, max_int);

    Fraction f5(max_int - 1, 1);
    Fraction f6(min_int, 1);
    Fraction f7(min_int + 1, 1);

    Fraction f9 = f2*f4;

    // // CHECK_THROWS_AS
    // (f6 + f7, std::overflow_error);

    // // CHECK_THROWS_AS
    // (f1 - f6, std::overflow_error);
    // // CHECK_THROWS_AS
    // (f5 - f7, std::overflow_error);

    // // CHECK_NOTHROW
    // (f5 + Fraction{1, 1});
    // // CHECK_NOTHROW
    // (f7 - Fraction{1, 1});
}
