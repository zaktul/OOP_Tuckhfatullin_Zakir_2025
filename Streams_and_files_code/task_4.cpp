#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("employees.txt");
    if (!outFile) {
        cerr << "Cannot open file for writing!" << endl;
        return 1;
    }

    string first, middle, last;
    unsigned long number;
    char choice;

    do {
        cout << "Enter first name: "; cin >> first;
        cout << "Enter middle name: "; cin >> middle;
        cout << "Enter last name: "; cin >> last;
        cout << "Enter employee number: "; cin >> number;

        outFile << first << ' ' << middle << ' ' << last << ' ' << number << endl;

        cout << "Add another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    outFile.close();

    // Чтение из файла
    ifstream inFile("employees.txt");
    if (!inFile) {
        cerr << "Cannot open file for reading!" << endl;
        return 1;
    }

    cout << "\nEmployee list:\n";
    while (inFile >> first >> middle >> last >> number) {
        cout << "Name: " << first << ' ' << middle << ' ' << last;
        cout << ", Number: " << number << endl;
    }

    inFile.close();
    return 0;
}
