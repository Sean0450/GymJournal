#pragma once

#include <stdexcept>
#include <string>


class TrainingSessionId
{
  std::string m_id;

public:
  TrainingSessionId(std::string && date, size_t traningNumber);
  std::string Id() const;
};
