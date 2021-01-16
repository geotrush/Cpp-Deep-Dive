/*
Task
You should define a class with the single public method:
- "GetCurrentTime()": calls the private method AskTimeServer() and returns its value, however:
    a) If AskTimeServer() has thrown system_error, catch it and return last_fetched_time.
*/
#include <iostream>
#include <string>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::error_code;
using std::system_error;

class TimeServer {
public:
	string GetCurrentTime() {
		try {
            last_fetched_time = AskTimeServer();
		}
		catch (const system_error& system_error) {
			cout << system_error.what() << endl;
		}
		return last_fetched_time;
	}
private:
    string AskTimeServer() {
	    throw system_error(error_code());
	    return "01:26:16";
    }
	string last_fetched_time = "00:00:00";
};

int main() {
	TimeServer time;
	try {
		cout << time.GetCurrentTime() << endl;
	}
	catch (exception& exception) {
		cout << "Exception got: " << exception.what() << endl;
	}

	return 0;
}
