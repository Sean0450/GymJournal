#pragma once

#include <string>


struct Exercise
{
  const std::string exerciseName;
  const std::string musculesGroup;

  Exercise(const std::string& exerciseName, const std::string& musculesGroup)
      : exerciseName(exerciseName)
      , musculesGroup(musculesGroup)
  {

  }
};