#pragma once

#include <filesystem>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

namespace utils {

	struct ImageInfo {
		std::string Name;
		uint16_t Width; 
		uint16_t Height;
		uint16_t Channels;
	};

	struct FoldersInfo {
		std::string InputFiles;
		std::string OutputFiles;
	};

	struct Configuration {
		ImageInfo ImageInfo;
		FoldersInfo foldersInfo;
	};

	// Conversion functions for ImageInfo
	void to_json(json& j, const ImageInfo& mpi);
	void from_json(const json& j, ImageInfo& mpi);

	// Conversion functions for FoldersInfo
	void to_json(json& j, const FoldersInfo& fi);
	void from_json(const json& j, FoldersInfo& fi);

	// Conversion functions for Configuration
	void to_json(json& j, const Configuration& config);
	void from_json(const json& j, Configuration& config);

	size_t getTotalBytes(uint16_t width, uint16_t height, uint16_t channels);

} // namespace utils

namespace path {

	static const std::filesystem::path assets_dir =
		std::filesystem::current_path() / "Assets";

	inline std::filesystem::path input_dir(const utils::FoldersInfo& fi) {
		return assets_dir / fi.InputFiles;
	}

	inline std::filesystem::path output_dir(const utils::FoldersInfo& fi) {
		return assets_dir / fi.OutputFiles;
	}

} // namespace path
