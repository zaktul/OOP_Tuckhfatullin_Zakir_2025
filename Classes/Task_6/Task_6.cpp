#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

class date {
private:
    int day, month, year;

public:
    void getdate() {
        char slash;
        cout << "Enter hire date (MM/DD/YY): ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showdate() const {
        cout << month << "/" << day << "/" << year;
    }
};

class employee {
private:
    int id;
    float salary;
    etype position;
    date hire_date;

public:
    void getemploy() {
        char letter;
        cout << "Enter employee ID and salary: ";
        cin >> id >> salary;

        cout << "Enter the first letter of the job title (l, s, m, a, e, r): ";
        cin >> letter;
        switch (letter) {
        case 'l': position = laborer; break;
        case 's': position = secretary; break;
        case 'm': position = manager; break;
        case 'a': position = accountant; break;
        case 'e': position = executive; break;
        case 'r': position = researcher; break;
        }

        hire_date.getdate();
    }

    void putemploy() const {
        cout << "ID: " << id << ", Salary: $" << salary << ", Job: ";
        switch (position) {
        case laborer: cout << "Laborer"; break;
        case secretary: cout << "Secretary"; break;
        case manager: cout << "Manager"; break;
        case accountant: cout << "Accountant"; break;
        case executive: cout << "Executive"; break;
        case researcher: cout << "Researcher"; break;
        }
        cout << ", Hire Date: ";
        hire_date.showdate();
        cout << endl;
    }
};

int main() {
    employee emp1, emp2, emp3;

    emp1.getemploy();
    emp2.getemploy();
    emp3.getemploy();

    cout << "\nEmployee Information:\n";
    emp1.putemploy();
    emp2.putemploy();
    emp3.putemploy();

    return 0;
}
