#include <iostream>
using namespace std;

class ObjectCounter {
private:
    static int count;
    int id;

public:
    ObjectCounter() {
        count++;
        id = count;
    }

    void showID() const {
        cout << "My ID: " << id << endl;
    }
};

int ObjectCounter::count = 0;

int main() {
    ObjectCounter obj1, obj2, obj3;

    obj1.showID();
    obj2.showID();
    obj3.showID();

    return 0;
}
