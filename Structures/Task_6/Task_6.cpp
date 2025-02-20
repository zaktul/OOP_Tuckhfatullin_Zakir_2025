#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main() {
    char letter;
    etype position;

    cout << "Enter the first letter of the job title (l, s, m, a, e, r): ";
    cin >> letter;

    switch (letter) {
    case 'l': position = laborer; break;
    case 's': position = secretary; break;
    case 'm': position = manager; break;
    case 'a': position = accountant; break;
    case 'e': position = executive; break;
    case 'r': position = researcher; break;
    default: cout << "Invalid letter!\n"; return 1;
    }

    cout << "Full job title: ";
    switch (position) {
    case laborer: cout << "Laborer"; break;
    case secretary: cout << "Secretary"; break;
    case manager: cout << "Manager"; break;
    case accountant: cout << "Accountant"; break;
    case executive: cout << "Executive"; break;
    case researcher: cout << "Researcher"; break;
    }

    cout << endl;
    return 0;
}
