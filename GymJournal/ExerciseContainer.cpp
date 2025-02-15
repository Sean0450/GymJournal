#include "ExerciseContainer.h"


std::vector<std::string> GetExercisesName(const std::vector<ExerciseContainer>& exercises) {
    std::vector<std::string> exercisesName;
    for (auto && it : exercises)
    {
      exercisesName.emplace_back(it.GetExercise());
    }
    return exercisesName;
}