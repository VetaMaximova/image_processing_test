///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#include "ResizeCommandProcessor.h"

#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

bool ResizeCommandProcessor::CanProcess(const std::string &command) {
  return command == resize_command;
}

bool ResizeCommandProcessor::ProcessCommand(
    const std::vector<std::string> &command_with_args,
    std::unordered_map<std::string, cv::Mat> &images) {
  if (command_with_args.size() != 5) {
    std::cerr << "Not enough input arguments" << std::endl;
    return false;
  }

  auto &img_from_name = command_with_args[1];
  if (images.find(img_from_name) == images.end()) {
    std::cerr << "No such image" << std::endl;
    return false;
  }

  auto &img_to_name = command_with_args[2];

  auto &str_width = command_with_args[3];
  auto &str_height = command_with_args[4];
  int width = 0, height = 0;

  try {
    width = std::stoi(str_width);
    height = std::stoi(str_height);
  } catch (...) {
    std::cerr << "Incorrect width/heoght" << std::endl;
    return false;
  }

  try {
    cv::resize(images[img_from_name], images[img_to_name],
               cv::Size(width, height));
  } catch (...) {
    std::cerr << "Can't resize image" << std::endl;
    return false;
  }

  return true;
}
