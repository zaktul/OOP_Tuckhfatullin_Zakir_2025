#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "Исходный массив: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    copy(numbers.begin(), numbers.begin() + 5, numbers.begin() + 5);

    cout << "После copy(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    copy_backward(numbers.begin(), numbers.begin() + 5, numbers.begin() + 10);

    cout << "После copy_backward(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}