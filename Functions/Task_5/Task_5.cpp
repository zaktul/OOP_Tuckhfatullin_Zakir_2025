#include <iostream>
using namespace std;

long hms_to_secs(int, int, int); 

int main() {
    int hours, minutes, seconds;
    char choice;

    do {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;

        long total_seconds = hms_to_secs(hours, minutes, seconds);
        cout << "Total seconds: " << total_seconds << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

long hms_to_secs(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
