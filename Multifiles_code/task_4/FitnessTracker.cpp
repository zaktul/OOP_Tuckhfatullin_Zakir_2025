#include "FitnessTracker.h"
#include <iostream>
using namespace std;

void FitnessTracker::addWorkout(const std::string& name, int reps, int calories) {
    workouts.push_back({ name, reps, calories });
}

void FitnessTracker::displayWorkouts() const {
    for (const Workout& w : workouts) {
        cout << "Упражнение: " << w.name
            << ", Повторений: " << w.repetitions
            << ", Калорий: " << w.calories << endl;
    }
}

int FitnessTracker::getTotalCalories() const {
    int total = 0;
    for (const Workout& w : workouts) {
        total += w.calories;
    }
    return total;
}
