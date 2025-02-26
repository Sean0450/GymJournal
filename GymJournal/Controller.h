#pragma once

#include <unordered_map>

#include "DocumentManager.h"
#include "ExercisePanelObserver.h"
#include "ExercisesDocument.h"
#include "GymJournal.h"
#include "TraningSessionPanelObserver.h"


class Controller : public ExercisePanelObserver,
                   public TraningSessionPanelObserver
{
  struct Private
  {
    explicit Private() = default;
  };
  std::shared_ptr<GymJournal> m_view;
  DocumentManager m_docManager;

public:
  Controller(Private priv, std::shared_ptr<GymJournal> journal);
  static std::shared_ptr<Controller> Create(std::shared_ptr<GymJournal> journal);
  virtual void AddExerciseButtonClicked(std::string_view exercise, std::string_view musculesGroup) override;
  virtual void ViewAllExercisesButtonClicked() override;
  virtual void AddTraningSessionButtonClicked(const std::vector<std::string> & exercisesNames,
                                              const std::vector<std::string> & amountAndWeight, const std::string & date) override;
  virtual void ViewAllTraningSessionsButtonClicked() override;
  virtual std::vector<std::string> GetExercisesTypes() override;
};
