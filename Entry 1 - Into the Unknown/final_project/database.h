#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

#include "date.h"

using std::map;
using std::set;
using std::pair;
using std::string;
using std::vector;
using std::make_pair;


class Database {
private:
	map<Date, pair<set<string>, vector<set<string>::iterator>>> db;
public:
	void Add(const Date& date, const string& event);
	void Print(ostream& is) const;
	string Last(const Date& date) const;

	template<typename Functor>
	int RemoveIf(const Functor& func);

	template<typename Functor>
	vector<pair<Date, string>> FindIf(const Functor& func) const;
};

template<typename Functor>
int Database::RemoveIf(const Functor& functor) {
    int count = 0;
    for (auto& date_iter : db) {
		auto iter = stable_partition(date_iter.second.second.begin(), date_iter.second.second.end(), [&](const auto& event) -> bool {
				if (functor(date_iter.first, *event)) {
					count++;
					date_iter.second.first.erase(*event);
					return false;
				}
				return true;
			});
		date_iter.second.second.erase(iter, date_iter.second.second.end());
	}
	for (auto erase_iter = db.cbegin(), next_iter = erase_iter; erase_iter != db.cend(); erase_iter = next_iter) {
		++next_iter;
		if (erase_iter->second.first.empty()) {
			db.erase(erase_iter);
		}
	}
	return count;
}

template<typename Functor>
vector<pair<Date, string>> Database::FindIf(const Functor& functor) const {
	vector<pair<Date, string>> temp;
	for (const auto& date_iter : db) {
		auto it = find_if(date_iter.second.second.begin(), date_iter.second.second.end(), [&](const auto& event) -> bool {
			if (functor(date_iter.first, *event)) {
				temp.push_back(make_pair(date_iter.first, *event));
			}
			return false;
		});
	}
	return temp;
}
