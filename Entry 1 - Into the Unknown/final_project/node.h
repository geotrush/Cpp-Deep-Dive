#pragma once

#include <map>
#include <set>

#include "date.h"

using std::string;
using std::shared_ptr;


enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation {
	Or,
	And
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
	virtual ~Node() = default;
};

class EmptyNode : public Node {
public:
	EmptyNode();
	bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
private:
	const Comparison comparison_;
	const Date date_;
public:
	DateComparisonNode(const Comparison& comparison, const Date& date);
	bool Evaluate(const Date& date, const string& event) const override;
};

class EventComparisonNode : public Node {
private:
	const Comparison comparison_;
	const string event_;
public:
	EventComparisonNode(const Comparison& comparison, const string& event);
	bool Evaluate(const Date& date, const string& event) const override;
};

class LogicalOperationNode : public Node {
private:
	const LogicalOperation logical_operation_;
	const shared_ptr<Node> lhs_;
	const shared_ptr<Node> rhs_;
public:
	LogicalOperationNode(const LogicalOperation& logical_operation, const shared_ptr<Node>& lhs, const shared_ptr<Node>& rhs);
	bool Evaluate(const Date& date, const string& event) const override;
};
