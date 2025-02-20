#include <iostream>
using namespace std;

struct fraction {
    int numerator, denominator;
};

int main() {
    fraction f1, f2, result;

    cout << "Enter first fraction (numerator and denominator): ";
    cin >> f1.numerator >> f1.denominator;

    cout << "Enter second fraction (numerator and denominator): ";
    cin >> f2.numerator >> f2.denominator;

    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;

    cout << "Sum: " << result.numerator << "/" << result.denominator << endl;

    return 0;
}
