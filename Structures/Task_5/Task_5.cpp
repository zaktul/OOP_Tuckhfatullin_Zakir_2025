#include <iostream>
using namespace std;

struct date {
    int day, month, year;
};

int main() {
    date d;

    cout << "Enter date (DD/MM/YYYY): ";
    char slash;
    cin >> d.day >> slash >> d.month >> slash >> d.year;

    cout << "You entered: " << d.day << "/" << d.month << "/" << d.year << endl;

    return 0;
}
