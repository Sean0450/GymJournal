#pragma once

#include <string>
#include <vector>


class ExerciseContainer
{
  std::string m_exercise;
  std::string m_musculesGroup;

public:
  explicit ExerciseContainer(const std::string & exercise, const std::string & musculesGroup) noexcept
    : m_exercise(exercise)
    , m_musculesGroup(musculesGroup)
  {
  }
  const std::string & GetExercise() const noexcept { return m_exercise; }
  const std::string & GetMusculesGroup() const noexcept { return m_musculesGroup; }
};

std::vector<std::string> GetExercisesName(const std::vector<ExerciseContainer>& exercises);
