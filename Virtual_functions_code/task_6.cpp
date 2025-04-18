#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

long double mstold(const char*);
void ldtoms(char*, long double);

class bMoney {
private:
    long double money;

public:
    bMoney() : money(0.0) {}
    bMoney(char s[]) { money = mstold(s); }

    void getmoney() {
        char s[80];
        cout << "Enter money amount (e.g. $1,234.56): ";
        cin >> s;
        money = mstold(s);
    }

    void putmoney() const {
        char s[80];
        ldtoms(s, money);
        cout << "Amount: " << s << endl;
    }

    bMoney operator+(const bMoney& other) const {
        return bMoney(to_string(money + other.money));
    }

    bMoney operator-(const bMoney& other) const {
        return bMoney(to_string(money - other.money));
    }

    bMoney operator*(long double val) const {
        return bMoney(to_string(money * val));
    }

    bMoney operator/(long double val) const {
        return bMoney(to_string(money / val));
    }

    long double operator/(const bMoney& other) const {
        return money / other.money;
    }

    friend bMoney operator*(long double, const bMoney&);
    friend long double operator/(long double, const bMoney&);
};

// --- Дружественные перегрузки:
bMoney operator*(long double val, const bMoney& m) {
    return bMoney(to_string(val * m.money));
}

long double operator/(long double val, const bMoney& m) {
    return val / m.money;
}

int main() {
    bMoney m1, m2, result;
    long double num;

    char choice;
    do {
        cout << "\n--- Enter first money value ---\n";
        m1.getmoney();

        cout << "--- Enter second money value ---\n";
        m2.getmoney();

        cout << "--- Enter a floating point number: ";
        cin >> num;

        result = m1 + m2;
        cout << "\nSum: "; result.putmoney();

        result = m1 - m2;
        cout << "Difference: "; result.putmoney();

        result = m1 * num;
        cout << "m1 * num: "; result.putmoney();

        result = num * m2;
        cout << "num * m2: "; result.putmoney();

        result = m1 / num;
        cout << "m1 / num: "; result.putmoney();

        cout << "m1 / m2 = " << (m1 / m2) << endl;
        cout << "num / m1 = " << (num / m1) << endl;

        cout << "\nRepeat? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Преобразование строки в long double
long double mstold(const char* str) {
    char clean[80];
    int j = 0;
    for (int i = 0; str[i]; i++)
        if (isdigit(str[i]) || str[i] == '.')
            clean[j++] = str[i];
    clean[j] = '\0';
    return atof(clean);
}

// Преобразование long double в строку
void ldtoms(char* str, long double val) {
    sprintf(str, "$%.2Lf", val);
}
