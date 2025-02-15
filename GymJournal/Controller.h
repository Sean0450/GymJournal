#pragma once

#include "ExercisePanelObserver.h"
#include "ExercisesDocument.h"
#include "GymJournal.h"
#include "TraningSessionPanelObserver.h"


class Controller : public ExercisePanelObserver,
                   public TraningSessionPanelObserver{
  struct Private
  {
    explicit Private() = default;
  };
  std::shared_ptr<GymJournal> m_view;
  ExercisesDocument m_exercisedoc;

public:
  Controller(Private priv, std::shared_ptr<GymJournal> journal);
  static std::shared_ptr<Controller> Create(std::shared_ptr<GymJournal> journal);
  virtual void AddExerciseButtonClicked(std::string_view exercise, std::string_view musculesGroup) override;
  virtual void ViewAllExercisesButtonClicked() override;
  virtual void AddTraningSessionButtonClicked() override;
  virtual void ViewAllTraningSessionsButtonClicked() override;
  virtual const std::vector<std::string> GetExercisesTypes() override;
};
