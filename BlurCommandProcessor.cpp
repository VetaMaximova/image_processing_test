///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#include "BlurCommandProcessor.h"

#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

bool BlurCommandProcessor::CanProcess(const std::string &command) {
  return command == blur_command;
}

bool BlurCommandProcessor::ProcessCommand(
    const std::vector<std::string> &command_with_args,
    std::unordered_map<std::string, cv::Mat> &images) {
  if (command_with_args.size() != 4) {
    std::cerr << "Not enough input arguments" << std::endl;
    return false;
  }

  auto &img_from_name = command_with_args[1];
  if (images.find(img_from_name) == images.end()) {
    std::cerr << "No such image" << std::endl;
    return false;
  }

  auto &img_to_name = command_with_args[2];
  auto &str_size = command_with_args[3];
  int size = 0;

  try {
    size = std::stoi(str_size);
  } catch (...) {
    std::cerr << "Incorrect size" << std::endl;
    return false;
  }

  try {
    cv::medianBlur(images[img_from_name], images[img_to_name], size);
  } catch (...) {
    std::cerr << "Error in blur" << std::endl;
    return false;
  }

  return true;
}
