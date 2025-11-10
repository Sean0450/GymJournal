#include "AddTraningSessionDialog.h"

AddTraningSessionDialog::AddTraningSessionDialog(QWidget * parent)
  : QDialog(parent)
{
  setWindowTitle(Resources::traningSessionTitle);
  auto mainLayout = new QVBoxLayout(this);
  m_layout = new QVBoxLayout(this);

  auto dateLabel = new QLabel(this);
  dateLabel->setText(QDate::currentDate().toString());

  m_addExerciseButton = new QPushButton(this);
  m_addExerciseButton->setText(Resources::addExercise);
  QObject::connect(m_addExerciseButton, &QPushButton::clicked, this, &AddTraningSessionDialog::AddExerciseButtonclicked);

  m_endTraningButton = new QPushButton(this);
  m_endTraningButton->setText(Resources::endTraningButton);
  QObject::connect(m_endTraningButton, &QPushButton::clicked, this, &AddTraningSessionDialog::EndTraningButtonClicked);

  auto buttonsLayout = new QHBoxLayout(this);
  buttonsLayout->addWidget(m_addExerciseButton);
  buttonsLayout->addWidget(m_endTraningButton);
  mainLayout->addWidget(dateLabel);
  mainLayout->addLayout(m_layout);
  mainLayout->addLayout(buttonsLayout);
}

void AddTraningSessionDialog::AddExerciseButtonclicked()
{
  ExerciseWidget exerciseWidget(this, m_existingExercises);
  QObject::connect(exerciseWidget.m_deleteButton, &QPushButton::clicked, this,
                   [=]() { AddTraningSessionDialog::DeleteButtonClicked(exerciseWidget.m_widget); });
  ExerciseWidget::BlockUnblockPreviousExerciseEdit(m_addedExercises, false);
  m_layout->addWidget(exerciseWidget.m_widget);
  m_addedExercises.emplace_back(exerciseWidget);
}

void AddTraningSessionDialog::EndTraningButtonClicked()
{
  for (auto && it : m_addedExercises)
  {
    m_exercisesName.emplace_back(it.m_chooseExercise->currentText().toStdString());
    auto amount = it.m_amountEdit->text().toStdString();
    auto weight = it.m_weightEdit->text().toStdString();
    assert(!amount.empty() and !weight.empty());
    m_amountAndWeight.emplace_back(amount + Resources::x + weight);
  }
  m_traningIsEnd = true;
  close();
}

void AddTraningSessionDialog::DeleteButtonClicked(QWidget * widget)
{
  widget->deleteLater();
  m_addedExercises.pop_back();
  ExerciseWidget::BlockUnblockPreviousExerciseEdit(m_addedExercises, false);
}

AddTraningSessionDialog::ExerciseWidget::ExerciseWidget(QWidget * parent, const QStringList & existingExercises)
{
  m_widget = new QWidget(parent);
  auto hLayout = new QHBoxLayout(parent);
  m_widget->setLayout(hLayout);
  auto exerciseLabel = new QLabel(parent);
  exerciseLabel->setText(Resources::exerciseLabel);
  hLayout->addWidget(exerciseLabel);

  m_chooseExercise = new QComboBox(parent);
  m_chooseExercise->addItems(existingExercises);
  hLayout->addWidget(m_chooseExercise);

  auto amountLabel = new QLabel(parent);
  amountLabel->setText(Resources::amountLabel);
  hLayout->addWidget(amountLabel);

  m_amountEdit = new QLineEdit(parent);
  hLayout->addWidget(m_amountEdit);

  auto xLabel = new QLabel(parent);
  xLabel->setText(Resources::x);
  hLayout->addWidget(xLabel);

  auto weightLabel = new QLabel(parent);
  weightLabel->setText(Resources::weightLabel);
  hLayout->addWidget(weightLabel);

  m_weightEdit = new QLineEdit(parent);
  hLayout->addWidget(m_weightEdit);

  m_deleteButton = new QPushButton(parent);
  m_deleteButton->setText(Resources::deleteButton);
  hLayout->addWidget(m_deleteButton);
}

void AddTraningSessionDialog::SetExercisesNames(const QStringList & existingExercises)
{
  m_existingExercises = existingExercises;
  //Rewrite combobox values
  for (auto && it : m_addedExercises)
  {
    it.SetItem(m_existingExercises);
  }
}

void AddTraningSessionDialog::ExerciseWidget::SetItem(const QStringList & existingExercises)
{
  m_chooseExercise->clear();
  m_chooseExercise->addItems(existingExercises);
}

void AddTraningSessionDialog::ExerciseWidget::BlockUnblockPreviousExerciseEdit(const std::vector<ExerciseWidget> & widgets,
                                                                               bool flag)
{
  if (!widgets.empty())
  {
    widgets.back().m_deleteButton->setEnabled(flag);
    widgets.back().m_chooseExercise->setEnabled(flag);
    widgets.back().m_weightEdit->setEnabled(flag);
    widgets.back().m_amountEdit->setEnabled(flag);
  }
}
