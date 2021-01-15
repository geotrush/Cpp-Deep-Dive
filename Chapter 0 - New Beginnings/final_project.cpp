/*
Task
You should define a class with the five public methods:
1) "AddEvent(date, event)": records the event at the date (duplicate events are ignored);
2) "DeleteEvent(date, event)":
    a) If the event was recorded, erases it and outputs "Deleted successfully";
    b) If the event wasn't recorded, outputs "Event not found";
3) "DeleteDate(date)": erases all n events at the date and always outputs "Deleted n events";
4) "FindDate(date)": outputs one per line all of the events at the date sorted in acsending order;
5) "PrintDatabase()": outputs one per line all of the date-event pairs sorted by date and by events in acsending order.
You should catch the following exceptions:
1) "Unknown command: COMMAND": if the COMMAND (first input string) wasn't recognised;
2) "Wrong date format: DATE": if the DATE (second input string) doesn't comply with the formatting:
    a) "YEAR-MONTH-DAY": valid format can contain '+' or '-' signs before the integers;
    b) If MONTH is not between 1 and 12, output "Month value is invalid: MONTH";
    c) If DAY is not between 1 and 31, output "Day value is invalid: DAY";
Notes:
1) All months have 31 days; 
2) If MONTH has invalid formatting, don't check the day;
3) You don't have to check the year formatting.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::to_string;
using std::istream;
using std::stringstream;
using std::string;
using std::map;
using std::set;
using std::exception;
using std::logic_error;

class Date {
public:
	Date() {
        year = 1970;
        month = 1;
        day = 1;
    }
	Date(int new_year, int new_month, int new_day) {
		if (new_month > 12 || new_month < 1) {
			throw logic_error("Month value is invalid: " + to_string(new_month));
		}
		else {
			month = new_month;
		}
		
		if (new_day > 31 || new_day < 1) {
			throw logic_error("Day value is invalid: " + to_string(new_day));
		}
		else {
			day = new_day;
		}
		year = new_year;
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int year;
	int month;
	int day;
};

istream& operator >> (istream& input, Date& date) {
	string str_date;
	input >> str_date;

	stringstream date_stream(str_date);

	int year;
	date_stream >> year;
	if (date_stream.fail() || date_stream.peek() != '-') {
		throw logic_error("Wrong date format: " + str_date);
	}
	date_stream.ignore();

	int month;
	date_stream >> month;
	if (date_stream.fail() || date_stream.peek() != '-' ) {
		throw logic_error("Wrong date format: " + str_date);
	}
	date_stream.ignore();

	int day;
	date_stream >> day;
	if (date_stream.fail() || !date_stream.eof()) {
		throw logic_error("Wrong date format: " + str_date);
	}

	date = Date(year, month, day);
	return input;
}

bool operator < (const Date& left, const Date& right) {
	if (left.GetYear() == right.GetYear()) {
		if (left.GetMonth() == right.GetMonth()) {
			return left.GetDay() < right.GetDay();
		}
		return left.GetMonth() < right.GetMonth();
	}
	return left.GetYear() < right.GetYear();
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		database[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (database.count(date) && database[date].count(event)) {
			database[date].erase(event);
			return true;
		}
		return false;
	}
	int DeleteDate(const Date& date) {
		const int count = database[date].size();
		if (count) {
			database.erase(date);
		}
		return count;
	}
	set<string> FindDate(const Date& date) const {
		if (database.count(date)) {
			return database.at(date);
		}
		return {};
	}
	void PrintDatabase() const {
		for (const auto& item : database) {
			for (const auto& event : item.second) {
				cout << setw(4) << setfill('0') << item.first.GetYear()  << '-'
				     << setw(2) << setfill('0') << item.first.GetMonth() << '-'
				     << setw(2) << setfill('0') << item.first.GetDay()   << ' '
                     << event   << endl;
			}
		}
	}
private:
	map<Date, set<string>> database;
};

int main() {
	try {
		Database database;

		string command;
		while (getline(cin, command)) {
			stringstream command_stream(command);
			string operation;
			command_stream >> operation;

			if (operation == "Add") {
				Date date;
                string event;
				command_stream >> date >> event;
				database.AddEvent(date, event);
			}
			else if (operation == "Del") {
				Date date;
				command_stream >> date;

				if (!command_stream.eof()) {
					string event;
					command_stream >> event;

					if (database.DeleteEvent(date, event)) {
						cout << "Deleted successfully\n";
					}
					else {
						cout << "Event not found\n";
					}
				}
				else {
					const int count = database.DeleteDate(date);
					cout << "Deleted " << count << " events\n";
				}
			}
			else if (operation == "Find") {
				Date date;
				command_stream >> date;

				for (const auto& event : database.FindDate(date)) {
					cout << event << endl;
				}
			}
			else if (operation == "Print") {
				database.PrintDatabase();
			}
			else if (operation.empty()) {
                // Ignore
			}
			else {
				throw logic_error("Unknown command: " + operation);
			}
		}
	}
	catch (const exception& exception) {
		cout << exception.what();
	}
    
	return 0;
}
