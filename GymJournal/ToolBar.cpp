#include "ToolBar.h"


ToolBar::ToolBar(QWidget * parent)
  : QWidget(parent)
{
  auto buttonsLayout = new QHBoxLayout(this);
  m_statistics = new QPushButton(this);
  m_statistics->setText(Resources::statisticsButton);
  QObject::connect(m_statistics, &QPushButton::clicked, this, &ToolBar::StatisticsButtonClicked);
  buttonsLayout->addWidget(m_statistics);

  m_settings = new QPushButton(this);
  m_settings->setText(Resources::settingsButton);
  QObject::connect(m_settings, &QPushButton::clicked, this, &ToolBar::SettingsButtonClicked);
  buttonsLayout->addWidget(m_settings);
}

void ToolBar::StatisticsButtonClicked()
{
}

void ToolBar::SettingsButtonClicked()
{
}
