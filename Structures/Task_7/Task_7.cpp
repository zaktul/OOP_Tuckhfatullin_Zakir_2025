#include <iostream>
using namespace std;

struct date {
    int day, month, year;
};

enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct employee {
    int id;
    float salary;
    etype position;
    date hire_date;
};

int main() {
    employee emp1, emp2, emp3;
    char letter;

    for (int i = 0; i < 3; i++) {
        employee& emp = (i == 0) ? emp1 : (i == 1) ? emp2 : emp3;

        cout << "Enter employee ID and salary: ";
        cin >> emp.id >> emp.salary;

        cout << "Enter the first letter of the job title (l, s, m, a, e, r): ";
        cin >> letter;
        switch (letter) {
        case 'l': emp.position = laborer; break;
        case 's': emp.position = secretary; break;
        case 'm': emp.position = manager; break;
        case 'a': emp.position = accountant; break;
        case 'e': emp.position = executive; break;
        case 'r': emp.position = researcher; break;
        }

        cout << "Enter hire date (DD/MM/YYYY): ";
        char slash;
        cin >> emp.hire_date.day >> slash >> emp.hire_date.month >> slash >> emp.hire_date.year;
    }

    cout << "\nEmployee Information:\n";
    for (int i = 0; i < 3; i++) {
        employee& emp = (i == 0) ? emp1 : (i == 1) ? emp2 : emp3;

        cout << "ID: " << emp.id << ", Salary: $" << emp.salary << ", Job: ";
        switch (emp.position) {
        case laborer: cout << "Laborer"; break;
        case secretary: cout << "Secretary"; break;
        case manager: cout << "Manager"; break;
        case accountant: cout << "Accountant"; break;
        case executive: cout << "Executive"; break;
        case researcher: cout << "Researcher"; break;
        }
        cout << ", Hire Date: " << emp.hire_date.day << "/" << emp.hire_date.month << "/" << emp.hire_date.year << endl;
    }

    return 0;
}
