#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
        cout << "Enter money amount (e.g. $1234.56): ";
        cin >> s;
        money = mstold(s);
    }

    void putmoney() const {
        char s[80];
        ldtoms(s, money);
        cout << "Amount: " << s << endl;
    }

    friend bMoney round(const bMoney& m);
};

bMoney round(const bMoney& m) {
    long double intPart;
    long double frac = modfl(m.money, &intPart);
    if (frac >= 0.5L)
        intPart += 1.0L;
    return bMoney(to_string(intPart));
}

int main() {
    bMoney original, rounded;
    char choice;

    do {
        original.getmoney();
        rounded = round(original);
        cout << "Rounded: ";
        rounded.putmoney();

        cout << "\nRound another? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Строка -> long double
long double mstold(const char* str) {
    char clean[80];
    int j = 0;
    for (int i = 0; str[i]; i++)
        if (isdigit(str[i]) || str[i] == '.')
            clean[j++] = str[i];
    clean[j] = '\0';
    return atof(clean);
}

// long double -> строка
void ldtoms(char* str, long double val) {
    sprintf(str, "$%.2Lf", val);
}
