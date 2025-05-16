#include "elev.h"
#include <iostream>
using namespace std;

Elevator::Elevator() : currentFloor(1), direction('u') {}

void Elevator::addRequest() {
    int floor;
    char dir;
    cout << "�� ����� ����� �� ����������? (1�20): ";
    cin >> floor;
    if (floor < 1 || floor > 20) {
        cout << "�������� ����! ������� ����� �� 1 �� 20." << endl;
        return;
    }

    cout << "� ����� ����������� �� ������ �������? (u � �����, d � ����): ";
    cin >> dir;
    if (dir != 'u' && dir != 'd') {
        cout << "�������� �����������! ������� 'u' ��� 'd'." << endl;
        return;
    }

    direction = dir;
    if (processedRequests.find(floor) == processedRequests.end()) {
        requests.push(floor);
        processedRequests.insert(floor);
        cout << "������ �� ���� " << floor << " ��������." << endl;
    }
    else {
        cout << "������ �� ���� " << floor << " ��� ��� ��������." << endl;
    }
}

void Elevator::processRequests() {
    while (!requests.empty()) {
        int nextFloor = requests.front();
        requests.pop();
        moveToFloor(nextFloor);
    }
    processedRequests.clear();
}

void Elevator::moveToFloor(int floor) {
    cout << "���� �������� " << (floor > currentFloor ? "�����" : "����") << " � ����� " << floor << "..." << endl;
    currentFloor = floor;
    cout << "���� ������ �� ���� " << currentFloor << "." << endl;
}

void Elevator::displayStatus() const {
    cout << "������� ����: " << currentFloor
        << ", �����������: " << (direction == 'u' ? "�����" : "����") << endl;
}
