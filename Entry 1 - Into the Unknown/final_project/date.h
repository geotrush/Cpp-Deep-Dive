#pragma once

#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <memory>
#include <string>

using std::pair;
using std::string;
using std::istream;
using std::ostream;


class Date {
private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int new_year, int new_month, int new_day);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	string DateToStr() const;
};

Date ParseDate(istream& is);

ostream& operator << (ostream& os, const Date& date);
ostream& operator << (ostream& os, const pair<Date, string>& pair);

bool operator < (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
