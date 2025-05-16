#include "elev.h"
#include <iostream>
using namespace std;

Elevator::Elevator() : currentFloor(1) {}
void Elevator::requestFloor() {
    int floor;
    cout << "На каком вы этаже?? ";
    cin >> floor;
    if (floor < 1 || floor > 20) {
        cout << "Этаж может быть лишь в деапозоне от 1 до 20." << endl;
        return;
    }
    cout << "Выберите направление (u/d): ";
    char direction;
    cin >> direction;
    if (direction != 'u' && direction != 'd') {
        cout << "Вы можете выбрать только из 2-х вариантов, либо u либл d." << endl;
        return;
    }
    destinations.push_back(floor);
    cout << "Вы на этаже " << floor << "." << endl;
    moveToFloor(floor);
}

void Elevator::moveToFloor(int floor) {
    cout << "Вы едите на этаж " << floor << "..." << endl;
    currentFloor = floor;
    cout << "Вы прибыли на этаж " << currentFloor << "." << endl;
}

void Elevator::setDestination() {
    int dest;
    cout << "Введите желаемый этаж (0 для завершения ввода): ";
    while (true) {
        cin >> dest;
        if (dest == 0) break;
        if (dest < 1 || dest > 20) {
            cout << "Неверный этаж. Введите этаж от 1 до 20." << endl;
            continue;
        }
        destinations.push_back(dest);
    }
    cout << "Список этажей для посещения: ";
    for (int floor : destinations) {
        cout << floor << " ";
    }
    cout << endl;
    serviceDestinations();
}

void Elevator::serviceDestinations() {
    for (int floor : destinations) {
        moveToFloor(floor);
    }
    destinations.clear();
}