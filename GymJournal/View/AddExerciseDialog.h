#pragma once

#include <QtWidgets>

#include "Resources.h"


class AddExerciseDialog : public QDialog
{
  Q_OBJECT
  QPushButton * m_addButton = nullptr;
  QLineEdit * m_exerciseNameEdit = nullptr;
  QLineEdit * m_musculesGroupNameEdit = nullptr;
  std::string m_exerciseName;
  std::string m_musculesGroupName;
private slots:
  void AddButtonClicked();
  void ExerciseNameEditChanged();
  void MusculesGroupEditChanged();

public:
  AddExerciseDialog(QWidget * parent = nullptr);
  std::string GetExerciseName() const noexcept { return m_exerciseName; }
  std::string GetMusculesGroupName() const noexcept { return m_musculesGroupName; }
};

static bool IsLineEditEmpty(QLineEdit * edit) noexcept
{
  return edit->text().isEmpty();
}
