#include <iostream>
using namespace std;

class employee {
private:
    int id;
    float salary;

public:
    void getData() {
        cout << "Enter employee ID and salary: ";
        cin >> id >> salary;
    }

    void showData() const {
        cout << "ID: " << id << ", Salary: $" << salary << endl;
    }
};

int main() {
    employee emp1, emp2, emp3;

    emp1.getData();
    emp2.getData();
    emp3.getData();

    cout << "\nEmployee Information:\n";
    emp1.showData();
    emp2.showData();
    emp3.showData();

    return 0;
}
