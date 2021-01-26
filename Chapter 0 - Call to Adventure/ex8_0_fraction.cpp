/*
Task
You should define a class with the default& custom constructos:
1) "Rational()": creates the default fraction p/q where p = 0, q = 1;
2) "Rational(numerator, denominator)": creates a fraction p/q where p is integer, q is natural;
You should also define the following class operators:
1) Relational ("==", '<');
2) Arithmetic ('+', '-', '*', '/');
3) IO Stream (">>", "<<").
Task for 8_2_exceptions.cpp
You should also throw the following exceptions:
1) "invalid argument": if the denominator equals zero;
2) "domain error": if the divisor is equal to zero.
*/
#include <iostream>
#include <exception>

using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::domain_error;
using std::invalid_argument;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }
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

const bool operator == (const Rational& left, const Rational& right) {
    return left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator();
}

const Rational operator + (const Rational& left, const Rational& right) {
    if (left.Denominator() == right.Denominator()) {
        return {left.Numerator() + right.Numerator(), left.Denominator()};
    }
    else {
        return {left.Numerator() * right.Denominator() + right.Numerator() * left.Denominator(),
                left.Denominator() * right.Denominator()};
    }
}

const Rational operator - (const Rational& left, const Rational& right) {
    return left + Rational(-right.Numerator(), right.Denominator());
}

const bool operator < (const Rational& left, const Rational& right) {
    return (left - right).Numerator() < 0;
}

const Rational operator * (const Rational& left, const Rational& right) {
    return {left.Numerator() * right.Numerator(),
            left.Denominator() * right.Denominator()};
}

const Rational operator / (const Rational& left, const Rational& right) {
    if (right.Numerator() == 0) {
        throw domain_error("Division by zero!");
    }
    return left * Rational(right.Denominator(), right.Numerator());
}

istream& operator >> (istream& input, Rational& fraction) {
    int p, q;
    if (input >> p && input.ignore(1) && input >> q) {
        fraction = Rational(p, q);
    }
    return input;
}

ostream& operator << (ostream& output, const Rational& fraction) {
    return output << fraction.Numerator() << '/' << fraction.Denominator();
}
