#include <iostream>
using namespace std;

void callCounter();

int main() {
    for (int i = 0; i < 10; i++) {
        callCounter();
    }
    return 0;
}

void callCounter() {
    static int counter = 0;
    counter++;
    cout << "Function called " << counter << " time(s)" << endl;
}
