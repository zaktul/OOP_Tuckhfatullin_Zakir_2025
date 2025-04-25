#include <iostream>
#include <sstream>
using namespace std;

class Frac {
private:
    int num, den;

public:
    Frac() : num(0), den(1) {}

    friend istream& operator>>(istream& in, Frac& f) {
        string input;
        in >> input;
        istringstream iss(input);
        char slash;
        if (!(iss >> f.num >> slash >> f.den) || slash != '/' || f.den == 0) {
            in.setstate(ios::failbit);
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Frac& f) {
        out << f.num << '/' << f.den;
        return out;
    }

    Frac operator+(const Frac& f) const {
        return Frac(num * f.den + f.num * den, den * f.den);
    }
};

int main() {
    Frac f1, f2, result;
    char op;
    bool valid = false;

    while (!valid) {
        cout << "Enter first fraction: ";
        if (cin >> f1)
            valid = true;
        else {
            cout << "Invalid fraction format! Try again.\n";
            cin.clear(); cin.ignore(1000, '\n');
        }
    }

    cout << "Enter operator (+): ";
    cin >> op;

    valid = false;
    while (!valid) {
        cout << "Enter second fraction: ";
        if (cin >> f2)
            valid = true;
        else {
            cout << "Invalid fraction format! Try again.\n";
            cin.clear(); cin.ignore(1000, '\n');
        }
    }

    result = f1 + f2;
    cout << "Result: " << result << endl;
    return 0;
}
