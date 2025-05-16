﻿#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int first1, last1, first2;

    cout << "Введите начало (first1) и конец (last1) последовательности для копирования: ";
    cin >> first1 >> last1;
    cout << "Введите позицию назначения (first2): ";
    cin >> first2;

    if (first2 >= first1 && first2 <= last1) {
        cout << "Ошибка: копирование вправо может перекрыть исходные данные!" << endl;
        return 1;
    }
    copy(numbers.begin() + first1, numbers.begin() + last1 + 1, numbers.begin() + first2);

    cout << "После копирования: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}