/*
Task
You should define a class with the three public methods:
1) "AddPart(operation, value)": stores an operation to add/subtract the value or multiply/divide by the value;
2) "Apply(value)": applies all of the stored operations to the value sequentially;
3) "Invert()": inverts the order as well as the sign of the stored operations.
*/
#include <algorithm>
#include <vector>

using std::vector;

class FunctionPart {
public:
	FunctionPart(const char& new_operation, const double& new_value) {
		operation = new_operation;
        value = new_value;
    }
	double Apply(const double& source_value) const {
		if (operation == '+') {
			return source_value + value;
		}
		else if (operation == '-') {
			return source_value - value;
		}
		else if (operation == '*') {
			return source_value * value;
		}
		else if (operation == '/') {
			return source_value / value;
		}
	}
	void Invert() {
		if (operation == '+') {
			operation = '-';
		}
		else if (operation == '-') {
			operation = '+';
		}
		else if (operation == '*') {
			operation = '/';
		}
		else if (operation == '/') {
			operation = '*';
		}
	}
private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(const char operation, const double value) {
		parts.push_back({operation, value});
	}
	double Apply(double value) const {
		for (const FunctionPart& part : parts) {
			value = part.Apply(value);
		}
		return value;
	}
	void Invert() {
		for (FunctionPart& part : parts) {
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	}
private:
	vector<FunctionPart> parts;
};
