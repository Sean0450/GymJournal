#pragma once

#include <QtWidgets>
#include <vector>

#include "Resources.h"


class AddTraningSessionDialog : public QDialog
{
  Q_OBJECT
  QPushButton * m_addExerciseButton = nullptr;
  QPushButton * m_endTraningButton = nullptr;
  QVBoxLayout * m_layout = nullptr;
  QStringList m_existingExercises;
  std::vector<std::string> m_exercisesName;
  std::vector<std::string> m_amountAndWeight;
  struct ExerciseWidget
  {
    ExerciseWidget(QWidget * parent = nullptr, const QStringList & existingExercises = QStringList());
    QWidget * m_widget = nullptr;
    QComboBox * m_chooseExercise = nullptr;
    QLineEdit * m_amountEdit = nullptr;
    QLineEdit * m_weightEdit = nullptr;
    QPushButton * m_deleteButton = nullptr;
  };
  std::vector<ExerciseWidget> m_addedExercises;
  bool m_traningIsEnd = false;
  void AddExerciseLineEdit();
private slots:
  void AddExerciseButtonclicked();
  void EndTraningButtonClicked();
  void DeleteButtonClicked(QWidget * widget);

public:
  AddTraningSessionDialog(QWidget * parent = nullptr);
  bool IsTraningEnded() const noexcept { return m_traningIsEnd; }
  void SetExercisesNames(const QStringList & existingExercises);
};
