#include <iostream>
using namespace std;

double power(double, int = 2);
float power(float, int = 2);
int power(int, int = 2);
long power(long, int = 2);
char power(char, int = 2);  

int main() {
    double d = 2.5;
    float f = 3.2f;
    int i = 3;
    long l = 4;
    char c = 'A';

    cout << "Double: " << d << "^3 = " << power(d, 3) << endl;
    cout << "Float: " << f << "^2 = " << power(f) << endl;
    cout << "Int: " << i << "^4 = " << power(i, 4) << endl;
    cout << "Long: " << l << "^3 = " << power(l, 3) << endl;
    cout << "Char: " << c << "^2 = " << power(c) << " (ASCII code)" << endl;

    return 0;
}

double power(double n, int p) {
    double result = 1;
    for (int i = 0; i < p; i++)
        result *= n;
    return result;
}

float power(float n, int p) {
    float result = 1;
    for (int i = 0; i < p; i++)
        result *= n;
    return result;
}

int power(int n, int p) {
    int result = 1;
    for (int i = 0; i < p; i++)
        result *= n;
    return result;
}

long power(long n, int p) {
    long result = 1;
    for (int i = 0; i < p; i++)
        result *= n;
    return result;
}

char power(char n, int p) {
    int result = 1;
    for (int i = 0; i < p; i++)
        result *= n;
    return static_cast<char>(result);
}
