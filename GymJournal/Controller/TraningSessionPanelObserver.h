#pragma once

#include <string>
#include <vector>


class TraningSessionPanelObserver
{
public:
  virtual ~TraningSessionPanelObserver() = default;
  virtual void AddTraningSessionButtonClicked(const std::vector<std::string> & exercisesNames,
                                              const std::vector<std::string> & amountAndWeight, const std::string & date) = 0;
  virtual void ViewAllTraningSessionsButtonClicked() = 0;
  virtual std::vector<std::string> GetExercisesTypes() = 0;
};
