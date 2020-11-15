///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#include "LoadCommandProcessor.h"

#include <fstream>
#include <iostream>

bool LoadCommandProcessor::CanProcess(const std::string &command) {
  return command == load_full_command || command == load_short_command;
}

bool LoadCommandProcessor::ProcessCommand(
    const std::vector<std::string> &command_with_args,
    std::unordered_map<std::string, cv::Mat> &images) {
  if (command_with_args.size() != 3) {
    std::cerr << "Not enough input arguments" << std::endl;
    return false;
  }

  auto &img_path = command_with_args[2];
  if (!std::ifstream(img_path).good()) {
    std::cerr << "Incorrect image path" << std::endl;
    return false;
  }

  auto &img_name = command_with_args[1];
  images[img_name] = cv::imread(img_path, cv::IMREAD_COLOR);

  return true;
}
