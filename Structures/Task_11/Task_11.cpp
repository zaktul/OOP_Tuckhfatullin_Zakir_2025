#include <iostream>
using namespace std;

struct Time {
    int hours, minutes, seconds;
};

int main() {
    Time t1, t2, result;
    long totalSeconds;

    cout << "Enter first time (hh mm ss): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "Enter second time (hh mm ss): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    totalSeconds = (t1.hours * 3600 + t1.minutes * 60 + t1.seconds) +
        (t2.hours * 3600 + t2.minutes * 60 + t2.seconds);

    result.hours = totalSeconds / 3600;
    result.minutes = (totalSeconds % 3600) / 60;
    result.seconds = totalSeconds % 60;

    cout << "Sum: " << result.hours << ":" << result.minutes << ":" << result.seconds << endl;

    return 0;
}
