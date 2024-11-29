#include "serializer.h"
#include <iostream>
#include <fstream>
#include <string>

void saveToFile(std::string data, std::string filePath)
{
	std::ofstream outFile(filePath);

	if (outFile.is_open())
	{
		outFile << data;
		outFile.close();
	}
	else
	{
		std::cerr << "Error opening file for writing!" << std::endl;
	}
}


int main() {

	const auto dataName = "data";
	std::string xml, json, yaml;
	using MyNode = Node<std::map<Key, std::string>, std::vector<std::string>, std::string>;
	auto data = std::map<Key, MyNode>{
			{"key_to_map",    std::map<Key, std::string>{{"key1","value1"}, {"key2","value2"}}},
			{"key_to_vector", std::vector<std::string>{"string from vector 1", "string from vector 2"}},
			{"key_to_string", "this is a string"},
	};

	std::cout << "Here's how this structure looks in XML:\n";
	xml = ToXML(dataName, data);
	saveToFile(xml, "example.xml");
		std::cout << xml;

	std::cout << "\nThis is its representation in JSON:\n";
	json = "{\n" + ToJSON(dataName, data, INDENT_STEP) + "}\n";
	saveToFile(json, "example.json");
	std::cout << json;

	std::cout << "\nAnd finally, YAML:\n";
	yaml = ToYAML(dataName, data);
	saveToFile(yaml, "example.yaml");
	std::cout << yaml;

	return 0;
}