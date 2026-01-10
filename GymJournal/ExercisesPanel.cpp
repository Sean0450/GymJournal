#include "ExercisesPanel.h"
#include "Exercise.hpp"

ExercisesPanel::ExercisesPanel(QWidget * parent)
  : QWidget(parent)
{
  auto vlayout = new QVBoxLayout(this);
  m_addExerceseButton = new QPushButton(this);
  m_addExerceseButton->setText(Resources::addExercise);
  QObject::connect(m_addExerceseButton, &QPushButton::clicked, this, &ExercisesPanel::AddExerciseButtonClicked);
  vlayout->addWidget(m_addExerceseButton);

  m_viewAllExercisesButton = new QPushButton(this);
  m_viewAllExercisesButton->setText(Resources::viewAllExercises);
  QObject::connect(m_viewAllExercisesButton, &QPushButton::clicked, this, &ExercisesPanel::ViewAllExercisesButtonClicked);
  vlayout->addWidget(m_viewAllExercisesButton);
}

void ExercisesPanel::AddExerciseButtonClicked()
{
  auto addExercise = new AddExerciseDialog(this);
  addExercise->exec();
  auto exerciseName = addExercise->GetExerciseName();
  auto musculesGroup = addExercise->GetMusculesGroupName();
  if (auto observer = m_observer.lock())
  {
    if (!exerciseName.empty() and !musculesGroup.empty())
    {
      observer->AddExerciseButtonClicked(std::move(exerciseName), std::move(musculesGroup));
    }
  }
}

void ExercisesPanel::SetObserver(std::weak_ptr<ExercisePanelObserver> observer)
{
  m_observer = std::move(observer);
}

void ExercisesPanel::ViewAllExercisesButtonClicked()
{
  if (auto observer = m_observer.lock())
  {
    observer->ViewAllExercisesButtonClicked();
  }
}
