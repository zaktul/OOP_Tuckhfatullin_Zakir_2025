#include <iostream>
using namespace std;

struct sterling {
    int pounds, shillings, pence;
};

int main() {
    double decimalPounds;
    sterling oldMoney;

    cout << "Enter amount in decimal pounds: ";
    cin >> decimalPounds;

    oldMoney.pounds = static_cast<int>(decimalPounds);
    double remaining = (decimalPounds - oldMoney.pounds) * 20;
    oldMoney.shillings = static_cast<int>(remaining);
    oldMoney.pence = static_cast<int>((remaining - oldMoney.shillings) * 12);

    cout << "Equivalent in old system: "
        << oldMoney.pounds << " pounds, "
        << oldMoney.shillings << " shillings, "
        << oldMoney.pence << " pence" << endl;

    return 0;
}
