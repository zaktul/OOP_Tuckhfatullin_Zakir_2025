#include <iostream>
using namespace std;

void addarrays(float*, float*, float*, int);

int main() {
    const int SIZE = 5;
    float arr1[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    float arr2[SIZE] = { 5.5, 4.4, 3.3, 2.2, 1.1 };
    float result[SIZE];

    addarrays(arr1, arr2, result, SIZE);

    cout << "Result array: ";
    for (int i = 0; i < SIZE; i++)
        cout << *(result + i) << " ";
    cout << endl;

    return 0;
}

void addarrays(float* a1, float* a2, float* res, int size) {
    for (int i = 0; i < size; i++)
        *(res + i) = *(a1 + i) + *(a2 + i);
}