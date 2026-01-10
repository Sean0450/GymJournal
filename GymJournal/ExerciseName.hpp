#pragma once

#include <string>
#include <vector>

class ExerciseName
{
  std::vector<std::string> m_exerciseName;

public:
  ExerciseName() = default;
  ExerciseName(std::vector<std::string> && exerciseName);
  void AddExerciseName(std::string && name);
  bool Empty() const;
  bool AreEqual(const ExerciseName & exerciseName);
  std::vector<std::string> Names() const;
};
