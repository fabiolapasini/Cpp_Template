#include <fstream>
#include <iostream>
#include <string>

#include "include/utils.h"
#include "include/template.h"

using json = nlohmann::json;

int main() {

	std::filesystem::path config_json_file = path::assets_dir / "config.json";
	std::ifstream file(config_json_file);
	if (!file.is_open()) {
		std::cout << "Impossible to open config.json";
		return 1;
	}

	json j;
	file >> j;
	utils::Configuration config;
	try {
		config = j.get<utils::Configuration>();
	}
	catch (const json::exception& e) {
		std::cout << "Error during JSON parsing: " << e.what();
		return 1;
	}

	runProgram(config);

	return 0;
}
