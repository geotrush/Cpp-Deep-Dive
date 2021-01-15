/*
Input
The input stream contains an integer q (number of queries)
as well as some sequence of the following queries (guaranteed to be valid):
- "ADD i t": add task t on the i-th day (indexed from '1') of the current month;
- "DUMP i": check all tasks planned on the i-th day (indexed from '1');
- "NEXT": transfer all tasks from the current month to the next one,
moving the tasks that didn't fit to the last day of the new month.
Notes: January is the starting month; February always has 28 days.

Output
You should output the number of planned tasks for the i-th day as well as their names
in any order, separated by spaces at every "DUMP i" query (on a new line).
*/
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	const vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int month_count = days_in_month.size();
	int month;

	int q;
	cin >> q;

	vector<vector<string>> daily_planner(days_in_month[month]);
	for (int i = 0; i < q; ++i) {
		string query;
		cin >> query;

		if (query == "ADD") {
			int day;
			cin >> day;
			string task;
			cin >> task;
			daily_planner[--day].push_back(task);
		}
		else if (query == "NEXT") {
			const int old_month_length = days_in_month[month];
			month = (month + 1) % month_count;
			const int new_month_length = days_in_month[month];

			if (new_month_length < old_month_length) {
				vector<string>& last_day_tasks = daily_planner[new_month_length - 1];

				for (int i = new_month_length; i < old_month_length; i++) {
					last_day_tasks.insert(end(last_day_tasks),
					begin(daily_planner[i]), end(daily_planner[i]));
				}
			}
			daily_planner.resize(new_month_length);
		}
		else if (query == "DUMP") {
			int day;
			cin >> day;
			cout << daily_planner[--day].size() << ' ';

			for (const string& task : daily_planner[day]) {
				cout << task << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}
