#include <iostream>
using namespace std;

class fraction {
private:
    int numerator, denominator;

public:
    fraction(int n, int d) : numerator(n), denominator(d) {}

    fraction multiply(const fraction& f) const {
        return fraction(numerator * f.numerator, denominator * f.denominator);
    }

    void showFraction() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    int d;
    cout << "Enter denominator: ";
    cin >> d;

    cout << "\nMultiplication Table:\n";
    for (int i = 1; i < d; i++) {
        for (int j = 1; j < d; j++) {
            fraction f1(i, d);
            fraction f2(j, d);
            fraction result = f1.multiply(f2);
            result.showFraction();
            cout << "\t";
        }
        cout << endl;
    }

    return 0;
}
