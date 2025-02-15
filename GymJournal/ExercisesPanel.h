#pragma once

#include <QtWidgets>

#include "ExercisePanelObserver.h"
#include "Resources.h"
#include "AddExerciseDialog.h"


class ExercisesPanel : public QWidget
{
  Q_OBJECT
  QPushButton * m_addExerceseButton = nullptr;
  QPushButton* m_viewAllExercisesButton = nullptr;
  std::weak_ptr<ExercisePanelObserver> m_observer;

private slots:
  void AddExerciseButtonClicked();
  void ViewAllExercisesButtonClicked();

public:
  ExercisesPanel(QWidget * parent = nullptr);
  void SetObserver(std::weak_ptr<ExercisePanelObserver> observer);
};
