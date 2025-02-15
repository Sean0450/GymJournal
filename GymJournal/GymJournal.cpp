#include "GymJournal.h"

GymJournal::GymJournal(QWidget * parent)
  : QMainWindow(parent)
{
  m_ui.setupUi(this);
  auto hlayout = new QHBoxLayout(m_ui.centralWidget);
  m_exercisePanel = new ExercisesPanel(this);
  m_traningPanel = new TraningSessionsPanel(this);
  hlayout->addWidget(m_traningPanel);
  hlayout->addWidget(m_exercisePanel);

  m_toolBar = new ToolBar(this);
  m_ui.mainToolBar->addWidget(m_toolBar);
}
