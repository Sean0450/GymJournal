#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_GymJournal.h"


class ExercisesPanel;
class ToolBar;
class TraningSessionsPanel;

class GymJournal : public QMainWindow
{
  Q_OBJECT
  ExercisesPanel* m_exercisePanel = nullptr;
  TraningSessionsPanel* m_traningPanel = nullptr;
  ToolBar* m_toolBar = nullptr;
  Ui::GymJournalClass m_ui;

public:
  GymJournal(QWidget * parent = nullptr);
  ExercisesPanel* GetExercisePanel() const noexcept { return m_exercisePanel; }
  TraningSessionsPanel* GetTraningSessionPanel() const noexcept { return m_traningPanel; }
  ToolBar* GetToolBar() const noexcept { return m_toolBar; }
  ~GymJournal() = default;
};
