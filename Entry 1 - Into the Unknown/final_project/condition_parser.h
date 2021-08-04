#pragma once

#include <memory>
#include <iostream>

#include "node.h"

using std::istream;
using std::shared_ptr;


shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
