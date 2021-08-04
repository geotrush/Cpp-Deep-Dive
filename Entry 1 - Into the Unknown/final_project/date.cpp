#include "date.h"

using std::setw;
using std::setfill;
using std::to_string;
using std::make_tuple;
using std::pair;
using std::string;
using std::istream;
using std::ostream;
using std::logic_error;
using std::stringstream;


Date::Date() : year(0), month(0), day(0) {}

Date::Date(int new_year, int new_month, int new_day) {
	if (new_month < 1 || new_month > 12) {
		string error = "Month value is invalid: " + to_string(new_month);
		throw logic_error(error);
	}
	else {
		month = new_month;
	}
	if (new_day < 1 || new_day > 31) {
		string error = "Day value is invalid: " + to_string(new_day);
		throw logic_error(error);
	}
	else {
		day = new_day;
	}
	year = new_year;
}

int Date::GetYear() const {
	return year;
}

int Date::GetMonth() const {
	return month;
}

int Date::GetDay() const {
	return day;
}

string Date::DateToStr() const {
	stringstream ss;
	ss << *this;
	return ss.str();
}

Date ParseDate(istream& is) {
    string date;
    is >> date;
    stringstream date_stream(date);

    int year;
    date_stream >> year;
    if (date_stream.fail() || date_stream.peek() != '-') {
        throw logic_error("Wrong date format: " + date);
    }
    date_stream.ignore();

    int month;
    date_stream >> month;
    if (date_stream.fail() || date_stream.peek() != '-') {
        throw logic_error("Wrong date format: " + date);
    }
    date_stream.ignore();

    int day;
    date_stream >> day;
    if (date_stream.fail() || !date_stream.eof()) {
        throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

ostream& operator << (ostream& os, const Date& date) {
	os << setw(4) << setfill('0') << date.GetYear() << '-';
	os << setw(2) << setfill('0') << date.GetMonth() << '-';
	os << setw(2) << setfill('0') << date.GetDay();
	return os;
}

ostream& operator << (ostream& os, const pair<Date, string>& pair) {
	os << pair.first << ' ' << pair.second;
	return os;
}

bool operator < (const Date& lhs, const Date& rhs) {
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) < 
		   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator <= (const Date& lhs, const Date& rhs) {
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <= 
		   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator > (const Date& lhs, const Date& rhs) {
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >
		   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator >= (const Date& lhs, const Date& rhs) {
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >= 
		   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator == (const Date& lhs, const Date& rhs) {
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) ==
		   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator != (const Date& lhs, const Date& rhs) {	
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) != 
		   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
