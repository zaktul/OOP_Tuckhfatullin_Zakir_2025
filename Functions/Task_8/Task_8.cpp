#include <iostream>
using namespace std;

void swap(int&, int&);

int main() {
    int x, y;
    cout << "Input X and Y values:" << endl;
    cin >> x >> y;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;
    return 0;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}