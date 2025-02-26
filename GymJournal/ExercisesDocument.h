#pragma once

#include "DocumentsWorkingTool.h"
#include "Resources.h"


class ExercisesDocument
{
  const std::string m_path = "ExercisesList.json";

  rapidjson::Value TranslateStringToJson(const std::string & exercisename, const std::string & musculesGrioup,
                                         rapidjson::Document & doc);

public:
  std::optional<StringDataContainer> GetStringFormat();
  void AddExercise(std::string_view exercisename, std::string_view musculesGroup);
};
