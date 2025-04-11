#include <iostream>
using namespace std;

int main() {
    const int NUM_ARRAYS = 10;
    const int ARRAY_SIZE = 10;

    int a0[ARRAY_SIZE], a1[ARRAY_SIZE], a2[ARRAY_SIZE], a3[ARRAY_SIZE], a4[ARRAY_SIZE];
    int a5[ARRAY_SIZE], a6[ARRAY_SIZE], a7[ARRAY_SIZE], a8[ARRAY_SIZE], a9[ARRAY_SIZE];

    int* ap[NUM_ARRAYS] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };

    // Заполнение значениями: 0, 10, 20, ..., 990
    for (int j = 0; j < NUM_ARRAYS; j++) {
        for (int k = 0; k < ARRAY_SIZE; k++) {
            ap[j][k] = j * 100 + k * 10;
        }
    }

    // Вывод
    for (int j = 0; j < NUM_ARRAYS; j++) {
        for (int k = 0; k < ARRAY_SIZE; k++) {
            cout << ap[j][k] << ' ';
        }
        cout << endl;
    }

    return 0;
}
