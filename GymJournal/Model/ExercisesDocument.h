#pragma once

#include "DocumentsWorkingTool.h"
#include "Resources.h"

struct Exercise;

class ExercisesDocument
{
  const std::string m_path = "Model/ExercisesList.json";

  rapidjson::Value TranslateStringToJson(const std::string & exercisename, const std::string & musculesGrioup,
                                         rapidjson::Document & doc);

public:
  std::optional<StringDataContainer> GetStringFormat();
  void AddExercise(Exercise&& exercise);
};
