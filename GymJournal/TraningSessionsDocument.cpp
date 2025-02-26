#include "TraningSessionsDocument.h"

void TraningSessionsDocument::AddTraningSession(const std::vector<std::string> & exercisesNames,
                                                const std::vector<std::string> & amountAndWeight, const std::string & traningDate)
{
  auto jsonDoc = documentingFunctions::GetJsonFormat(m_path, WraperTypes::Write);
  jsonDoc.value().SetObject();
  rapidjson::Value traning(rapidjson::kArrayType);
  rapidjson::Value exerciseNamesConverter;
  rapidjson::Value amountAndWeightConverter;
  for (auto i = 0; i < exercisesNames.size(); ++i)
  {
    rapidjson::Value exercise(rapidjson::kObjectType);
    exerciseNamesConverter.SetString(exercisesNames[i].c_str(), jsonDoc.value().GetAllocator());
    amountAndWeightConverter.SetString(amountAndWeight[i].c_str(), jsonDoc.value().GetAllocator());
    exercise.AddMember(exerciseNamesConverter, amountAndWeightConverter, jsonDoc.value().GetAllocator());
    traning.PushBack(exercise, jsonDoc.value().GetAllocator());
  }
  rapidjson::Value dateConverter;
  dateConverter.SetString(traningDate.c_str(), jsonDoc.value().GetAllocator());
  jsonDoc.value().AddMember(dateConverter, traning, jsonDoc.value().GetAllocator());
  std::ofstream file(m_path);
  if (!file.is_open())
  {
    return;
  }
  rapidjson::OStreamWrapper osw{file};
  rapidjson::Writer<rapidjson::OStreamWrapper> writer2{osw};
  jsonDoc.value().Accept(writer2);
}

std::optional<std::vector<StringDataContainer>> TraningSessionsDocument::GetStringFormat()
{
  auto jsonDoc = documentingFunctions::GetJsonFormat(m_path, WraperTypes::Read);
  if (!jsonDoc.value().HasParseError())
  {
    std::vector<StringDataContainer> data(jsonDoc.value().Size());
    for (auto i = 0; i < jsonDoc.value().Size(); ++i)
    {
      data[i].SetName(jsonDoc.value().GetString());
      for (auto j = 0; j < jsonDoc.value()[i].Size(); ++j)
      {
        data[i].AddData(jsonDoc.value()[i][j]["Exercise name"].GetString(),
                        jsonDoc.value()[i][j]["Amount and Weight"].GetString());
      }
    }
    return data;
  }
  return std::nullopt;
}

rapidjson::Value TraningSessionsDocument::TranslateStringToJson(const std::string & exercisename,
                                                                const std::string & musculesGrioup, rapidjson::Document & doc)
{
  return rapidjson::Value();
}
