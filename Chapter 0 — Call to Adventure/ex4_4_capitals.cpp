/*
Input
The input stream contains an integer q (number of queries)
as well as some sequence of the following queries (guaranteed to be valid):
- "CHANGE_CAPITAL country new_capital": add/change new/existing country-capital pair;
- "RENAME old_country_name new_country_name": change country name;
- "ABOUT country": check the name of the country's capital;
- "DUMP": check the capital names of all countries.
Note: all strings contain only latin letters, digits and underscores.

Output
You should output the following, based on the query and current state:
- "CHANGE_CAPITAL country new_capital":
	a) If the country didn't exist: "Introduce new country country with capital new_capital;
	b) If the country's capital name is new_capital: "Country country hasn't changed its capital";
	c) If the country can change its capital: "Country country has changed its capital from old_capital to new_capital";
- "RENAME old_country_name new_country_name":
	a) If old_country_name matches new_country_name, old_country_name doesn't exist or new_country_name already exists: "Incorrect rename, skip";
	b) If the country can be renamed: "Country old_country_name with capital capital has been renamed to new_country_name";
- "ABOUT country":
	a) If such country doesn't exist: "Country country doesn't exist";
	b) If such country exists: "Country country has capital capital";
- "DUMP":
	a) If no countries have been added: "There are no countries in the world";
	b) If some countries have been added: Pairs of "country/capital" separated by spaces and in ascending order by country name.
*/
#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {
	int q;
	cin >> q;

	map<string, string> country2capital;
	for (int i = 0; i < q; i++) {
		string query;
		cin >> query;

		if (query == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;

			if (country2capital.count(country) == 0) {
				cout << "Introduce new country " << country <<" with capital " << new_capital << endl;
			}
			else {
				const string& old_capital = country2capital[country];

				if (old_capital == new_capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
				else {
					cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
				}
			}
			country2capital[country] = new_capital;
		}
		else if (query == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			if (old_country_name == new_country_name ||
				country2capital.count(old_country_name) == 0 ||
				country2capital.count(new_country_name) == 1) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				cout << "Country " << old_country_name << " with capital " << country2capital[old_country_name] << " has been renamed to " << new_country_name << endl;
				country2capital[new_country_name] = country2capital[old_country_name];
				country2capital.erase(old_country_name);
			}
		}
		else if (query == "ABOUT") {
			string country;
			cin >> country;

			if (country2capital.count(country) == 0) {
				cout << "Country " << country << " doesn't exist\n";
			}
			else {
				cout << "Country " << country << " has capital " << country2capital[country] << endl;
			}
		}
		else if(query == "DUMP") {
			if (country2capital.empty()) {
				cout << "There are no countries in the world\n";
			}
			else {
				for (const auto& country : country2capital) {
					cout << country.first << '/' << country.second << ' ';
				}
				cout << endl;
			}
		}
	}

	return 0;
}
