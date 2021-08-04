/*
Task
You should write a database that supports the following commands:
1) "Add date event": adds a date-event pair;
2) "Print": output the whole database;
3) "Find condition": output the records that satisfy the condition;
4) "Del condition": remove the records that satisfy the condition;
5) "Last date": output the event record that happened at or before the date.
Notes:
1) Find and Del commands can have empty condition strings; 
2) Find and Del commands can use any comparison operators.
*/
#include "date.h"
#include "node.h"
#include "database.h"
#include "condition_parser.h"
#include "../4+5_unit_test_framework.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::logic_error;
using std::istringstream;
using std::invalid_argument;


string ParseEvent(istream& is) {
    string event;
    getline(is, event);
    return string(find_if(event.begin(), event.end(), [](const unsigned char& c) {
        return !isspace(c);
    }), event.end());
}

void TestParseEvent() {
    {
        istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
    }
    {
        istringstream is("   sport event ");
        AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
    }
    {
        istringstream is("  first event  \n  second event");
        vector<string> events;
        events.push_back(ParseEvent(is));
        events.push_back(ParseEvent(is));
        AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
    }
}

void TestAll() {
    TestRunner runner;
    runner.RunTest(TestParseEvent, "TestParseEvent");
    runner.RunTest(TestParseCondition, "TestParseCondition");
}


int main() {
    Database db;

    for (string line; getline(cin, line); ) {
        istringstream is(line);
        string command;
        is >> command;
        if (command == "Add") {
            const auto date = ParseDate(is);
            const auto event = ParseEvent(is);
            db.Add(date, event);
        }
        else if (command == "Print") {
            db.Print(cout);
        }
        else if (command == "Del") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };
            int count = db.RemoveIf(predicate);
            cout << "Removed " << count << " entries" << endl;
        }
        else if (command == "Find") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };
            const auto entries = db.FindIf(predicate);
            for (const auto& entry : entries) {
                cout << entry << endl;
            }
            cout << "Found " << entries.size() << " entries" << endl;
        }
        else if (command == "Last") {
            try {
                cout << db.Last(ParseDate(is)) << endl;
            }
            catch (invalid_argument&) {
                cout << "No entries" << endl;
            }
        }
        else if (command.empty()) {
            continue;
        }
        else {
            throw logic_error("Unknown command: " + command);
        }
    }

    return 0;
}
