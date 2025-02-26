#pragma once

#include "DocumentsWorkingTool.h"

class TraningSessionsDocument
{
  const std::string m_path = "TraningSessions.json";
  rapidjson::Value TranslateStringToJson(const std::string & exercisename, const std::string & musculesGrioup,
                                         rapidjson::Document & doc);

public:
  std::optional<std::vector<StringDataContainer>> GetStringFormat();
  void AddTraningSession(const std::vector<std::string> & exercisesNames, const std::vector<std::string> & amountAndWeight,
                         const std::string & traningDate);
};
