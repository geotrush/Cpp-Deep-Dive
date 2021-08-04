#include "token.h"
#include "condition_parser.h"

using std::map;
using std::shared_ptr;
using std::logic_error;
using std::make_shared;
using std::istringstream;


template <class Iterator>
shared_ptr<Node> ParseComparison(Iterator& current, Iterator end) {
    if (current == end) {
        throw logic_error("Expected column name: date or event");
    }
    const Token& column = *current;
    if (column.type != TokenType::COLUMN) {
         throw logic_error("Expected column name: date or event");
    }
    ++current;
    if (current == end) {
        throw logic_error("Expected comparison operation");
    }
    const Token& op = *current;
    if (op.type != TokenType::COMPARE_OP) {
        throw logic_error("Expected comparison operation");
    }
    ++current;
    if (current == end) {
        throw logic_error("Expected right value of comparison");
    }
    Comparison cmp;
    if (op.value == '<') {
        cmp = Comparison::Less;
    } 
    else if (op.value == "<=") {
        cmp = Comparison::LessOrEqual;
    } 
    else if (op.value == ">") {
        cmp = Comparison::Greater;
    } 
    else if (op.value == ">=") {
        cmp = Comparison::GreaterOrEqual;
    } 
    else if (op.value == "==") {
        cmp = Comparison::Equal;
    } 
    else if (op.value == "!=") {
        cmp = Comparison::NotEqual;
    } 
    else {
        throw logic_error("Unknown comparison token: " + op.value);
    }
    const string& value = current->value;
    ++current;
    if (column.value == "date") {
        istringstream is(value);
        return make_shared<DateComparisonNode>(cmp, ParseDate(is));
    } 
    else {
        return make_shared<EventComparisonNode>(cmp, value);
    }
}

template <class Iterator>
shared_ptr<Node> ParseExpression(Iterator& current, Iterator end, unsigned precedence) {
    if (current == end) {
        return shared_ptr<Node>();
    }
    shared_ptr<Node> left;
    if (current->type == TokenType::PAREN_LEFT) {
        ++current;
        left = ParseExpression(current, end, 0u);
        if (current == end || current->type != TokenType::PAREN_RIGHT) {
            throw logic_error("Missing right paren");
        }
        ++current;
    }
    else {
        left = ParseComparison(current, end);
    }
    const map<LogicalOperation, unsigned> precedences = {{LogicalOperation::Or, 1}, {LogicalOperation::And, 2}};
    while (current != end && current->type != TokenType::PAREN_RIGHT) {
        if (current->type != TokenType::LOGICAL_OP) {
            throw logic_error("Expected logic operation");
        }
        const auto logical_operation = current->value == "AND" ? LogicalOperation::And : LogicalOperation::Or;
        const auto current_precedence = precedences.at(logical_operation);
        if (current_precedence <= precedence) {
            break;
        }
        ++current;
        left = make_shared<LogicalOperationNode>(logical_operation, left, ParseExpression(current, end, current_precedence));
    }
    return left;
}

shared_ptr<Node> ParseCondition(istream& is) {
    auto tokens = Tokenize(is);
    auto current = tokens.begin();
    auto top_node = ParseExpression(current, tokens.end(), 0u);
    if (!top_node) {
        top_node = make_shared<EmptyNode>();
    }
    if (current != tokens.end()) {
        throw logic_error("Unexpected tokens after condition");
    }
    return top_node;
}
