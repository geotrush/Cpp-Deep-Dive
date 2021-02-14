#include "node.h"

using std::string;
using std::shared_ptr;


EmptyNode::EmptyNode() {}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& comparison, const Date& date) : comparison_(comparison), date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    switch (comparison_) {
	case Comparison::Less:
		return date < date_;
	case Comparison::LessOrEqual:
		return date <= date_;
	case Comparison::Greater:
		return date > date_;
	case Comparison::GreaterOrEqual:
		return date >= date_;
	case Comparison::Equal:
		return date == date_;
	case Comparison::NotEqual:
		return date != date_;
	default:
		return 0;
		break;
	}
}

EventComparisonNode::EventComparisonNode(const Comparison& comparison, const string& event) : comparison_(comparison), event_(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (comparison_) {
	case Comparison::Less:
		return event < event_;
	case Comparison::LessOrEqual:
		return event <= event_;
	case Comparison::Greater:
		return event > event_;
	case Comparison::GreaterOrEqual:
		return event >= event_;
	case Comparison::Equal:
		return event == event_;
	case Comparison::NotEqual:
		return event != event_;
	default:
		return 0;
		break;
	}
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logical_operation,
										   const shared_ptr<Node>& lhs,
										   const shared_ptr<Node>& rhs) : logical_operation_(logical_operation), lhs_(lhs), rhs_(rhs) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	switch (logical_operation_) {
	case LogicalOperation::Or:
		return lhs_->Evaluate(date, event) || rhs_->Evaluate(date, event);
	case LogicalOperation::And:
		return lhs_->Evaluate(date, event) && rhs_->Evaluate(date, event);
	default:
		return 0;
		break;
	}
}
