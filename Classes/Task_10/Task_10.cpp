#include <iostream>
using namespace std;

class angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    void getAngle() {
        cout << "Enter degrees, minutes, and direction (N, S, E, W): ";
        cin >> degrees >> minutes >> direction;
    }

    void showAngle() const {
        cout << degrees << "\xF8" << minutes << "' " << direction;
    }
};

class ship {
private:
    static int count;
    int id;
    angle latitude, longitude;

public:
    ship() : id(++count) {}

    void getShipData() {
        cout << "Enter location for ship " << id << ":\n";
        cout << "Latitude:\n";
        latitude.getAngle();
        cout << "Longitude:\n";
        longitude.getAngle();
    }

    void showShipData() const {
        cout << "Ship ID: " << id << "\nLatitude: ";
        latitude.showAngle();
        cout << "\nLongitude: ";
        longitude.showAngle();
        cout << endl;
    }
};

int ship::count = 0;

int main() {
    ship s1, s2, s3;

    s1.getShipData();
    s2.getShipData();
    s3.getShipData();

    cout << "\nShip Information:\n";
    s1.showShipData();
    s2.showShipData();
    s3.showShipData();

    return 0;
}
