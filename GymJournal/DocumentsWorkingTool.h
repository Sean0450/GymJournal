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


enum class WraperTypes
{
  Read,
  Write
};

namespace documentingFunctions
{
std::optional<rapidjson::Document> GetJsonFormat(const std::string & path, WraperTypes type);

}
