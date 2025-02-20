#include <iostream> 
using namespace std;

double power(double, int = 2); 

int main()
{
    double n, nb, np;
    int p;

    cout << "Enter your number: ";
    cin >> n;
    cout << "Enter power of raising a number: ";
    cin >> p;

    nb = power(n, p);
    np = power(n);    

    cout << "Number " << n << " in power " << p << " = " << nb << endl;
    cout << "Number " << n << " in power 2 = " << np << endl;

    return 0;
}

double power(double n, int p) { 
    double num = n;

    for (int i = 1; i < p; i++)
        n *= num;

    return n;
}
