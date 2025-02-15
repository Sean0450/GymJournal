#include "ExercisesDocument.h"


rapidjson::Value ExercisesDocument::TranslateExerciseToJson(const std::string & exercisename, const std::string & musculesGrioup, rapidjson::Document&  doc)
{
  rapidjson::Value converter;
  rapidjson::Value exercise(rapidjson::kObjectType);
  converter.SetString(exercisename.c_str(), doc.GetAllocator());
  exercise.AddMember("Exercise name", converter, doc.GetAllocator());
  converter.SetString(musculesGrioup.c_str(), doc.GetAllocator());
  exercise.AddMember("Muscules group", converter, doc.GetAllocator());
  return exercise;
}

std::optional<rapidjson::Document> ExercisesDocument::GetJsonFormat()
{
  std::ifstream doc(m_path);
  if (doc.is_open())
  {
    rapidjson::Document jsonDoc;
    rapidjson::IStreamWrapper wrapper(doc);
    jsonDoc.ParseStream(wrapper);
    return jsonDoc;
  }
  return std::nullopt;
}

std::optional<std::vector<ExerciseContainer>> ExercisesDocument::GetStringFormat()
{
  auto jsonDoc = GetJsonFormat();
  if (!jsonDoc.value().HasParseError())
  {
    const rapidjson::Value & exercises = jsonDoc.value()["exercises"];
    std::vector<ExerciseContainer> data;
    for (rapidjson::SizeType i = 0; i < exercises.Size(); ++i)
    {
      data.emplace_back(ExerciseContainer(exercises[i]["Exercise name"].GetString(), exercises[i]["Muscules group"].GetString()));
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
    auto exercisesData = data.value();
    for (auto i = 0; i < exercisesData.size(); ++i)
    {
      exercises.PushBack(TranslateExerciseToJson(exercisesData[i].GetExercise(), exercisesData[i].GetMusculesGroup(), doc),
                         doc.GetAllocator());
    }
  }
  exercises.PushBack(TranslateExerciseToJson(std::string(exercisename), std::string(musculesGroup), doc), doc.GetAllocator());
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
