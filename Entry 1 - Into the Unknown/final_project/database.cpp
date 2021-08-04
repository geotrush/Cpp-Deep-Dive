#include "database.h"

using std::endl;
using std::setw;
using std::setfill;
using std::string;
using std::ostream;
using std::invalid_argument;


void Database::Add(const Date& date, const string& event) {
	if (db.count(date)) {
		const auto insert_it = db[date].first.insert(event);
		if (insert_it.second) {
			db[date].second.push_back(insert_it.first);
		}
	}
	else {
		auto insert_result = db[date].first.insert(event);
		db[date].second.push_back(insert_result.first);
	}
}

void Database::Print(ostream& is) const {
	for (const auto& date_iter : db) {
		for (const auto& event_iter : date_iter.second.second) {
			is << setw(4) << setfill('0') << date_iter.first.GetYear() << '-';
			is << setw(2) << setfill('0') << date_iter.first.GetMonth() << '-';
			is << setw(2) << setfill('0') << date_iter.first.GetDay();
			is << ' ' << *event_iter << endl;
		}
	}
}

string Database::Last(const Date& date) const {
	const auto iter_upper = db.upper_bound(date);
	if (iter_upper == db.begin()) {
		throw invalid_argument("No entries");
	}
	return prev(iter_upper)->first.DateToStr() + ' ' + *prev(iter_upper)->second.second.back();
}
