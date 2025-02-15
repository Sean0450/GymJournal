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
  if (m_exercisesList.empty())
  {
    if (auto observer = m_observer.lock())
    {
      VectorToStringList(observer->GetExercisesTypes());
      m_traningDialog->SetExercisesNames(m_exercisesList);
    }
  }

  if (m_traningDialog->IsTraningEnded())
  {
    if (auto observer = m_observer.lock())
    {
      observer->AddTraningSessionButtonClicked();
    }
    m_traningDialog->deleteLater();
    m_traningDialog = new AddTraningSessionDialog(this);
  }
  m_traningDialog->exec();
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
  for (auto && it : existingExercises)
  {
    m_exercisesList.emplace_back(QString::fromStdString(it));
  }
}
