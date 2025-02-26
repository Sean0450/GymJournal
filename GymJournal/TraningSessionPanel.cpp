#include "TraningSessionsPanel.h"

TraningSessionsPanel::TraningSessionsPanel(QWidget * parent)
  : QWidget(parent)
{
  auto vlayout = new QVBoxLayout(this);
  m_addTraningSessionButton = new QPushButton(this);
  m_addTraningSessionButton->setText(Resources::addTraningDay);
  QObject::connect(m_addTraningSessionButton, &QPushButton::clicked, this, &TraningSessionsPanel::AddTraningSessionButtonClicked);
  vlayout->addWidget(m_addTraningSessionButton);

  m_viewAllTraningSessionsButton = new QPushButton(this);
  m_viewAllTraningSessionsButton->setText(Resources::viewAllTranings);
  QObject::connect(m_viewAllTraningSessionsButton, &QPushButton::clicked, this,
                   &TraningSessionsPanel::ViewAllTraningSessionsButtonClicked);
  vlayout->addWidget(m_viewAllTraningSessionsButton);
  m_traningDialog = new AddTraningSessionDialog(this);
}

void TraningSessionsPanel::SetObserver(std::weak_ptr<TraningSessionPanelObserver> observer)
{
  m_observer = std::move(observer);
}

void TraningSessionsPanel::AddTraningSessionButtonClicked()
{
  if (auto observer = m_observer.lock())
  {
    VectorToStringList(observer->GetExercisesTypes());
    m_traningDialog->SetExercisesNames(m_exercisesList);
  }
  m_traningDialog->exec();
  if (m_traningDialog->IsTraningEnded())
  {
    if (auto observer = m_observer.lock())
    {
      observer->AddTraningSessionButtonClicked(m_traningDialog->GetExercisesNames(), m_traningDialog->GetAmountAndWeight(),
                                               QDateTime::currentDateTime().toString().toStdString());
    }
    m_traningDialog->deleteLater();
    m_traningDialog = new AddTraningSessionDialog(this);
  }
}

void TraningSessionsPanel::ViewAllTraningSessionsButtonClicked()
{
  if (auto observer = m_observer.lock())
  {
    observer->ViewAllTraningSessionsButtonClicked();
  }
}

void TraningSessionsPanel::VectorToStringList(const std::vector<std::string> & existingExercises)
{
  m_exercisesList.resize(existingExercises.size());
  for (auto i = 0; i < existingExercises.size(); ++i)
  {
    m_exercisesList[i] = QString::fromStdString(existingExercises[i]);
  }
}
