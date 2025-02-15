#pragma once

#include <vector>
#include <optional>
#include <string>


class ExerciseContainer;

class TraningSessionPanelObserver
{
public:
  virtual ~TraningSessionPanelObserver() = default;
  virtual void AddTraningSessionButtonClicked() = 0;
  virtual void ViewAllTraningSessionsButtonClicked() = 0;
  virtual const std::vector<std::string> GetExercisesTypes() = 0;
};
