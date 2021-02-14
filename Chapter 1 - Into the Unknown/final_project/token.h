#pragma once

#include <stdexcept>
#include <sstream>
#include <vector>

using std::string;
using std::vector;
using std::istream;


enum class TokenType {
    DATE,
    EVENT,
    COLUMN,
    LOGICAL_OP,
    COMPARE_OP,
    PAREN_LEFT,
    PAREN_RIGHT,
};

struct Token {
    const string value;
    const TokenType type;
};

vector<Token> Tokenize(istream& cl);
