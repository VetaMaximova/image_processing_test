///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#include "StoreCommandProcessor.h"

#include <fstream>
#include <iostream>

bool StoreCommandProcessor::CanProcess(const std::string &command) {
  return command == store_full_command || command == store_short_command;
}

bool StoreCommandProcessor::ProcessCommand(
    const std::vector<std::string> &command_with_args,
    std::unordered_map<std::string, cv::Mat> &images) {
  if (command_with_args.size() != 3) {
    std::cerr << "Not enough input arguments" << std::endl;
    return false;
  }

  auto &save_path = command_with_args[2];
  auto parent_path = save_path.substr(0, save_path.find_last_of("/\\"));
  if (!std::ifstream(parent_path).good()) {
    std::cerr << "Incorrect save path" << std::endl;
    return false;
  }

  auto &img_name = command_with_args[1];
  if (images.find(img_name) == images.end()) {
    std::cerr << "No such image" << std::endl;
    return false;
  }

  cv::imwrite(save_path, images[img_name]);

  return true;
}
