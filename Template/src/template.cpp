
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>  
#include <opencv2/imgcodecs.hpp> 

#include "../include/utils.h"

namespace fs = std::filesystem;

int runProgram(const utils::Configuration &config) {

  // check dirs and create dirs if needed
  const auto inputDir = path::input_dir(config.foldersInfo);
  const auto outputDir = path::output_dir(config.foldersInfo);
  if (!std::filesystem::exists(inputDir)) {
      std::cout << "Error: Input directory not found at: " << inputDir;
    return 1;
  }
  if (!std::filesystem::exists(outputDir)) {
    std::filesystem::create_directory(outputDir);
    std::cout << "Directory created: " << outputDir;
  }

  // open binary file
  fs::path filePath = fs::path(inputDir) / config.ImageInfo.Name;
  std::ifstream file(filePath, std::ios::binary);
  if (!file) {
      std::cerr << "Error: cannot open file" << std::endl;
      return -1;
  }

  // read binary into vec
  size_t bufferSize = utils::getTotalBytes(config.ImageInfo.Width, config.ImageInfo.Height, config.ImageInfo.Channels);
  std::vector<uint8_t> buffer(bufferSize);
  file.read(reinterpret_cast<char*>(buffer.data()), bufferSize);
  file.close();

  cv::Mat image(config.ImageInfo.Height, config.ImageInfo.Width, CV_8UC3, buffer.data());
  cv::Mat bgrImage;
  cv::cvtColor(image, bgrImage, cv::COLOR_RGB2BGR);

  fs::path outputPath = fs::path(outputDir) / config.ImageInfo.Name;
  outputPath.replace_extension(".png");
  if (cv::imwrite(outputPath.string(), bgrImage)) {
      std::cout << "File saved" << std::endl;
  }
  else {
      std::cerr << "Errore during saving PNG file" << std::endl;
  }

  return 0;
}