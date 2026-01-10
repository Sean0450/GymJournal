#pragma once

#include "ExercisesDocument.h"
#include "TrainingSession/TraningSessionsDocument.h"


class DocumentManager
{
  ExercisesDocument m_exerciseDoc;
  TraningSessionsDocument m_traningSessionsDoc;

public:
  ExercisesDocument& GetExercisesDocument() noexcept { return m_exerciseDoc; }
  TraningSessionsDocument& GetTraningsDocument() noexcept { return m_traningSessionsDoc; }
};
