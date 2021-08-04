/*
Task
You should define class methods that were declared in the header file ex5_0_sum_reverse_sort.h
*/
#include "ex5_1_phone_number.h"
#include <sstream>

using std::getline;
using std::istringstream;
using std::invalid_argument;


PhoneNumber::PhoneNumber(const string& international_number) {
	istringstream in_string(international_number);
	const char sign = in_string.get();
	if (in_string) {
		getline(in_string, country_code, '-');
		getline(in_string, city_code, '-');
		getline(in_string, local_number, '\n');
	}
	if (sign != '+' || country_code.empty()) {
		throw invalid_argument("The country code must begin with a + sign and be at least one character");
	}
	if (city_code.empty()) {
		throw invalid_argument("Area code cannot be empty");
	}
	if (local_number.empty()) {
		throw invalid_argument("Phone number cannot be empty");
	}
}
string PhoneNumber::GetCountryCode() const {
	return country_code;
}
string PhoneNumber::GetCityCode() const {
	return city_code;
}
string PhoneNumber::GetLocalNumber() const {
	return local_number;
}
string PhoneNumber::GetInternationalNumber() const {
	return ('+' + country_code + '-' + city_code + '-' + local_number);
}
