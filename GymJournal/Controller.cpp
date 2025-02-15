#include "Controller.h"


Controller::Controller(Private priv, std::shared_ptr<GymJournal> journal)
  : m_view(std::move(journal))
{
}

std::shared_ptr<Controller> Controller::Create(std::shared_ptr<GymJournal> journal)
{
  auto controller = std::make_shared<Controller>(Private(), journal);
  return controller;
}

void Controller::AddExerciseButtonClicked(std::string_view exercise, std::string_view musculesGroup)
{
  m_exercisedoc.AddExercise(exercise, musculesGroup);
}

void Controller::ViewAllExercisesButtonClicked()
{
  m_exercisedoc.GetStringFormat();
}

void Controller::AddTraningSessionButtonClicked()
{
}

void Controller::ViewAllTraningSessionsButtonClicked()
{
}

const std::vector<std::string> Controller::GetExercisesTypes()
{
  return GetExercisesName(m_exercisedoc.GetStringFormat().value());
}
