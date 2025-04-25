#include <iostream>
#include <cstdlib>
using namespace std;

class Frac {
private:
    int num, den;

public:
    Frac() : num(0), den(1) {}
    Frac(int n, int d) : num(n), den(d) {}

    friend istream& operator>>(istream& in, Frac& f) {
        char slash;
        in >> f.num >> slash >> f.den;
        if (f.den == 0) {
            cout << "Denominator cannot be zero!" << endl;
            exit(1);
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

    Frac operator-(const Frac& f) const {
        return Frac(num * f.den - f.num * den, den * f.den);
    }

    Frac operator*(const Frac& f) const {
        return Frac(num * f.num, den * f.den);
    }

    Frac operator/(const Frac& f) const {
        return Frac(num * f.den, den * f.num);
    }
};

int main() {
    Frac f1, f2, result;
    char op;

    cout << "Enter first fraction (e.g. 3/4): ";
    cin >> f1;
    cout << "Enter operator (+,-,*,/): ";
    cin >> op;
    cout << "Enter second fraction: ";
    cin >> f2;

    switch (op) {
    case '+': result = f1 + f2; break;
    case '-': result = f1 - f2; break;
    case '*': result = f1 * f2; break;
    case '/': result = f1 / f2; break;
    default: cout << "Invalid operator.\n"; return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}
