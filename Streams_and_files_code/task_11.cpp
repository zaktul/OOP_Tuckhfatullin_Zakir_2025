#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class bMoney {
private:
    long double money;

public:
    bMoney() : money(0.0) {}
    bMoney(long double m) : money(m) {}

    friend istream& operator>>(istream& in, bMoney& m) {
        char s[80];
        in >> s;
        char clean[80];
        int j = 0;
        for (int i = 0; s[i]; i++)
            if (isdigit(s[i]) || s[i] == '.')
                clean[j++] = s[i];
        clean[j] = '\0';
        m.money = atof(clean);
        return in;
    }

    friend ostream& operator<<(ostream& out, const bMoney& m) {
        out.setf(ios::fixed);
        out.precision(2);
        out << "$" << m.money;
        return out;
    }
};

int main() {
    bMoney m1, m2;
    cout << "Enter first amount: ";
    cin >> m1;
    cout << "Enter second amount: ";
    cin >> m2;
    cout << "You entered: " << m1 << " and " << m2 << endl;
    return 0;
}
