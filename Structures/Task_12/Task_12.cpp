#include <iostream>
using namespace std;

struct fraction {
    int numerator, denominator;
};

int main() {
    fraction f1, f2, result;
    char op;

    cout << "Enter first fraction (numerator denominator): ";
    cin >> f1.numerator >> f1.denominator;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second fraction (numerator denominator): ";
    cin >> f2.numerator >> f2.denominator;

    switch (op) {
    case '+':
        result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
        result.denominator = f1.denominator * f2.denominator;
        break;
    case '-':
        result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
        result.denominator = f1.denominator * f2.denominator;
        break;
    case '*':
        result.numerator = f1.numerator * f2.numerator;
        result.denominator = f1.denominator * f2.denominator;
        break;
    case '/':
        result.numerator = f1.numerator * f2.denominator;
        result.denominator = f1.denominator * f2.numerator;
        break;
    default:
        cout << "Invalid operator!" << endl;
        return 1;
    }

    cout << "Result: " << result.numerator << "/" << result.denominator << endl;

    return 0;
}
