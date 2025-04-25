#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    void get_time() {
        cout << "Enter hours (0-23): ";
        while (!(cin >> hours) || hours < 0 || hours > 23) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid! Enter hours (0-23): ";
        }

        cout << "Enter minutes (0-59): ";
        while (!(cin >> minutes) || minutes < 0 || minutes > 59) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid! Enter minutes (0-59): ";
        }

        cout << "Enter seconds (0-59): ";
        while (!(cin >> seconds) || seconds < 0 || seconds > 59) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid! Enter seconds (0-59): ";
        }
    }

    void put_time() const {
        cout << "Time = " << hours << ':'
            << (minutes < 10 ? "0" : "") << minutes << ':'
            << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};

int main() {
    Time t;
    char choice;
    do {
        t.get_time();
        t.put_time();
        cout << "Continue (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
