#include "TraningSessionsDocument.h"

void TraningSessionsDocument::AddTraningSession(const std::vector<std::string> & exercisesNames,
                                                const std::vector<std::string> & amountAndWeight, 
                                                const std::string & traningDate)
{
  using namespace documentingFunctions;

  auto oldData = GetJsonFormat(m_path);
  rapidjson::Document jsonDoc;
  auto & allocator{jsonDoc.GetAllocator()};
  jsonDoc.SetObject();

  if (oldData && !oldData.value().HasParseError())
  {
    ReadOldData(oldData.value(), jsonDoc);
  }

  jsonDoc.AddMember(rapidjson::Value(traningDate.c_str(), allocator).Move(), 
                    TranslateStringToJson(exercisesNames, amountAndWeight, jsonDoc),
                    allocator);
  WriteJsonToFile(jsonDoc, m_path);
}

std::optional<std::vector<StringDataContainer>> TraningSessionsDocument::GetStringFormat()
{
  auto jsonDoc = documentingFunctions::GetJsonFormat(m_path);
  if (jsonDoc && !jsonDoc.value().HasParseError())
  {
    std::vector<StringDataContainer> data;
    //Iterates document than iterates inside exerciseArray. At the end iterates inside array and makes every member a Value;
    for (auto && documentObject : jsonDoc.value().GetObject())
    {
      data.emplace_back(StringDataContainer());
      for (auto && array : documentObject.value.GetArray())
      {
        for (auto arrayElement = array.MemberBegin(); arrayElement != array.MemberEnd(); ++arrayElement)
        {
          data.back().AddData(arrayElement->name.GetString(), arrayElement->value.GetString());
        }
      }
    }
    return data;
  }
  return std::nullopt;
}

rapidjson::Value TraningSessionsDocument::TranslateStringToJson(const std::vector<std::string> & exercisesNames,
                                                                const std::vector<std::string> & amountAndWeight,
                                                                rapidjson::Document & jsonDoc)
{
  using namespace rapidjson;
  auto & allocator{jsonDoc.GetAllocator()};
  Value traning(rapidjson::kArrayType);

  for (int i = 0; i < static_cast<int>(exercisesNames.size()); ++i)
  {
    Value exercise(kObjectType);
    exercise.AddMember(Value(exercisesNames[i].c_str(), allocator).Move(), 
                       Value(amountAndWeight[i].c_str(), allocator).Move(),
                       allocator);
    traning.PushBack(exercise, allocator);
  }
  return traning;
}
