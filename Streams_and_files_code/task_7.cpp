#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Name {
private:
    string first, middle, last;
    unsigned long number;
    static fstream file;

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

    static void open_file() {
        file.open("names_static.txt", ios::in | ios::out | ios::app);
    }

    void save() {
        file << first << ' ' << middle << ' ' << last << ' ' << number << '\n';
    }

    static void rewind_file() {
        file.clear(); file.seekg(0);
    }

    static void read_all() {
        string f, m, l;
        unsigned long num;
        rewind_file();
        while (file >> f >> m >> l >> num)
            cout << "Name: " << f << ' ' << m << ' ' << l << ", Number: " << num << endl;
    }

    static void close_file() {
        file.close();
    }
};

fstream Name::file;

int main() {
    Name::open_file();
    Name n;
    char choice;
    do {
        n.input();
        n.save();
        cout << "Add another? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nReading all records:\n";
    Name::read_all();
    Name::close_file();
    return 0;
}
