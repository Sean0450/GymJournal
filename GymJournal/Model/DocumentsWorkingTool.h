#pragma once

#include <fstream>
#include <iostream>
#include <optional>

#include "StringDataContainer.h"

#include "rapidjson-master/include/rapidjson/document.h"
#include "rapidjson-master/include/rapidjson/istreamwrapper.h"
#include "rapidjson-master/include/rapidjson/ostreamwrapper.h"
#include "rapidjson-master/include/rapidjson/rapidjson.h"
#include "rapidjson-master/include/rapidjson/writer.h"


namespace documentingFunctions
{
std::optional<rapidjson::Document> GetJsonFormat(const std::string & path);
void WriteJsonToFile(rapidjson::Document & doc, const std::string & path);
void ReadOldData(rapidjson::Document & readingDocument, rapidjson::Document & writingDocument);
} // namespace documentingFunctions
