#pragma once

#include <QtWidgets>

#include "AddTraningSessionDialog.h"
#include "Resources.h"
#include "TraningSessionPanelObserver.h"


class TraningSessionsPanel : public QWidget
{
  Q_OBJECT
  QPushButton * m_addTraningSessionButton = nullptr;
  QPushButton * m_viewAllTraningSessionsButton = nullptr;
  AddTraningSessionDialog * m_traningDialog = nullptr;
  std::weak_ptr<TraningSessionPanelObserver> m_observer;
  QStringList m_exercisesList;
  void VectorToStringList(const std::vector<std::string>& existineExercises);
private slots:
  void AddTraningSessionButtonClicked();
  void ViewAllTraningSessionsButtonClicked();

public:
  TraningSessionsPanel(QWidget * parent = nullptr);
  void SetObserver(std::weak_ptr<TraningSessionPanelObserver> observer);
};
