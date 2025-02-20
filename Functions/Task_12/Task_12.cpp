#include <iostream>
using namespace std;

struct fraction {
    int num, den;
};

fraction fadd(fraction, fraction);
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);
void showFraction(fraction);

int main() {
    fraction f1, f2, result;
    char op;
    cout << "Input fraction (numerator and denominator): ";
    cin >> f1.num >> f1.den;
    cout << "Input operation (+, -, *, /): ";
    cin >> op;
    cout << "Input second fraction: ";
    cin >> f2.num >> f2.den;

    switch (op) {
    case '+': result = fadd(f1, f2); break;
    case '-': result = fsub(f1, f2); break;
    case '*': result = fmul(f1, f2); break;
    case '/': result = fdiv(f1, f2); break;
    default: cout << "Invalid operation!"; return 1;
    }

    cout << "Result: ";
    showFraction(result);
    return 0;
}

fraction fadd(fraction f1, fraction f2) {
    fraction res;
    res.num = f1.num * f2.den + f2.num * f1.den;
    res.den = f1.den * f2.den;
    return res;
}

fraction fsub(fraction f1, fraction f2) {
    fraction res;
    res.num = f1.num * f2.den - f2.num * f1.den;
    res.den = f1.den * f2.den;
    return res;
}

fraction fmul(fraction f1, fraction f2) {
    fraction res;
    res.num = f1.num * f2.num;
    res.den = f1.den * f2.den;
    return res;
}

fraction fdiv(fraction f1, fraction f2) {
    fraction res;
    res.num = f1.num * f2.den;
    res.den = f1.den * f2.num;
    return res;
}

void showFraction(fraction f) {
    cout << f.num << "/" << f.den << endl;
}