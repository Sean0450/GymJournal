#include "ExerciseName.hpp"

ExerciseName::ExerciseName(std::vector<std::string> && exerciseName)
  : m_exerciseName(exerciseName)
{
}

void ExerciseName::AddExerciseName(std::string && name)
{
  m_exerciseName.emplace_back(std::move(name));
}

bool ExerciseName::Empty() const
{
  return m_exerciseName.empty();
}

bool ExerciseName::AreEqual(const ExerciseName & exerciseName)
{
  bool result{true};
  for (int i = 0; i < static_cast<int>(exerciseName.m_exerciseName.size()); ++i)
  {
    if (m_exerciseName[i] != exerciseName.m_exerciseName[i])
    {
      result = false;
      break;
    }
  }
  return result;
}

std::vector<std::string> ExerciseName::Names() const
{
  return m_exerciseName;
}
