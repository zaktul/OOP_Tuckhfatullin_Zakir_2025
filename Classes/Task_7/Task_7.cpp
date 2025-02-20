#include <iostream>
using namespace std;

class angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    angle(int d, float m, char dir) : degrees(d), minutes(m), direction(dir) {}

    void getAngle() {
        cout << "Enter degrees, minutes, and direction (N, S, E, W): ";
        cin >> degrees >> minutes >> direction;
    }

    void showAngle() const {
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};

int main() {
    angle location1(149, 34.8, 'W');
    cout << "Default location: ";
    location1.showAngle();

    angle userLocation(0, 0.0, 'N');
    while (true) {
        userLocation.getAngle();
        cout << "You entered: ";
        userLocation.showAngle();
    }

    return 0;
}
