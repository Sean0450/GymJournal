#pragma once

#include <QtWidgets>

#include "Resources.h"


class ToolBar : public QWidget
{
  Q_OBJECT
  QPushButton * m_settings = nullptr;
  QPushButton * m_statistics = nullptr;
private slots:
	void SettingsButtonClicked();
	void StatisticsButtonClicked();
public:
  ToolBar(QWidget * parent = nullptr);
};
