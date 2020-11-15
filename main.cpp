///
/// @file
/// @copyright Copyright (C) 2020, Bayerische Motoren Werke Aktiengesellschaft
/// (BMW AG)
///
#include "ImageProcessor.h"

#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

std::vector<std::string>
divide_command_with_args(const std::string &command_with_args) {
  std::istringstream iss(command_with_args);
  return {std::istream_iterator<std::string>(iss), {}};
}

int main(int argc, char **argv) {
  ImageProcessor image_processor;
  std::string command_with_args;

  std::cout << "ImageProcessing app started, print your commands" << std::endl;
  while (true) {
    std::getline(std::cin, command_with_args);
    auto command_with_args_splited =
        divide_command_with_args(command_with_args);

    if (!image_processor.IsCommandCorrect(command_with_args_splited[0])) {
      std::cerr << "Your command is not supported "
                << command_with_args_splited[0] << std::endl;
      continue;
    }

    if (image_processor.IsFinishCommand(command_with_args_splited[0])) {
      break;
    }

    bool process_result =
        image_processor.ProcessCommand(command_with_args_splited);
    if (!process_result) {
      std::cerr << "Arguments are incorrect" << std::endl;
      continue;
    }
  }
}
