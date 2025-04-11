#include <iostream>
using namespace std;

class person {
private:
    char name[40];
    float salary;

public:
    void setData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void printData() {
        cout << "Name: " << name << ", Salary: $" << salary;
    }

    float getSalary() {
        return salary;
    }
};

void salsort(person* [], int);

int main() {
    person* persPtr[100];
    int n = 0;
    char choice;

    do {
        persPtr[n] = new person;
        persPtr[n]->setData();
        n++;
        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    salsort(persPtr, n);

    cout << "\nSorted list by salary:\n";
    for (int i = 0; i < n; i++) {
        cout << "Employee #" << i + 1 << ": ";
        persPtr[i]->printData();
        cout << endl;
    }

    return 0;
}

void salsort(person* pp[], int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
                person* temp = *(pp + j);
                *(pp + j) = *(pp + k);
                *(pp + k) = temp;
            }
        }
    }
}
