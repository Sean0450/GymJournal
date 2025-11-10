#include "DocumentsWorkingTool.h"

namespace documentingFunctions
{
std::optional<rapidjson::Document> GetJsonFormat(const std::string & path)
{
  std::ifstream doc(path);
  if (doc.is_open())
  {
    rapidjson::Document jsonDoc;
    rapidjson::IStreamWrapper wrapper(doc);
    jsonDoc.ParseStream(wrapper);
    return jsonDoc;
  }
  return std::nullopt;
}

void ReadOldData(rapidjson::Document & readingDocument, rapidjson::Document & writingDocument)
{
  if (readingDocument.IsObject())
  {
    for (auto && it : readingDocument.GetObject())
    {
      writingDocument.AddMember(it.name, it.value, writingDocument.GetAllocator());
    }
  }
}

void WriteJsonToFile(rapidjson::Document & doc, const std::string & path)
{
  std::ofstream file(path);
  if (!file.is_open())
  {
    return;
  }
  rapidjson::OStreamWrapper osw{file};
  rapidjson::Writer<rapidjson::OStreamWrapper> writer2{osw};
  doc.Accept(writer2);
  file.close();
}

} // namespace documentingFunctions
