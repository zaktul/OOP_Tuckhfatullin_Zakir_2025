#include <iostream>
using namespace std;

class SafeArray {
private:
    static const int NUM_ARRAYS = 10;
    static const int ARRAY_SIZE = 10;
    int* ap[NUM_ARRAYS];

public:
    SafeArray() {
        for (int j = 0; j < NUM_ARRAYS; j++) {
            ap[j] = new int[ARRAY_SIZE];
        }
    }

    int& operator[](int index) {
        int outer = index / ARRAY_SIZE;
        int inner = index % ARRAY_SIZE;
        return *(*(ap + outer) + inner);
    }

    void fillTestData() {
        for (int i = 0; i < NUM_ARRAYS * ARRAY_SIZE; i++) {
            (*this)[i] = i * 10;
        }
    }

    void display() {
        for (int i = 0; i < NUM_ARRAYS * ARRAY_SIZE; i++) {
            cout << (*this)[i] << " ";
            if ((i + 1) % ARRAY_SIZE == 0) cout << endl;
        }
    }
};

int main() {
    SafeArray a;
    a.fillTestData();
    a.display();
    return 0;
}
