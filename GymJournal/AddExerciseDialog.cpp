#include "AddExerciseDialog.h"


AddExerciseDialog::AddExerciseDialog(QWidget * parent)
  : QDialog(parent)
{
  auto vlayout = new QVBoxLayout(this);
  auto firstHLayout = new QHBoxLayout(this);

  auto exerciseLabel = new QLabel(this);
  exerciseLabel->setText(Resources::exerciseLabel);
  firstHLayout->addWidget(exerciseLabel);
  m_exerciseNameEdit = new QLineEdit(this);
  QObject::connect(m_exerciseNameEdit, &QLineEdit::textChanged, this, &AddExerciseDialog::ExerciseNameEditChanged);
  firstHLayout->addWidget(m_exerciseNameEdit);
  vlayout->addLayout(firstHLayout);

  auto secondHLayout = new QHBoxLayout(this);
  auto musculesLabel = new QLabel(this);
  musculesLabel->setText(Resources::musculesGroupLabel);
  secondHLayout->addWidget(musculesLabel);
  m_musculesGroupNameEdit = new QLineEdit(this);
  QObject::connect(m_musculesGroupNameEdit, &QLineEdit::textChanged, this, &AddExerciseDialog::MusculesGroupEditChanged);
  secondHLayout->addWidget(m_musculesGroupNameEdit);
  vlayout->addLayout(secondHLayout);

  m_addButton = new QPushButton(this);
  QObject::connect(m_addButton, &QPushButton::clicked, this, &AddExerciseDialog::AddButtonClicked);
  m_addButton->setText(Resources::addButton);
  m_addButton->setEnabled(false);
  vlayout->addWidget(m_addButton);
}

void AddExerciseDialog::AddButtonClicked()
{
  m_exerciseName = m_exerciseNameEdit->text().toStdString();
  m_musculesGroupName = m_musculesGroupNameEdit->text().toStdString();
  close();
}

void AddExerciseDialog::ExerciseNameEditChanged()
{
  if (!IsLineEditEmpty(m_musculesGroupNameEdit))
  {
    m_addButton->setEnabled(true);
  }
  else
  {
    m_addButton->setEnabled(false);
  }
}

void AddExerciseDialog::MusculesGroupEditChanged()
{
  if (!IsLineEditEmpty(m_exerciseNameEdit))
  {
    m_addButton->setEnabled(true);
  }
  else
  {
    m_addButton->setEnabled(false);
  }
}
