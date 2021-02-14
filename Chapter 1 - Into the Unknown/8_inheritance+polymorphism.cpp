#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::shared_ptr;
using std::make_shared;


class Node {
public:
    virtual int Evaluate() const = 0;
};

class Value : public Node {
private:
    const uint8_t _value;
public:
    Value(char digit) : _value(digit - '0') {}
    int Evaluate() const override { return _value; }
};

struct Variable : public Node {
private:
    const int &_x;
public:
    Variable(const int &x) : _x(x) {}
    int Evaluate() const override { return _x; }
};

class Operation : public Node {
private:
    const char _op;
    shared_ptr<const Node> _left, _right;
public:
    const uint8_t precedence;
    Operation(char value) : precedence((value == '*') ? (2) : (1)), _op(value) {}
    int Evaluate() const override {
        if (_op == '*') {
            return _left->Evaluate() * _right->Evaluate();
        }
        else if (_op == '+') {
            return _left->Evaluate() + _right->Evaluate();
        }
        else if (_op == '-') {
            return _left->Evaluate() - _right->Evaluate();
        }
        return 0;
    }
    void SetLeft(shared_ptr<Node> node) { _left = node; }
    void SetRight(shared_ptr<Node> node) { _right = node; }
};

template <class Iterator>
shared_ptr<Node> Parse(Iterator token, Iterator end, const int &x) {
    if (token == end) {
        return make_shared<Value>('0');
    }
    stack<shared_ptr<Node>> values;
    stack<shared_ptr<Operation>> ops;
    auto PopOperations = [&](int precedence) {
        while (!ops.empty() && ops.top()->precedence >= precedence) {
            auto value1 = values.top();
            values.pop();
            auto value2 = values.top();
            values.pop();
            auto op = ops.top();
            ops.pop();
            op->SetRight(value1);
            op->SetLeft(value2);
            values.push(op);
        }
    };
    while (token != end) {
        const auto &value = *token;
        if (value >= '0' && value <= '9') {
            values.push(make_shared<Value>(value));
        }
        else if (value == 'x') {
            values.push(make_shared<Variable>(x));
        }
        else if (value == '*') {
            PopOperations(2);
            ops.push(make_shared<Operation>(value));
        }
        else if (value == '+' || value == '-') {
            PopOperations(1);
            ops.push(make_shared<Operation>(value));
        }
        ++token;
    }
    while (!ops.empty()) {
        PopOperations(0);
    }
    return values.top();
}

int main() {
    string tokens;
    cout << "Enter expression: ";
    getline(cin, tokens);
    int x;
    auto node = Parse(tokens.begin(), tokens.end(), x);
    cout << "Enter x: ";
    while (cin >> x) {
        cout << "Expression value: " << node->Evaluate() << endl;
        cout << "Enter x: ";
    }

    return 0;
}
