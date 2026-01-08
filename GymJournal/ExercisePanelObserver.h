#pragma once

#include <string>

class ExercisePanelObserver
{
public:
  virtual ~ExercisePanelObserver() = default;
  virtual void AddExerciseButtonClicked(std::string&& exerciseName, std::string&& musculesGroup) = 0;
  virtual void ViewAllExercisesButtonClicked() = 0;
};
