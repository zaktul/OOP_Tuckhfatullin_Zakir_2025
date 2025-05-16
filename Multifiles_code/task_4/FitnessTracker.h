#ifndef FITNESSTRACKER_H
#define FITNESSTRACKER_H

#include <string>
#include <vector>

struct Workout {
    std::string name;
    int repetitions;
    int calories;
};

class FitnessTracker {
private:
    std::vector<Workout> workouts;

public:
    void addWorkout(const std::string& name, int reps, int calories);
    void displayWorkouts() const;
    int getTotalCalories() const;
};

#endif
