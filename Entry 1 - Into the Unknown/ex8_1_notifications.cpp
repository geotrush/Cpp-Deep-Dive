/* 
Task
You should write the following three classes:
1) "Notifier": abstract base class that implements the pure virtual method Notify(message);
2) "SmsNotifier": derived class that accepts a phone number string and overrides Notify(message) method;
3) "EmailNotifier": derived class that accepts an e-mail address string and overrides Notify(message) method.
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class Notifier {
public:
    virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public Notifier {
private:
    const string Number;
public:
    SmsNotifier(const string& number) : Number(number) {}
    void SendSms(const string& number, const string& message) const {
        cout << "Send '" << message << "' to number " << number << endl;
    }
    virtual void Notify(const string& message) const override {
        SendSms(Number, message);
    }
};

class EmailNotifier : public Notifier {
private:
    const string Email;
public:
    EmailNotifier(const string& email) : Email(email) {}
    void SendEmail(const string& email, const string& message) const {
        cout << "Send '" << message << "' to e-mail " << email << endl;
    }
    virtual void Notify(const string& message) const override {
        SendEmail(Email, message);
    }
};

void Notify(const Notifier& notifier, const string& message) {
    notifier.Notify(message);
}
