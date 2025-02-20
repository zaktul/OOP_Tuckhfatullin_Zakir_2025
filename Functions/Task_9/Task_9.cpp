#include <iostream>
using namespace std;

struct Time {
    int hours, minutes, seconds;
};

void swap(Time&, Time&);

int main() {
    Time t1, t2;
    cout << "Enter first time:" << endl;
    cin >> t1.hours >> t1.minutes >> t1.seconds;
    cout << "Enter second time:" << endl;
    cin >> t2.hours >> t2.minutes >> t2.seconds;
    
    cout << "Before swap: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " and "
        << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;
    swap(t1, t2);
    cout << "After swap: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " and "
        << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;
    return 0;
}

void swap(Time& t1, Time& t2) {
    Time temp = t1;
    t1 = t2;
    t2 = temp;
}