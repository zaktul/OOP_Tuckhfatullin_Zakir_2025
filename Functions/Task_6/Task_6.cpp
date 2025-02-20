#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(Time);
Time secs_to_time(long);

int main() {
    Time t1, t2, sum;

    cout << "Enter first time (hours minutes seconds): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "Enter second time (hours minutes seconds): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    long total_secs = time_to_secs(t1) + time_to_secs(t2);
    sum = secs_to_time(total_secs);

    cout << "Total time: " << sum.hours << ":" << sum.minutes << ":" << sum.seconds << endl;

    return 0;
}

long time_to_secs(Time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

Time secs_to_time(long total_secs) {
    Time t;
    t.hours = total_secs / 3600;
    t.minutes = (total_secs % 3600) / 60;
    t.seconds = total_secs % 60;
    return t;
}
