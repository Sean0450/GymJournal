#pragma once

#include <string>


class ExercisePanelObserver
{
public:
  virtual ~ExercisePanelObserver() = default;
  virtual void AddExerciseButtonClicked(std::string_view exercise, std::string_view musculesGroup) = 0;
  virtual void ViewAllExercisesButtonClicked() = 0;
};
