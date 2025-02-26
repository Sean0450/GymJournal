#include "ExercisesDocument.h"


rapidjson::Value ExercisesDocument::TranslateStringToJson(const std::string & exercisename, const std::string & musculesGrioup,
                                                          rapidjson::Document & doc)
{
  rapidjson::Value converter;
  rapidjson::Value exercise(rapidjson::kObjectType);
  converter.SetString(exercisename.c_str(), doc.GetAllocator());
  exercise.AddMember("Exercise name", converter, doc.GetAllocator());
  converter.SetString(musculesGrioup.c_str(), doc.GetAllocator());
  exercise.AddMember("Muscules group", converter, doc.GetAllocator());
  return exercise;
}

std::optional<StringDataContainer> ExercisesDocument::GetStringFormat()
{
  auto jsonDoc = documentingFunctions::GetJsonFormat(m_path, WraperTypes::Read);
  if (!jsonDoc.value().HasParseError())
  {
    const rapidjson::Value & exercises = jsonDoc.value()["exercises"];
    StringDataContainer data;
    for (auto i = 0; i < exercises.Size(); ++i)
    {
      data.AddData(exercises[i]["Exercise name"].GetString(), exercises[i]["Muscules group"].GetString());
    }
    return data;
  }
  return std::nullopt;
}

void ExercisesDocument::AddExercise(std::string_view exercisename, std::string_view musculesGroup)
{
  rapidjson::Document doc;
  doc.SetObject();
  rapidjson::Value exercises(rapidjson::kArrayType);
  auto data = GetStringFormat();
  if (data.has_value())
  {
    auto exercisesData = data.value().GetAllData();
    for (const auto & [exercise, musculeGroup] : exercisesData)
    {
      exercises.PushBack(TranslateStringToJson(exercise, musculeGroup, doc), doc.GetAllocator());
    }
  }
  exercises.PushBack(TranslateStringToJson(std::string(exercisename), std::string(musculesGroup), doc), doc.GetAllocator());
  doc.AddMember("exercises", exercises, doc.GetAllocator());
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
  doc.Accept(writer);
  std::ofstream file(m_path);
  if (!file.is_open())
  {
    return;
  }
  file << buffer.GetString();
  file.close();
}
