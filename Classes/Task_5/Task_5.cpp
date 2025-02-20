#include <iostream>
using namespace std;

class date {
private:
    int day, month, year;

public:
    void getdate() {
        char slash;
        cout << "Enter date (MM/DD/YY): ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showdate() const {
        cout << "Date: " << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    date d;
    d.getdate();
    d.showdate();
    return 0;
}
