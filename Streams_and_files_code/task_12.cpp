#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
private:
    string first, last;
    unsigned long number;

public:
    void input() {
        cout << "Enter first name: "; cin >> first;
        cout << "Enter last name: "; cin >> last;
        cout << "Enter number: "; cin >> number;
    }

    void output() const {
        cout << "Name: " << first << ' ' << last
            << ", Number: " << number << endl;
    }

    void save(ofstream& out) const {
        out << first << ' ' << last << ' ' << number << endl;
    }

    bool load(ifstream& in) {
        return (in >> first >> last >> number);
    }

    bool has_number(unsigned long num) const {
        return number == num;
    }
};

int main() {
    char choice;
    Employee emp;

    do {
        emp.input();
        ofstream out("employees_search.txt", ios::app);
        emp.save(out);
        out.close();
        cout << "Add another? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    cout << "\nPress 'f' to search: ";
    cin >> choice;

    if (choice == 'f') {
        unsigned long searchNum;
        cout << "Enter employee number to search: ";
        cin >> searchNum;

        ifstream in("employees_search.txt");
        bool found = false;
        while (emp.load(in)) {
            if (emp.has_number(searchNum)) {
                cout << "Found:\n";
                emp.output();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Employee not found.\n";
    }

    return 0;
}
