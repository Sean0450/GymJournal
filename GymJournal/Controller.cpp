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
	m_docManager.GetExercisesDocument().AddExercise(exercise, musculesGroup);
}

void Controller::ViewAllExercisesButtonClicked()
{
	m_docManager.GetExercisesDocument().GetStringFormat().value().GetAllData();
}

void Controller::AddTraningSessionButtonClicked(const std::vector<std::string> & exercisesNames,
                                              const std::vector<std::string> & amountAndWeight, const std::string & date)
{
	m_docManager.GetTraningsDocument().AddTraningSession(exercisesNames, amountAndWeight, date);
}

void Controller::ViewAllTraningSessionsButtonClicked()
{
}

std::vector<std::string> Controller::GetExercisesTypes()
{
	auto exerciseNames = m_docManager.GetExercisesDocument().GetStringFormat();
	if (exerciseNames.has_value()) {
		return exerciseNames.value().GetKeys();
	}
	return std::vector<std::string>();
}
