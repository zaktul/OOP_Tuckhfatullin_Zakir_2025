#include <iostream>
using namespace std;

struct employee {
    int id;
    float salary;
};

int main() {
    employee emp1, emp2, emp3;

    cout << "Enter employee ID and salary: ";
    cin >> emp1.id >> emp1.salary;

    cout << "Enter employee ID and salary: ";
    cin >> emp2.id >> emp2.salary;

    cout << "Enter employee ID and salary: ";
    cin >> emp3.id >> emp3.salary;

    cout << "\nEmployee Information:\n";
    cout << "ID: " << emp1.id << ", Salary: $" << emp1.salary << endl;
    cout << "ID: " << emp2.id << ", Salary: $" << emp2.salary << endl;
    cout << "ID: " << emp3.id << ", Salary: $" << emp3.salary << endl;

    return 0;
}
