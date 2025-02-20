#include <iostream>
using namespace std;

int counter = 0;

void callCounter();

int main() {
    for (int i = 0; i < 10; i++) {
        callCounter();
    }
    return 0;
}

void callCounter() {
    counter++;
    cout << "Function called " << counter << " time(s)" << endl;
}