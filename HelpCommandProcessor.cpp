///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#include "HelpCommandProcessor.h"

#include <iostream>

bool HelpCommandProcessor::CanProcess(const std::string &command) {
  return command == help_full_command || command == help_short_command;
}

bool HelpCommandProcessor::ProcessCommand(
    const std::vector<std::string> &command_with_args,
    std::unordered_map<std::string, cv::Mat> &images) {
  std::cout << "Available commands are: " << std::endl;
  std::cout << "Load image 'load', 'ld': should be provided with 2 args, "
               "image_name, image_path"
            << std::endl;
  std::cout << "Save image 'store', 's': : should be provided with 2 args, "
               "image_name, image_path"
            << std::endl;
  std::cout << "Blur image 'blur': should be provided with three args: "
               "from_image, to_image, size"
            << std::endl;
  std::cout << "Resize image 'resize': should be provided with four args: "
               "from_image, to_image, width, height"
            << std::endl;

  return true;
}
