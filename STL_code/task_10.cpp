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

    cout << "Введите имя для поиска: ";
    cin >> SearchName;
    auto it = find_if(names.begin(), names.end(), [&](const string& s) { return s == SearchName; });

    if (it != names.end()) {
        cout << "Имя '" << SearchName << "' найдено на позиции " << distance(names.begin(), it) << endl;
    }
    else {
        cout << "Имя '" << SearchName << "' не найдено в контейнере." << endl;
    }

    return 0;
}