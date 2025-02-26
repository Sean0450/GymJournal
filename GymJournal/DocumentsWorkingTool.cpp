#include "DocumentsWorkingTool.h"

namespace documentingFunctions
{
std::optional<rapidjson::Document> GetJsonFormat(const std::string & path, WraperTypes type)
{
  std::ifstream doc(path);
  if (doc.is_open())
  {
    rapidjson::Document jsonDoc;
    switch (type)
    {
    case WraperTypes::Read: {
        rapidjson::IStreamWrapper wrapper(doc);
        jsonDoc.ParseStream(wrapper);
        return jsonDoc;
    }
    case WraperTypes::Write: {

        std::ofstream file(path);
        rapidjson::OStreamWrapper osw(file);
        rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
        jsonDoc.Accept(writer);
        return jsonDoc;
    }
    }
  }
  return std::nullopt;
}

} // namespace documentingFunctions
