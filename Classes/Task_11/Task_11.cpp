#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class fraction {
private:
    int numerator, denominator;

    void lowterms() {
        long tnum = labs(numerator);
        long tden = labs(denominator);
        long temp, gcd;

        if (tden == 0) {
            cout << "Invalid denominator!";
            exit(1);
        }
        else if (tnum == 0) {
            numerator = 0;
            denominator = 1;
            return;
        }

        while (tnum != 0) {
            if (tnum < tden) {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum -= tden;
        }
        gcd = tden;
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    void getFraction() {
        char slash;
        cout << "Enter fraction (numerator/denominator): ";
        cin >> numerator >> slash >> denominator;
        lowterms();
    }

    void showFraction() const {
        cout << numerator << "/" << denominator;
    }

    fraction add(const fraction& f) const {
        fraction result;
        result.numerator = numerator * f.denominator + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        result.lowterms();
        return result;
    }

    fraction subtract(const fraction& f) const {
        fraction result;
        result.numerator = numerator * f.denominator - f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        result.lowterms();
        return result;
    }

    fraction multiply(const fraction& f) const {
        fraction result;
        result.numerator = numerator * f.numerator;
        result.denominator = denominator * f.denominator;
        result.lowterms();
        return result;
    }

    fraction divide(const fraction& f) const {
        fraction result;
        result.numerator = numerator * f.denominator;
        result.denominator = denominator * f.numerator;
        result.lowterms();
        return result;
    }
};

int main() {
    fraction f1, f2, result;
    char op;

    cout << "Enter first fraction: ";
    f1.getFraction();

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second fraction: ";
    f2.getFraction();

    switch (op) {
    case '+': result = f1.add(f2); break;
    case '-': result = f1.subtract(f2); break;
    case '*': result = f1.multiply(f2); break;
    case '/': result = f1.divide(f2); break;
    default: cout << "Invalid operator!"; return 1;
    }

    cout << "Result: ";
    result.showFraction();
    cout << endl;

    return 0;
}
