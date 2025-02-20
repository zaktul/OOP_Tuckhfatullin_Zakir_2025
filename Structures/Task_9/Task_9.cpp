#include <iostream>
using namespace std;

struct Time {
    int hours, minutes, seconds;
};

int main() {
    Time t;

    cout << "Enter time (hours minutes seconds): ";
    cin >> t.hours >> t.minutes >> t.seconds;

    long totalSeconds = t.hours * 3600 + t.minutes * 60 + t.seconds;

    cout << "Total seconds: " << totalSeconds << endl;

    return 0;
}
