/*
Task
You should write a fraction calculator program, based on the ex8_0_fractions.cpp, that:
1) Implements arithmetic operations ('+', '-', '*', '/');
2) Catches exceptions ("Zero denominator", "Division by zero").
*/
#include <iostream>
#include <exception>

using std::cin;
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

bool operator == (const Rational& left, const Rational& right) {
    return left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator();
}

Rational operator + (const Rational& left, const Rational& right) {
	if (left.Denominator() == right.Denominator()) {
		return {left.Numerator() + right.Numerator(), left.Denominator()};
	}
	else {
		return {left.Numerator() * right.Denominator() + right.Numerator() * left.Denominator(),
				left.Denominator() * right.Denominator()};
	}
}

Rational operator - (const Rational& left, const Rational& right) {
	return left + Rational(-right.Numerator(), right.Denominator());
}

bool operator < (const Rational& left, const Rational& right) {
	return (left - right).Numerator() < 0;
}

Rational operator * (const Rational& left, const Rational& right) {
	return {left.Numerator() * right.Numerator(),
			left.Denominator() * right.Denominator()};
}

Rational operator / (const Rational& left, const Rational& right) {
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

int main() {
	Rational fraction_1, fraction_2;
	char operation;

	try {
		cin >> fraction_1 >> operation >> fraction_2;

		if (operation == '+') {
			cout << fraction_1 + fraction_2 << endl;
		}
		else if (operation == '-') {
			cout << fraction_1 - fraction_2 << endl;
		}
		else if (operation == '*') {
			cout << fraction_1 * fraction_2 << endl;
		}
		else if (operation == '/') {
			try {
				cout << fraction_1 / fraction_2 << endl;
			}
			catch (domain_error& domain_error) {
				cout << domain_error.what();
			}
		}
	}
	catch (const invalid_argument& invalid_argument) {
		cout << invalid_argument.what();
	}

	return 0;
}
