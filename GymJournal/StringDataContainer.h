#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <optional>

class StringDataContainer {
	std::unordered_map<std::string, std::string> m_container;
	std::optional<std::string> m_name;
public:
	void AddData(const std::string& key, const std::string& value);
	void SetName(const std::string& name);
	const std::unordered_map<std::string, std::string> & GetAllData() const;
	std::vector<std::string> GetKeys() const;
	std::vector<std::string> GetValues() const;
};