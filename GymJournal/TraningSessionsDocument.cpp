#include "TraningSessionsDocument.h"

void TraningSessionsDocument::AddTraningSession(const std::vector<std::string> & exercisesNames,
                                                const std::vector<std::string> & amountAndWeight, const std::string & traningDate)
{
  auto oldData = documentingFunctions::GetJsonFormat(m_path);
  rapidjson::Document jsonDoc;
  jsonDoc.SetObject();
  if (oldData.has_value())
  {
    documentingFunctions::ReadOldData(oldData.value(), jsonDoc);
  }

  rapidjson::Value traning(rapidjson::kArrayType);
  rapidjson::Value exerciseNamesConverter;
  rapidjson::Value amountAndWeightConverter;
  for (auto i = 0; i < exercisesNames.size(); ++i)
  {
    rapidjson::Value exercise(rapidjson::kObjectType);
    exerciseNamesConverter.SetString(exercisesNames[i].c_str(), jsonDoc.GetAllocator());
    amountAndWeightConverter.SetString(amountAndWeight[i].c_str(), jsonDoc.GetAllocator());
    exercise.AddMember(exerciseNamesConverter, amountAndWeightConverter, jsonDoc.GetAllocator());
    traning.PushBack(exercise, jsonDoc.GetAllocator());
  }
  rapidjson::Value dateConverter;
  dateConverter.SetString(traningDate.c_str(), jsonDoc.GetAllocator());
  jsonDoc.AddMember(dateConverter, traning, jsonDoc.GetAllocator());
  documentingFunctions::WriteJsonToFile(jsonDoc, m_path);
}

std::optional<std::vector<StringDataContainer>> TraningSessionsDocument::GetStringFormat()
{
  auto jsonDoc = documentingFunctions::GetJsonFormat(m_path);
  if (jsonDoc.has_value() && !jsonDoc.value().HasParseError())
  {
    std::vector<StringDataContainer> data;
    //Iterates document than iterates inside exerciseArray. At the end iterates inside array and makes every member a Value;
    for (auto && it : jsonDoc.value().GetObject())
    {
      data.emplace_back(StringDataContainer());
      for (auto && it2 : it.value.GetArray())
      {
        for (auto itr3 = it2.MemberBegin(); itr3 != it2.MemberEnd(); ++itr3)
        {
          data.back().AddData(itr3->name.GetString(), itr3->value.GetString());
        }
      }
    }
    return data;
  }
  return std::nullopt;
}
