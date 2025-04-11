#include <iostream>
using namespace std;

int main() {
    const int NUM_ARRAYS = 10;
    const int ARRAY_SIZE = 10;

    int* ap[NUM_ARRAYS];

    for (int j = 0; j < NUM_ARRAYS; j++) {
        *(ap + j) = new int[ARRAY_SIZE];
    }

    for (int j = 0; j < NUM_ARRAYS; j++) {
        for (int k = 0; k < ARRAY_SIZE; k++) {
            *(*(ap + j) + k) = j * 100 + k * 10;
        }
    }

    for (int j = 0; j < NUM_ARRAYS; j++) {
        for (int k = 0; k < ARRAY_SIZE; k++) {
            cout << *(*(ap + j) + k) << ' ';
        }
        cout << endl;
    }

    return 0;
}
