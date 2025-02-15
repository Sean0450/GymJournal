#pragma once

#include <fstream>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

#include "ExerciseContainer.h"

#include "rapidjson-master/include/rapidjson/document.h"
#include "rapidjson-master/include/rapidjson/istreamwrapper.h"
#include "rapidjson-master/include/rapidjson/writer.h"


class ExercisesDocument
{
  const std::string m_path = "ExercisesList.json";

  rapidjson::Value TranslateExerciseToJson(const std::string & exercisename, const std::string & musculesGrioup, rapidjson::Document & doc);
  std::optional<rapidjson::Document> GetJsonFormat();

public:
  std::optional<std::vector<ExerciseContainer>> GetStringFormat();
  void AddExercise(std::string_view exercisename, std::string_view musculesGroup);
};
