#include <iostream>
#include <cstdlib>
using namespace std;

class horse {
protected:
    float position;
public:
    horse() : position(0.0f) {}
    virtual void horse_tick(horse* hArray[], int size) {
        position += (float(rand() % 10) / 10);
    }
    float get_position() const { return position; }
};

class comhorse : public horse {
public:
    void horse_tick(horse* hArray[], int size) override {
        float maxPos = 0;
        for (int i = 0; i < size; i++)
            if (hArray[i] != this)
                if (hArray[i]->get_position() > maxPos)
                    maxPos = hArray[i]->get_position();

        float gap = position - maxPos;
        if (gap < 0.1f)
            position += 0.2f; 
        else
            position += 0.1f; 
    }
};

int main() {
    const int N = 3;
    horse* hArray[N];
    hArray[0] = new horse();
    hArray[1] = new comhorse();
    hArray[2] = new horse();

    for (int t = 0; t < 10; t++) {
        cout << "Tick " << t + 1 << ":\n";
        for (int i = 0; i < N; i++) {
            hArray[i]->horse_tick(hArray, N);
            cout << "Horse " << i << " pos: " << hArray[i]->get_position() << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) delete hArray[i];
    return 0;
}
