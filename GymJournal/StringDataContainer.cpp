#include "StringDataContainer.h"


void StringDataContainer::SetName(const std::string& name) {
    m_name = name;
}
void StringDataContainer::AddData(const std::string & key, const std::string & value)
{
  m_container[key] = value;
}

const std::unordered_map<std::string, std::string> & StringDataContainer::GetAllData() const {
    return m_container;
}

std::vector<std::string> StringDataContainer::GetKeys() const
{
  std::vector<std::string> data;
  for (auto && it : m_container)
  {
    data.emplace_back(it.first);
  }
  return data;
}

std::vector<std::string> StringDataContainer::GetValues() const
{
  std::vector<std::string> data;
  for (auto && it : m_container)
  {
    data.emplace_back(it.second);
  }
  return data;
}
