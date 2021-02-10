/*
Task
You should write tests for the previous Chapter's function in ex2_0_quadratic_equation.cpp
using the unit-testing framework defined in 4_unit_test_framework.cpp.
*/
#include "4+5_unit_test_framework.h"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cassert>
#include <random>
#include <string>
#include <cmath>
#include <map>
#include <set>

using std::pow;
using std::cout;
using std::cerr;
using std::endl;
using std::showpos;
using std::map;
using std::set;
using std::string;
using std::mt19937;
using std::ostream;
using std::stringstream;
using std::ostringstream;
using std::runtime_error;
using std::uniform_real_distribution;


int GetDistinctRealRootCount(double a, double b, double c) {
    double D = pow(b, 2) - 4 * a * c;
    if (a == 0) {
        if (b != 0) {
            cout << -c / b << endl;
            return 1;
        }
    }
    else if (D == 0) {
        cout << -b / (2 * a) << endl;
        return 1;
    }
    else if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << x1 << ' ' << x2 << endl;
        return 2;
    }
    return 0;
}

// Unit tests
void TestRootCount() {
	mt19937 gen;
	uniform_real_distribution<> uniform(-10, 10);
	for (auto i = 0; i < 100; ++i) {
		const auto a = uniform(gen);
		const auto b = uniform(gen);
		const auto c = uniform(gen);
		const auto count = GetDistinctRealRootCount(a, b, c);
		Assert(count >= 0 && count <= 2, "Quadratic equation must either have 0, 1 or 2 real roots.");
	}
}
void TestNoRoots() {
	AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "x^2+1 = 0 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(1, 3, 4), 0, "x^2+3x+4 = 0 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(1, -2, 10), 0, "x^2-2x+10 = 0 has 0 real roots.");
}
void TestConstant() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "a = b = 0, where c = 1 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(0, 0, -10), 0, "a = b = 0, where c = -10 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(0, 0, 189238910), 0, "a = b = 0, where c = 189238910 has 0 real roots.");
}
void TestZeroDiscriminant() {
    AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1, "x^2+2x+1 = 0 has 1 distinct root.");
    AssertEqual(GetDistinctRealRootCount(2, 4, 2), 1, "2x^2+4x+2 = 0 has 1 distinct root.");
    AssertEqual(GetDistinctRealRootCount(16, 8, 1), 1, "16x^2+8x+1 = 0 has 1 distinct root.");
}
void TestLinearEquation() {
	AssertEqual(GetDistinctRealRootCount(0, 2, 1), 1, "2x+1 = 0 has 1 real root.");
	AssertEqual(GetDistinctRealRootCount(0, -1, 0), 1, "-x = 0 has 1 real root.");
	AssertEqual(GetDistinctRealRootCount(0, 120, -10), 1, "120x - 10 = 0 has 1 real root.");
}


int main() {
	TestRunner runner;
	runner.RunTest(TestRootCount, "TestRootCount");
	runner.RunTest(TestNoRoots, "TestNoRoots");
	runner.RunTest(TestConstant, "TestConstant");
    runner.RunTest(TestZeroDiscriminant, "TestOneRoot");
	runner.RunTest(TestLinearEquation, "TestLinearEquation");

	return 0;
}
