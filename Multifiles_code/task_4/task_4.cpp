#include <iostream>
#include "FitnessTracker.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    FitnessTracker tracker;

    char choice;
    do {
        string name;
        int reps, calories;

        cout << "\nВведите название упражнения: ";
        cin.ignore(); // чтобы считывать строку после cin
        getline(cin, name);

        cout << "Количество повторений: ";
        cin >> reps;

        cout << "Сожжённые калории: ";
        cin >> calories;

        tracker.addWorkout(name, reps, calories);

        cout << "Добавить ещё тренировку? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nВаша история тренировок:\n";
    tracker.displayWorkouts();

    cout << "\nВсего сожжено калорий: " << tracker.getTotalCalories() << endl;

    return 0;
}
