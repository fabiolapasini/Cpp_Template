#include <filesystem>
#include <fstream>
#include <sstream>

#include "../include/utils.h"

namespace utils {

// conversion functions for MapperProducerInfo
void to_json(json& j, const utils::ImageInfo& mpi) {
    j = json{{"Name", mpi.Name},
             {"Width", mpi.Width},
             {"Height", mpi.Height},
             {"Channels", mpi.Channels}};
}
void from_json(const json& j, utils::ImageInfo& mpi) {
    j.at("Name").get_to(mpi.Name);
    mpi.Width =
        static_cast<uint16_t>(std::stoi(j.at("Width").get<std::string>()));
    mpi.Height =
        static_cast<uint16_t>(std::stoi(j.at("Height").get<std::string>()));
    mpi.Channels =
        static_cast<uint16_t>(std::stoi(j.at("Channels").get<std::string>()));
}

// conversion functions for FoldersInfo
void to_json(json& j, const utils::FoldersInfo& fi) {
    j = json{{"InputFiles", fi.InputFiles}, {"OutputFiles", fi.OutputFiles}};
}
void from_json(const json& j, utils::FoldersInfo& fi) {
    j.at("InputFiles").get_to(fi.InputFiles);
    j.at("OutputFiles").get_to(fi.OutputFiles);
}

// conversion functions for Configuration
void to_json(json& j, const utils::Configuration& config) {
    j = json{{"ImageInfo", config.ImageInfo},
             {"FoldersInfo", config.foldersInfo}};
}
void from_json(const json& j, utils::Configuration& config) {
    j.at("ImageInfo").get_to(config.ImageInfo);
    j.at("FoldersInfo").get_to(config.foldersInfo);
}

size_t getTotalBytes(uint16_t width, uint16_t height, uint16_t channels) {
    if (width == 0 || height == 0 || channels == 0)
        return 0;
    return static_cast<size_t>(width) * height * channels;
}

} // Namespace utils
