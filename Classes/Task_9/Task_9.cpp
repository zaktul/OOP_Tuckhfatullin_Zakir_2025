#include <iostream>
using namespace std;

class fraction {
private:
    int numerator, denominator;

public:
    void getFraction() {
        char slash;
        cout << "Enter fraction (numerator/denominator): ";
        cin >> numerator >> slash >> denominator;
    }

    void showFraction() const {
        cout << numerator << "/" << denominator;
    }

    fraction add(const fraction& f) const {
        fraction result;
        result.numerator = numerator * f.denominator + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return result;
    }
};

int main() {
    fraction f1, f2, result;
    char choice;

    do {
        f1.getFraction();
        f2.getFraction();

        result = f1.add(f2);
        cout << "Sum: ";
        result.showFraction();
        cout << endl;

        cout << "Continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
