#include "TrainingSessionId.h"


TrainingSessionId::TrainingSessionId(std::string && date, size_t traningNumber)
{
  if (date.empty() or traningNumber == 0)
  {
    throw std::runtime_error("Inccoret input params");
  }
  m_id = date + "-" + std::to_string(traningNumber);
}

std::string TrainingSessionId::Id() const
{
  return m_id;
}
