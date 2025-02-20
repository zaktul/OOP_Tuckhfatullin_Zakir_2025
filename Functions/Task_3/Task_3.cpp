#include <iostream> 
using namespace std;

void zeroSmaller(int&, int&);

int main()
{
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    zeroSmaller(num1, num2);

    cout << "num1 = " << num1  << endl;
    cout << "num2 = " << num2  << endl;

    return 0;
}

void zeroSmaller(int& num1, int& num2) {
    if (num1 == num2) {
        cout << "Numbers are equals, cannot assign value 0." << endl;
    }
    else if (num1 > num2) {
        num2 = 0;
    }
    else {
        num1 = 0;
    }
}
