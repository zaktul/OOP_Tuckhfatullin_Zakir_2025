#include <iostream>
using namespace std;

struct sterling {
    int pounds, shillings, pence;
};

sterling getSterling();
sterling addSterling(sterling, sterling);
void showSterling(sterling);

int main() {
    sterling s1 = getSterling();
    sterling s2 = getSterling();
    sterling result = addSterling(s1, s2);
    cout << "Sum: ";
    showSterling(result);
    return 0;
}

sterling getSterling() {
    sterling s;
    cout << "Input pounds, shillings and pence: ";
    cin >> s.pounds >> s.shillings >> s.pence;
    return s;
}

sterling addSterling(sterling s1, sterling s2) {
    sterling sum;
    sum.pence = s1.pence + s2.pence;
    sum.shillings = s1.shillings + s2.shillings + sum.pence / 12;
    sum.pounds = s1.pounds + s2.pounds + sum.shillings / 20;
    sum.pence %= 12;
    sum.shillings %= 20;
    return sum;
}

void showSterling(sterling s) {
    cout << s.pounds << " pounds, " << s.shillings << " shillings, " << s.pence << " pence" << endl;
}