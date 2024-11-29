#include "serializer.h"
#include <sstream>

// XML

// Helper function for escaping special characters in XML
std::string EscapeXML(const std::string &data)
{
	std::string escaped;
	for (char c : data)
	{
		switch (c)
		{
		case '&': escaped += "&amp;"; break;
		case '<': escaped += "&lt;"; break;
		case '>': escaped += "&gt;"; break;
		case '\"': escaped += "&quot;"; break;
		case '\'': escaped += "&apos;"; break;
		default: escaped += c; break;
		}
	}
	return escaped;
}

std::string ToXML(const std::string &tagName, const std::map<Key, std::string> &data, const std::string &indent)
{
	std::string result = indent + "<" + tagName + ">\n";
	for (const auto &[key, value] : data)
	{
		result += indent + INDENT_STEP + "<" + key + ">" + EscapeXML(value) + "</" + key + ">\n";
	}
	result += indent + "</" + tagName + ">\n";
	return result;
}

std::string ToXML(const std::string &tagName, const std::vector<std::string> &data, const std::string &indent)
{
	std::string result = indent + "<" + tagName + ">\n";
	for (const auto &value : data)
	{
		result += indent + INDENT_STEP + "<item>" + EscapeXML(value) + "</item>\n";
	}
	result += indent + "</" + tagName + ">\n";
	return result;
}

std::string ToXML(const std::string &tagName, const std::string &data, const std::string &indent)
{
	return indent + "<" + tagName + ">" + EscapeXML(data) + "</" + tagName + ">\n";
}

// JSON

std::string ToJSON(const std::string &tagName, const std::map<Key, std::string> &data, const std::string &indent)
{
	std::string result = indent + '"' + tagName + "\": {\n";
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		result += indent + INDENT_STEP + '"' + it->first + "\": \"" + it->second + "\"";
		if (std::next(it) != data.end()) result += ",";
		result += "\n";
	}
	result += indent + "}";
	return result;
}

std::string ToJSON(const std::string &tagName, const std::vector<std::string> &data, const std::string &indent)
{
	std::string result = indent + '"' + tagName + "\": [\n";
	for (size_t i = 0; i < data.size(); ++i)
	{
		result += indent + INDENT_STEP + '"' + data[i] + '"';
		if (i != data.size() - 1) result += ",";
		result += "\n";
	}
	result += indent + "]";
	return result;
}

std::string ToJSON(const std::string &tagName, const std::string &data, const std::string &indent)
{
	return indent + '"' + tagName + "\": \"" + data + '"';
}

// YAML

std::string ToYAML(const std::string &tagName, const std::map<Key, std::string> &data, const std::string &indent)
{
	std::string result = indent + tagName + ":\n";
	for (const auto &[key, value] : data)
	{
		result += indent + INDENT_STEP + key + ": " + value + "\n";
	}
	return result;
}

std::string ToYAML(const std::string &tagName, const std::vector<std::string> &data, const std::string &indent)
{
	std::string result = indent + tagName + ":\n";
	for (const auto &value : data)
	{
		result += indent + INDENT_STEP + "- " + value + "\n";
	}
	return result;
}

std::string ToYAML(const std::string &tagName, const std::string &data, const std::string &indent)
{
	return indent + tagName + ": " + data + "\n";
}
