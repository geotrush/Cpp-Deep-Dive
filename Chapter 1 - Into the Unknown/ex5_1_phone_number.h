#pragma once

#include <string>

using std::string;

class PhoneNumber {
private:
    string country_code;
    string city_code;
    string local_number;
public:
    explicit PhoneNumber(const string &international_number);
    string GetCountryCode() const;
    string GetCityCode() const;
    string GetLocalNumber() const;
    string GetInternationalNumber() const;
};
