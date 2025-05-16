#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<string> names = { "Малика", "Айжамал", "Жоомарт", "Бека", "Куба" };
    string SearchName;
    cout << "Введите имя, которое ищите: "; cin >> SearchName;

    auto it = find_if(names.begin(), names.end(), bind(equal_to<string>(), placeholders::_1, SearchName));

    if (it != names.end()) {
        cout << "Найдено: " << *it << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }

    return 0;
}