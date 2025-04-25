#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Name {
private:
    string first, middle, last;
    unsigned long number;

public:
    void input() {
        cout << "Enter first name: "; cin >> first;
        cout << "Enter middle name: "; cin >> middle;
        cout << "Enter last name: "; cin >> last;
        cout << "Enter employee number: "; cin >> number;
    }

    void output() const {
        cout << "Name: " << first << ' ' << middle << ' ' << last
            << ", Number: " << number << endl;
    }

    void save_to_file() const {
        ofstream out("names.txt", ios::app);
        out << first << ' ' << middle << ' ' << last << ' ' << number << '\n';
        out.close();
    }

    bool load_from_file(int index) {
        ifstream in("names.txt");
        string f, m, l;
        unsigned long num;
        int count = 0;
        while (in >> f >> m >> l >> num) {
            if (count == index) {
                first = f; middle = m; last = l; number = num;
                return true;
            }
            count++;
        }
        return false;
    }
};

int main() {
    Name n;
    char choice;
    do {
        n.input();
        n.save_to_file();
        cout << "Add another? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nEnter record index to read: ";
    int idx; cin >> idx;
    if (n.load_from_file(idx)) n.output();
    else cout << "Record not found.\n";
    return 0;
}
