#include "ExercisesDocument.h"


rapidjson::Value ExercisesDocument::TranslateStringToJson(const std::string & exercisename, 
                                                          const std::string & musculesGroup,
                                                          rapidjson::Document & doc)
{
  using namespace rapidjson;
  auto& allocator{doc.GetAllocator()};
  Value exercise(rapidjson::kObjectType);

  exercise.AddMember(Value(Resources::exerciseName, allocator).Move(), 
                     Value(exercisename.c_str(), allocator).Move(),
                     allocator);
  exercise.AddMember(Value(Resources::musculesGroupLabel, doc.GetAllocator()).Move(),
                     Value(musculesGroup.c_str(), allocator).Move(), 
                     allocator);
  return exercise;
}

std::optional<StringDataContainer> ExercisesDocument::GetStringFormat()
{
  using namespace Resources;
  auto jsonDoc = documentingFunctions::GetJsonFormat(m_path);

  if (!jsonDoc.value().HasParseError())
  {
    const rapidjson::Value& exercises = jsonDoc.value()[exercisesArrayName];
    StringDataContainer data;
    for (auto && it : exercises.GetArray())
    {
      data.AddData(it[exerciseName].GetString(), it[musculesGroupLabel].GetString());
    }
    return data;
  }
  return std::nullopt;
}

void ExercisesDocument::AddExercise(std::string_view exercisename, std::string_view musculesGroup)
{
  using namespace rapidjson;
  using namespace Resources;

  auto oldData = documentingFunctions::GetJsonFormat(m_path);
  Document doc;
  doc.SetObject();

  if (oldData && !oldData.value().HasParseError())
  {
      oldData.value()[exercisesArrayName].PushBack(TranslateStringToJson(std::string(exercisename),
                                                                                    std::string(musculesGroup), oldData.value()),
                                                                                    oldData.value().GetAllocator());
      documentingFunctions::ReadOldData(oldData.value(), doc);
  }
  else
  {
    auto& allocator{doc.GetAllocator()};
    Value exercises(rapidjson::kArrayType);

    exercises.PushBack(TranslateStringToJson(std::string(exercisename), std::string(musculesGroup), doc), allocator);
    doc.AddMember(Value(exercisesArrayName, allocator).Move(), exercises, allocator);
  }
  documentingFunctions::WriteJsonToFile(doc, m_path);
}
