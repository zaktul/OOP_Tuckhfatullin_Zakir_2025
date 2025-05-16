#include "elev.h"
#include <iostream>
using namespace std;

Elevator::Elevator() : currentFloor(1) {}
void Elevator::requestFloor() {
    int floor;
    cout << "�� ����� �� �����?? ";
    cin >> floor;
    if (floor < 1 || floor > 20) {
        cout << "���� ����� ���� ���� � ��������� �� 1 �� 20." << endl;
        return;
    }
    cout << "�������� ����������� (u/d): ";
    char direction;
    cin >> direction;
    if (direction != 'u' && direction != 'd') {
        cout << "�� ������ ������� ������ �� 2-� ���������, ���� u ���� d." << endl;
        return;
    }
    destinations.push_back(floor);
    cout << "�� �� ����� " << floor << "." << endl;
    moveToFloor(floor);
}

void Elevator::moveToFloor(int floor) {
    cout << "�� ����� �� ���� " << floor << "..." << endl;
    currentFloor = floor;
    cout << "�� ������� �� ���� " << currentFloor << "." << endl;
}

void Elevator::setDestination() {
    int dest;
    cout << "������� �������� ���� (0 ��� ���������� �����): ";
    while (true) {
        cin >> dest;
        if (dest == 0) break;
        if (dest < 1 || dest > 20) {
            cout << "�������� ����. ������� ���� �� 1 �� 20." << endl;
            continue;
        }
        destinations.push_back(dest);
    }
    cout << "������ ������ ��� ���������: ";
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