#include "ExercisesDocument.h"


rapidjson::Value ExercisesDocument::TranslateStringToJson(const std::string & exercisename, const std::string & musculesGrioup,
                                                          rapidjson::Document & doc)
{
  rapidjson::Value converter;
  rapidjson::Value exercise(rapidjson::kObjectType);
  converter.SetString(exercisename.c_str(), doc.GetAllocator());
  rapidjson::Value resourcesDataConverter;
  resourcesDataConverter.SetString(Resources::exerciseName, doc.GetAllocator());
  exercise.AddMember(resourcesDataConverter, converter, doc.GetAllocator());
  converter.SetString(musculesGrioup.c_str(), doc.GetAllocator());
  resourcesDataConverter.SetString(Resources::musculesGroupLabel, doc.GetAllocator());
  exercise.AddMember(resourcesDataConverter, converter, doc.GetAllocator());
  return exercise;
}

std::optional<StringDataContainer> ExercisesDocument::GetStringFormat()
{
  auto jsonDoc = documentingFunctions::GetJsonFormat(m_path);
  if (!jsonDoc.value().HasParseError())
  {
    const rapidjson::Value & exercises = jsonDoc.value()[Resources::exercisesArrayName];
    StringDataContainer data;
    for (auto && it : exercises.GetArray())
    {
      data.AddData(it[Resources::exerciseName].GetString(), it[Resources::musculesGroupLabel].GetString());
    }
    return data;
  }
  return std::nullopt;
}

void ExercisesDocument::AddExercise(std::string_view exercisename, std::string_view musculesGroup)
{
  auto oldData = documentingFunctions::GetJsonFormat(m_path);
  rapidjson::Document doc;
  doc.SetObject();
  if (oldData.has_value() && !oldData.value().HasParseError())
  {
      oldData.value()[Resources::exercisesArrayName].PushBack(TranslateStringToJson(std::string(exercisename),
                                                                                    std::string(musculesGroup), oldData.value()),
                                                              oldData.value().GetAllocator());
      documentingFunctions::ReadOldData(oldData.value(), doc);
  }
  else
  {
    rapidjson::Value exercises(rapidjson::kArrayType);
    exercises.PushBack(TranslateStringToJson(std::string(exercisename), std::string(musculesGroup), doc), doc.GetAllocator());
    rapidjson::Value stringParser;
    stringParser.SetString(Resources::exercisesArrayName, doc.GetAllocator());
    doc.AddMember(stringParser, exercises, doc.GetAllocator());
  }
  documentingFunctions::WriteJsonToFile(doc, m_path);
}
