/*
Task
You should write tests for the previous Chapter's class in ex8_0_fraction.cpp
using the unit-testing framework from 4+5_unit_test_framework.cpp.
*/
#include "4+5_unit_test_framework.h"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>

using std::cerr;
using std::endl;
using std::showpos;
using std::map;
using std::set;
using std::string;
using std::ostream;
using std::ostringstream;
using std::runtime_error;
using std::invalid_argument;


class Rational {
public:
    Rational() : p(0), q(1) {};
    Rational(const int& numerator, const int& denominator) {
        if (denominator == 0) {
            throw invalid_argument("Zero denominator!");
        }
        const int greatest_common_divisor = gcd(numerator, denominator);
        p = numerator / greatest_common_divisor;
        q = denominator / greatest_common_divisor;
        if (q < 0) {
            p = -p;
            q = -q;
        }
    }
    int Numerator() const {
        return p;
    }
    int Denominator() const {
        return q;
    }
    int gcd(const int& a, const int& b) const {
        if (b == 0) {
            return a;
        }
        else {
            return gcd(b, a % b);
        }
    }
private:
    int p;
    int q;
};

// Unit tests
void TestDefaultConstructor() {
    AssertEqual(Rational().Numerator(), 0, "Default numerator = 0");
    AssertEqual(Rational().Denominator(), 1, "Default denominator = 1");
}
void TestIrreducibleFraction() {
    AssertEqual(Rational(1, 1).Numerator(), 1, "1/1 = 1/1");
    AssertEqual(Rational(1, 1).Denominator(), 1, "1/1 = 1/1");
    AssertEqual(Rational(2, 3).Numerator(), 2, "2/3 = 2/3");
    AssertEqual(Rational(2, 3).Denominator(), 3, "2/3 = 2/3");
}
void TestReducibleFraction() {
    AssertEqual(Rational(7, 14).Numerator(), 1, "7/14 = 1/2");
    AssertEqual(Rational(7, 14).Denominator(), 2, "7/14 = 1/2");
    AssertEqual(Rational(2, 22).Numerator(), 1, "2/22 = 1/11");
    AssertEqual(Rational(2, 22).Denominator(), 11, "2/22 = 1/11");
}
void TestZeroNumerator() {
    AssertEqual(Rational(0, 42).Numerator(), 0, "0/42 = 0/42");
    AssertEqual(Rational(0, 42).Denominator(), 1, "0/42 = 0/42");
}
void TestNegativeNumerator() {
    AssertEqual(Rational(-8, 42).Numerator(), -4, "-8/42 = -4/21");
    AssertEqual(Rational(-8, 42).Denominator(), 21, "-8/42 = -4/21");
}
void TestNegativeDenominator() {
    AssertEqual(Rational(6, -12).Numerator(), -1, "6/-12 = -1/2");
    AssertEqual(Rational(6, -12).Denominator(), 2, "-6/-12 = -1/2");
}
void TestBothNegative() {
    AssertEqual(Rational(-2, -3).Numerator(), 2, "-2/-3 = 2/3");
    AssertEqual(Rational(-2, -3).Denominator(), 3, "-2/-3 = 2/3");
    AssertEqual(Rational(-3, -4).Numerator(), 3, "-3/-4 = 3/4");
    AssertEqual(Rational(-3, -4).Denominator(), 4, "-3/-4 = 3/4");
}


int main() {
    TestRunner runner;
    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    runner.RunTest(TestIrreducibleFraction, "TestIrreducibleFraction");
    runner.RunTest(TestReducibleFraction, "TestReducibleFraction");
    runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
    runner.RunTest(TestNegativeNumerator, "TestNegativeNumerator");
    runner.RunTest(TestNegativeDenominator, "TestNegativeDenominator");
    runner.RunTest(TestBothNegative, "TestBothNegative");

    return 0;
}
